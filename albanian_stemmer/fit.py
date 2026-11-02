"""Fit the Albanian light stemmer and stopword list; write their JSON and Snowball.

Rule sources, scored the same way (:mod:`albanian_stemmer.metrics`) against a
corpus lexicon (:mod:`albanian_stemmer.lexicon`; default: the public-crawl
lexicon in ``data/lexicons``) and, given ``--book``, the grammar book:

* ``--rules surface`` (the default): the grammar's ending tables
  (``SURFACE_STEP1``/``SURFACE_STEP2``) for stemming running text with no
  lemmatizer before it, pruned against the objective under **Search** and
  also written as a Snowball program. These are the committed rules.
* ``--rules hand``: smaller tables for stemming *lemmas* (``HAND_STEP1``/
  ``HAND_STEP2``), pruned the same way. It strips the -oj conjugation whole,
  so denominal verbs reach their noun's stem (*kontrolloj*/*kontroll*).
* ``--rules learned``: nothing hand-written, as follows.

* **Candidate endings** — uniparser segments every corpus word into stem and
  affixes (``burra-ve``, ``rekomando-h-et``); the ending is what follows the
  stem, the shortest one across the word's readings (so a derived reading
  ``pun-ime-ve`` does not make ``-imeve`` an ending).
* **Candidate stem rewrites** — the stem variants each uniparser lexeme lists
  (``puno|punua|punu``, ``libër//libr``) differ at the end by alternations
  like ``o/ua``, ``er/r``, ``k/q``.
* **Search** — on half of the lemmas (the other half is held out): for
  ``learned``, a grid over (ending count, min stem, passes), then greedy
  additions and removals of endings and rewrites; for ``hand``/``surface``,
  greedy removal (and restoring) of the tables' endings, toggling rewrites and
  moving the minimum stem. Both maximize mean recall (corpus types, tokens,
  and book families) while precision stays above ``--min-precision-types``/
  ``--min-precision-tokens`` and the book's derivations stay apart
  (``--min-apart``): a *light* stemmer, with few false merges.
* **Book** (``--book``) — the grammar's paradigms and inflectional examples
  (``data/grammar/book_checks.json``, word lists reduced from the book by
  ``tools/extract_grammar_inflection.py`` and ``tools/book_checks.py``) add a
  third recall to maximize,
  their endings join the candidates, and their derivational examples must
  keep distinct stems, except denominal verbs, which join their noun's family.
* **Stopwords** — words Stanza tagged mostly as function words in the corpus
  (the lexicon's ``is_stopword``) for which uniparser also has a closed-class
  reading (preposition, conjunction, particle, pronoun, article, clitic, verbal
  particle, or a form of jam/kam). The uniparser check drops Stanza's
  mistakes (*cilësi* "quality" tagged as a determiner) and foreign words.

* **Exceptions** (``--exceptions``) — whole words looked up before any rule:
  the irregular verbs, whose forms share no stem (``tools/build_irregular_verbs.py``),
  and the forms of frequent nouns that the rules split off their paradigm
  (``tools/build_noun_conflicts.py``). They are attached to the fitted rules
  (not used in the search) and are part of the scores reported.

The committed rules are reproduced byte for byte by::

    uv run --extra fit python -m albanian_stemmer.fit \\
        --min-precision-types 0.80 --book data/grammar/book_checks.json \\
        --precede --fix-min-stem --participles --derivational \\
        --exceptions data/grammar/irregular_verbs.json data/grammar/noun_conflicts.json \\
        --max-exceptions 1000

On a new corpus, write to a run directory instead of over the committed rules::

    uv run --extra fit python -m albanian_stemmer.fit --lexicon runs/web/lexicon.tsv.gz \\
        --min-precision-types 0.80 --book data/grammar/book_checks.json \\
        --max-words 200000 --out runs/web
"""

from __future__ import annotations

import argparse
import collections
import itertools
import json
import logging
import re
import sys
from pathlib import Path
from typing import Any, cast

from albanian_stemmer.lexicon import LexWord, load_lexicon
from albanian_stemmer.metrics import WORD as _WORD
from albanian_stemmer.metrics import (
    Book,
    Corpus,
    fmt,
    fmt_book,
    top_words,
)
from albanian_stemmer.rules import (POSTGRES_DIR, SNOWBALL_PATH, SURFACE_RULES_PATH,
                                    AlbanianStemmer)
from albanian_stemmer.text import fold

logger = logging.getLogger("albanian_stemmer.fit")

# Adverbs are left out: too many content words (ligjërisht, cilësisht) are adverbs.
CLOSED_POS = frozenset({"PR", "CONJ", "PART", "PRO", "ART", "CLIT_PRO", "VB_PART"})
AUXILIARIES = frozenset({"jam", "kam"})

DATA = Path(__file__).resolve().parents[1] / "data"
LEXICON_PATH = DATA / "lexicons" / "crawl-sq-2026-11.tsv.gz"


# ─── Inputs ───────────────────────────────────────────────────────────────────

def uniparser_readings(words: list[str], chunk: int = 50_000,
                       ) -> dict[str, list[tuple[str, str, str]]]:
    """word → [(lemma, POS, glossed form like 'burra-ve')] from uniparser."""
    from uniparser_albanian import AlbanianAnalyzer

    a = AlbanianAnalyzer()
    a.glossing = True
    out = {}
    for i in range(0, len(words), chunk):
        part = words[i: i + chunk]
        for w, anas in zip(part, cast(list[list[Any]], a.analyze_words(part))):
            out[w] = [(x.lemma, (x.gramm or "").split(",")[0], x.wfGlossed or "")
                      for x in anas if x.lemma]
        if len(words) > chunk:
            logger.info("uniparser: %d / %d words", min(i + chunk, len(words)), len(words))
    return out


def endings_of(readings: dict[str, list[tuple[str, str, str]]],
               freq: dict[str, int]) -> list[str]:
    """Inflectional endings, most frequent (per token) first."""
    cnt: collections.Counter = collections.Counter()
    for w, rs in readings.items():
        ends = []
        for _, _, glossed in rs:
            if not glossed:
                continue
            parts = fold(glossed).split("-")
            k = max(range(len(parts)), key=lambda i: len(parts[i]))  # the stem
            ends.append("".join(parts[k + 1:]))
        if ends:
            e = min(ends, key=len)
            if e and _WORD.match(e):
                cnt[e] += freq[w]
    return [e for e, _ in cnt.most_common()]


def alternations(min_count: int = 20) -> list[tuple[str, str]]:
    """Stem-end alternations between a lexeme's listed stems: both directions of
    a change (o/ua), the deleting direction of an addition (lule/lul-)."""
    from importlib.resources import files

    def lcp(a: str, b: str) -> int:
        n = 0
        for x, y in zip(a, b):
            if x != y:
                break
            n += 1
        return n

    text = (files("uniparser_albanian.data_strict") / "lexemes.txt").read_text(encoding="utf-8")
    cnt: collections.Counter = collections.Counter()
    for block in text.split("-lexeme")[1:]:
        if re.search(r"^ gramm:.*\bnonst\b", block, re.M):
            continue
        m = re.search(r"^ stem: (.*)$", block, re.M)
        if not m:
            continue
        stems = {fold(re.sub(r"[.\[\]]", "", s)) for part in m.group(1).split("|")
                 for s in part.split("//")}
        stems = {s for s in stems if s and _WORD.match(s)}
        for a, b in itertools.combinations(sorted(stems), 2):
            k = lcp(a, b)
            x, y = a[k:], b[k:]
            if (x or y) and len(x) <= 3 and len(y) <= 3:
                cnt[tuple(sorted((x, y)))] += 1
    out = []
    for (x, y), n in cnt.most_common():
        if n >= min_count:
            # x is "" for a deletion (lule/lul-), which only makes sense one way.
            out += [(y, x)] if not x else [(x, y), (y, x)]
    return out


def stopwords_of(lexicon: list[LexWord],
                 readings: dict[str, list[tuple[str, str, str]]]) -> set[str]:
    out = set()
    for e in lexicon:
        if not e.is_stopword or not _WORD.match(e.word):
            continue
        if any(pos in CLOSED_POS or lemma in AUXILIARIES
               for lemma, pos, _ in readings.get(e.word, [])):
            out.add(fold(e.word))
    return out


# ─── Search ───────────────────────────────────────────────────────────────────

def learn(c: Corpus, book: Book | None, endings: list[str],
          rewrite_pool: list[tuple[str, str]], min_p_type: float, min_p_tok: float,
          min_apart: float) -> AlbanianStemmer:
    """Maximize mean recall (corpus types, tokens, and book families) subject
    to the precision floors and the book's derivations staying apart."""
    def objective(r: dict[str, float]) -> float:
        short = min(r["P_type"] - min_p_type, r["P_tok"] - min_p_tok,
                    r.get("apart_book", 1.0) - min_apart)
        recalls = [r["R_tok"], r["R_type"]] + ([r["R_book"]] if "R_book" in r else [])
        return sum(recalls) / len(recalls) if short >= 0 else short - 1

    def ev(sfx, m, p, rw):
        st = AlbanianStemmer((tuple(sfx),) * p, m, tuple(rw))
        r = c.score(st)
        if book is not None:
            r |= book.score(st)
        return objective(r), st

    best = (-9.0, None)
    for k in (20, 45, len(endings)):
        for m in (2, 3, 4):
            for p in (1, 2):
                o, st = ev(endings[:k], m, p, [])
                if o > best[0]:
                    best = (o, st)
    o, st = best
    assert st is not None
    sfx, m, p, rw = list(st.steps[0]), st.min_stem, len(st.steps), list(st.rewrites)
    logger.info("grid: %d endings, min stem %d, %d pass(es), objective %.4f", len(sfx), m, p, o)
    for rnd in range(6):
        improved = False
        moves: list[tuple[str, Any]] = ([("drop_sfx", s) for s in sfx] + [("add_sfx", s) for s in endings if s not in sfx]
                 + [("add_rw", xy) for xy in rewrite_pool
                    if xy not in rw and all(xy[0] != x for x, _ in rw)]
                 + [("drop_rw", xy) for xy in rw]
                 + [("m", m - 1), ("m", m + 1), ("p", p - 1), ("p", p + 1)])
        for kind, v in moves:
            s2, rw2, m2, p2 = list(sfx), list(rw), m, p
            if kind == "drop_sfx" and v in s2:
                s2.remove(v)
            elif kind == "add_sfx" and v not in s2:
                s2.append(v)
            elif kind == "add_rw" and all(v[0] != x for x, _ in rw2):
                rw2.append(v)
            elif kind == "drop_rw" and v in rw2:
                rw2.remove(v)
            elif kind == "m":
                m2 = v
            elif kind == "p":
                p2 = v
            else:
                continue
            if m2 < 2 or p2 < 1:
                continue
            o2, _ = ev(s2, m2, p2, rw2)
            if o2 > o + 1e-6:
                o, sfx, rw, m, p, improved = o2, s2, rw2, m2, p2, True
        logger.info("round %d: %d endings, %d rewrites, min stem %d, %d pass(es), objective %.4f",
                    rnd, len(sfx), len(rw), m, p, o)
        if not improved:
            break
    return AlbanianStemmer((tuple(sfx),) * p, m, tuple(rw))


# ─── Hand-written rules ───────────────────────────────────────────────────────
# The grammar's ending tables (tools/extract_grammar_inflection.py), written
# out as two ordered steps; --rules hand prunes them against the same
# objective as the learned rules. Step 1 strips the outer ending: a noun or
# adjective's article and case, a verb's person, tense and mood, with the -oj
# conjugation written out whole (its thematic o/ua is not safe to strip alone:
# radio, kilo). Step 2 strips the plural or stem suffix left in front of it.
_W = str.split
HAND_STEP1 = tuple(sorted(set(
    _W("i u it in ut un a ja je s se ne n t te et ve sh esh rit rin ri")  # nouns, adjectives
    + _W("j jme jne ni in nim nit nin te ja je ur re ne sha sh shim shit shin "
         "em esh et emi eni en esha eshe ej eshim eshit eshin "
         "fsha fsh fte fshim fshit fshin kam ke ka kemi keni kan kane u am at an va ve")  # verbs
    + _W("oj on ojme oni ojne ova ove oi uam uat uan oja oje onte onim onit onin uar "
         "ofsha ofsh ofte ofshim ofshit ofshin uakam uake uaka uakemi uakeni uakan "
         "ohem ohesh ohet ohemi oheni ohen ohesha oheshe ohej oheshim oheshit oheshin ohu ou"))))
HAND_STEP2 = tuple(_W("e a ra er enj inj nj j"))
HAND_REWRITES = (("e", ""),)

# ``--derivational``: a third step, fixed rather than fitted, stripping the
# action-noun suffix -im that Albanian makes from verbs (përdor → përdorim,
# kultivoj → kultivim), once step 1 has taken its article (përdorimi). The
# lexicons' lemmas count the noun and its verb apart, so the fit would drop
# it; a human-labelled sample of word families and retrieval both want them
# together. Only in R2, so short words keep their -im (sjellim, trim, klim).
DERIVATIONAL_STEP: tuple[tuple[str, str], ...] = (("im", "R2"),)
DERIVATIONAL_NOTE = "derivation: nouns of action from verbs (përdorim, kultivimi → përdor, kultiv)"
# ``--participles``: step-1 endings, fixed rather than fitted, for the -oj
# verbs' participle once declined (organizuara, punuarit) and their non-active
# aorist (u punua; Gheg punue). The fit's candidates leave them out, so step 1
# takes only -ra or -a and leaves organizu- apart from organiz-. Added after
# the search rather than offered to it: offered, the greedy search takes a
# different path and loses type precision. The human-labelled sample and
# retrieval both favour them.
PARTICIPLE_ENDINGS = tuple(_W("uara uarat uarave uare uaresh uari uarin uarit uarve ua ue uem"))
PARTICIPLE_NOTE = ("participle, declined (punuara, punuarit, punuarve), "
                   "and non-active aorist (u punua; Gheg punue)")
HAND_REWRITE_POOL = (("j", ""), ("ua", "o"), ("k", "q"), ("g", "gj"), ("odh", "edh"),
                     ("ill", "oll"), ("er", "r"), ("shem", "shm"), ("el", "l"))

# ``--rules surface``: the stemmer alone analyzes text, with no lemmatizer
# before it, so its tables also hold what the lemmatizer used to remove: the
# suffixed article and case endings of nouns (-ës, -së, -it, -ve, -ët). Grouped
# as the Snowball program's comments (AlbanianStemmer.to_snowball).
SURFACE_STEP1: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("nouns, masculine: definite and oblique (mali, malin, malit; mjeku, mjekun)",
     tuple(_W("i in it u un ut"))),
    ("after a stressed vowel (druri, drurin, drurit)", tuple(_W("ri rin rit"))),
    ("nouns, feminine: definite and oblique (molla, mollën, mollës; lulja; shtëpisë)",
     tuple(_W("a ja n en s es se je ne"))),
    ("neuter and plural definite (vitet, mollët, shtëpitë, mollat)", tuple(_W("t et te at"))),
    ("plural oblique and ablative (mollëve, maleve, fermerësh)",
     tuple(_W("ve eve ave sh esh ash"))),
    ("neuter plurals in -ra (plehra, plehrat, plehrave)", tuple(_W("ra rat rave rash"))),
    ("verbs, present (punoj, punon, punojmë, punoni, punojnë)",
     tuple(_W("j jme jne ni oj on ojme oni ojne ej ejme eni ejne ij ijme ijne im in"))),
    ("imperfect (punoja, punonte, punonim, punonin)",
     tuple(_W("ja je nte nim nit nin oja oje onte onim onit onin"))),
    ("aorist (punova, punove, punoi, punuam, punuat, punuan)",
     tuple(_W("ova ove oi uam uat uan am at an"))),
    ("participle (punuar, ujitur, mbjellë)", tuple(_W("uar ur ure re"))),
    ("non-active (mbillet, mbillen, punohet, punohej)",
     tuple(_W("em esh et emi eni en hem hesh het hemi heni hen ohem ohesh ohet ohemi oheni "
              "ohen esha eshe ej eshim eshit eshin hesha heshe hej heshim heshit heshin "
              "ohesha oheshe ohej oheshim oheshit oheshin ohu hu"))),
    ("optative (punofsha, punoftë)",
     tuple(_W("fsha fsh fte fshim fshit fshin ofsha ofsh ofte ofshim ofshit ofshin"))),
    ("admirative (punuakam, punuaka)",
     tuple(_W("kam ke ka kemi keni kan kane uakam uake uaka uakemi uakeni uakan uakane"))),
)
SURFACE_STEP2: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("plural and stem vowels (male, mollë; ullinj)", tuple(_W("e a enj inj nj"))),
)
SNOWBALL_HEADER = """\
Albanian stemmer, generated by albanian_stemmer.fit --rules surface
from albanian_stemmer/snowball/albanian.json. Do not edit; rebuild instead.

A light, inflectional stemmer for keyword search. Like Romanian, Albanian
suffixes its definite article and fuses it with the case ending (mollë, molla,
mollës, mollën, mollët, mollëve), so, as in the Romanian Snowball stemmer, the
article and case endings go first (step1, which also holds the verb endings:
punoj, punonte, punohet, punuar), then plural and stem vowels (step2), then the
stem's end is normalized (stem_end: sëmundj → sëmund, libër → libr). The
endings are the grammar's, pruned against the corpus: two words sharing a
lemma should share a stem, two that do not should not. Derived words mostly keep
their own stems (punëtor), except that an -oj verb meets the noun it is made
from (kontrolloj, kontroll), and a third step joins nouns of action in -im to
their verb (përdorimi, përdor). Stems can be shorter than any word (moll, semund).
Some endings also need a certain letter before them (as in the Finnish and
Turkish stemmers): -t only after a vowel (mollët, but rast keeps its t). An
exception table, looked up first, joins the forms of irregular verbs (vij,
erdhi, ardhur; jam, është, qenë) and the forms the rules split off a frequent
noun (problemi, duar).

Input must be lowercase; ë and ç are folded first, so text typed without them
stems the same."""


def prune(c: Corpus, book: Book | None, min_p_type: float, min_p_tok: float,
          min_apart: float,
          tables: tuple[tuple[str, ...], tuple[str, ...]] = (HAND_STEP1, HAND_STEP2),
          regions: bool = False, fix_min_stem: bool = False,
          precede: bool = False) -> AlbanianStemmer:
    """Greedy: drop (or restore) one hand-written ending, toggle one rewrite, or
    move the minimum stem by one, while the objective improves. With
    *regions*, also move a kept ending between no region, R1 and R2 (the
    Snowball regions it must lie in); with *precede*, between no condition and
    the letter-before classes V, C, KGH. Same objective as :func:`learn`."""
    moves = ("", *(("R1", "R2") if regions else ()), *(("V", "C", "KGH") if precede else ()))
    conds: list[dict[str, str]] = [{} for _ in tables]

    def make(steps: list[list[str]], m: int, rw: list[tuple[str, str]],
             cd: list[dict[str, str]]) -> AlbanianStemmer:
        return AlbanianStemmer(tuple(map(tuple, steps)), m, tuple(rw), conditions=tuple(
            tuple((e, r) for e, r in c.items() if e in step) for c, step in zip(cd, steps)))

    def ev(steps: list[list[str]], m: int, rw: list[tuple[str, str]],
           cd: list[dict[str, str]] | None = None) -> float:
        st = make(steps, m, rw, conds if cd is None else cd)
        r = c.score(st)
        if book is not None:
            r |= book.score(st)
        short = min(r["P_type"] - min_p_type, r["P_tok"] - min_p_tok,
                    r.get("apart_book", 1.0) - min_apart)
        recalls = [r["R_tok"], r["R_type"]] + ([r["R_book"]] if "R_book" in r else [])
        return sum(recalls) / len(recalls) if short >= 0 else short - 1

    full = [list(tables[0]), list(tables[1])]
    cur, m, rw = [list(x) for x in full], 3, list(HAND_REWRITES)
    o = ev(cur, m, rw)
    for rnd in range(8):
        improved = False
        for i, e in [(i, e) for i, step in enumerate(full) for e in step]:
            c2 = [list(x) for x in cur]
            if e in c2[i]:
                c2[i].remove(e)
            else:
                c2[i].append(e)
            if (o2 := ev(c2, m, rw)) > o + 1e-5:
                o, cur, improved = o2, c2, True
        for xy in list(HAND_REWRITE_POOL) + rw:
            r2 = [x for x in rw if x != xy] if xy in rw else rw + [xy]
            if (o2 := ev(cur, m, r2)) > o + 1e-5:
                o, rw, improved = o2, r2, True
        for m2 in () if fix_min_stem else (m - 1, m + 1):
            if m2 >= 2 and (o2 := ev(cur, m2, rw)) > o + 1e-5:
                o, m, improved = o2, m2, True
        if len(moves) > 1:
            for i, e in [(i, e) for i, step in enumerate(cur) for e in step]:
                for r in moves:
                    if r == conds[i].get(e, ""):
                        continue
                    cd = [dict(c) for c in conds]
                    if r:
                        cd[i][e] = r
                    else:
                        cd[i].pop(e, None)
                    if (o2 := ev(cur, m, rw, cd)) > o + 1e-5:
                        o, conds, improved = o2, cd, True
        logger.info("round %d: %d + %d endings, %d rewrites, min stem %d, %d conditioned, "
                    "objective %.4f", rnd, len(cur[0]), len(cur[1]), len(rw), m,
                    sum(len(c) for c in conds), o)
        if not improved:
            break
    return make(cur, m, rw, conds)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--lexicon", default=str(LEXICON_PATH),
                    help="corpus lexicon TSV, see albanian_stemmer.lexicon (.gz ok; "
                         "default: %(default)s)")
    ap.add_argument("--max-words", type=int,
                    help="fit on the N most frequent lexicon words only (the search "
                         "re-stems every word per candidate, so a web-scale lexicon is slow)")
    ap.add_argument("--min-precision-types", type=float, default=0.90,
                    help="precision floor per word type, on the training half")
    ap.add_argument("--min-precision-tokens", type=float, default=0.90,
                    help="precision floor per token, on the training half")
    ap.add_argument("--gold", choices=("lexicon", "uniparser"), default="lexicon",
                    help="whose lemmas link words: the lexicon's (Stanza ∪ uniparser), or "
                         "uniparser's where it knows the word")
    ap.add_argument("--book", help="the grammar book's checks (data/grammar/book_checks.json): adds its endings to "
                    "the candidates and its word families to the objective")
    ap.add_argument("--min-apart", type=float, default=0.90,
                    help="with --book: share of its derivations that must keep distinct stems")
    ap.add_argument("--rules", choices=("hand", "learned", "surface"), default="surface",
                    help="hand: prune the lemma tables (strips -oj verbs whole, so "
                         "denominal verbs meet their noun); learned: search uniparser's "
                         "segmentation endings; surface: prune the larger tables for "
                         "stemming words without a lemmatizer, written as a Snowball program")
    ap.add_argument("--exceptions", nargs="+", default=[],
                    help="exception tables (tools/build_irregular_verbs.py, "
                         "tools/build_noun_conflicts.py) to attach to the fitted rules; "
                         "an earlier table wins a word both list")
    ap.add_argument("--regions", action="store_true",
                    help="surface/hand: also fit, per ending, the Snowball region (none, R1, "
                         "R2) it must lie in, so a word whose own letters look like an "
                         "ending (problem: -em) keeps them")
    ap.add_argument("--max-exceptions", type=int,
                    help="keep at most this many exceptions: whole words (all of a verb's "
                         "or noun's entries), most corpus tokens per entry first "
                         "(a Snowball-sized list; the rest add little)")
    ap.add_argument("--precede", action="store_true",
                    help="surface/hand: also fit, per ending, a condition on the letter "
                         "before it (a vowel, a non-vowel, or k/g/h): mollë-t but not rast")
    ap.add_argument("--participles", action="store_true",
                    help="add the declined participle endings (-uara, -uarit, -ua) to step 1 "
                         "after the search, fixed")
    ap.add_argument("--derivational", action="store_true",
                    help="add a fixed third step stripping the noun suffix -im in R2 "
                         "(përdorimi, përdor), after the fitted ones")
    ap.add_argument("--fix-min-stem", action="store_true",
                    help="surface/hand: keep the minimum stem at 3 instead of fitting it")
    ap.add_argument("--out", help="run directory: writes albanian.json, albanian.sbl "
                    "(surface), the Postgres extension's C (with --snowball) and report.json there")
    ap.add_argument("--json", help=f"rules to write (surface default: {SURFACE_RULES_PATH})")
    ap.add_argument("--postgres", help="with --snowball: also write the Postgres extension's "
                    f"generated C here (surface default: {POSTGRES_DIR})")
    ap.add_argument("--sbl", help=f"Snowball source to write (surface default: {SNOWBALL_PATH})")
    ap.add_argument("--report", help="write the scores (train, held-out, all, book) as JSON")
    ap.add_argument("--snowball", help="the Snowball compiler: also compile --sbl to Python "
                    "next to it (https://github.com/snowballstem/snowball)")
    args = ap.parse_args(argv)
    surface = args.rules == "surface"
    if args.out:
        out = Path(args.out)
        out.mkdir(parents=True, exist_ok=True)
        args.json = args.json or str(out / "albanian.json")
        args.sbl = args.sbl or (str(out / "albanian.sbl") if surface else None)
        args.postgres = args.postgres or (str(out / "postgres") if surface else None)
        args.report = args.report or str(out / "report.json")
    if not surface and not args.json:
        ap.error(f"--rules {args.rules} needs --json or --out "
                 "(the default path holds the surface rules)")
    # The committed Snowball program goes with the committed rules only: an
    # explicit --json elsewhere does not overwrite it.
    if not args.json:
        args.json = str(SURFACE_RULES_PATH)
        args.sbl = args.sbl or (str(SNOWBALL_PATH) if surface else None)
    if args.sbl == str(SNOWBALL_PATH) and POSTGRES_DIR.is_dir():
        args.postgres = args.postgres or str(POSTGRES_DIR)  # the committed rules: the repo's
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")

    lexicon = load_lexicon(args.lexicon)
    logger.info("%d lexicon words", len(lexicon))
    lexicon = top_words(lexicon, args.max_words)
    if args.max_words:
        logger.info("fitting on the %d most frequent", len(lexicon))
    if not any(e.function_occurrences for e in lexicon):
        logger.warning("the lexicon has no function-word tags (built without Stanza?): "
                       "no stopwords, and function words count as content words")
    alpha = [e for e in lexicon if _WORD.match(e.word)]
    readings = uniparser_readings([e.word for e in alpha])
    freq = {e.word: e.occurrences for e in alpha}
    content = {e.word for e in alpha if not e.is_stopword}
    endings = endings_of({w: r for w, r in readings.items() if w in content}, freq)
    rewrite_pool = alternations()
    book_train = book_test = None
    if args.book:
        book_train, book_test = Book(args.book, 0), Book(args.book, 1)
        new = [e for e in dict.fromkeys(book_train.endings) if e not in endings]
        logger.info("book: %d + %d family pairs, %d + %d derivation pairs, %d new endings %s",
                    len(book_train.pairs), len(book_test.pairs), len(book_train.apart),
                    len(book_test.apart), len(new), new)
        endings += new
    stop = stopwords_of(lexicon, readings)
    spelling_freq: collections.Counter = collections.Counter()
    for e in lexicon:
        if fold(e.word) in stop:
            spelling_freq[e.word.lower()] += e.occurrences
    logger.info("%d candidate endings, %d candidate rewrites, %d stopwords",
                len(endings), len(rewrite_pool), len(stop))

    gold = None
    if args.gold == "uniparser":
        gold = {w: sorted({lemma for lemma, _, _ in rs}) for w, rs in readings.items() if rs}
    train, test, full = (Corpus(lexicon, 0, gold), Corpus(lexicon, 1, gold),
                         Corpus(lexicon, None, gold))
    if args.rules in ("hand", "surface"):
        tables = (HAND_STEP1, HAND_STEP2) if not surface else tuple(
            tuple(sorted({e for _, ends in groups for e in ends}))
            for groups in (SURFACE_STEP1, SURFACE_STEP2))
        st = prune(train, book_train, args.min_precision_types, args.min_precision_tokens,
                   args.min_apart, tables, regions=args.regions,
                   fix_min_stem=args.fix_min_stem, precede=args.precede)  # type: ignore[arg-type]
    else:
        st = learn(train, book_train, endings, rewrite_pool, args.min_precision_types,
                   args.min_precision_tokens, args.min_apart)
    if args.participles:
        step1 = tuple(sorted(set(st.steps[0]) | set(PARTICIPLE_ENDINGS), key=lambda e: (-len(e), e)))
        st = AlbanianStemmer((step1, *st.steps[1:]), st.min_stem, st.rewrites, st.stopwords,
                             st.conditions)
    if args.derivational:
        conds = list(st.conditions) + [()] * (len(st.steps) - len(st.conditions))
        st = AlbanianStemmer(st.steps + (tuple(e for e, _ in DERIVATIONAL_STEP),), st.min_stem,
                             st.rewrites, st.stopwords,
                             (*conds, tuple((e, c) for e, c in DERIVATIONAL_STEP if c)))
    exceptions: dict[str, str] = {}
    tokens: dict[str, int] = {}
    groups: list[list[str]] = []
    for path in args.exceptions:
        d = json.loads(Path(path).read_text())
        table = d.get("exceptions", d)
        groups += [[f for f in g if f not in exceptions] for g in d.get("groups", {}).values()]
        grouped = {f for g in d.get("groups", {}).values() for f in g}
        groups += [[f] for f in sorted(table) if f not in grouped and f not in exceptions]
        exceptions = {**table, **exceptions}
        tokens = {**d.get("tokens", {}), **tokens}
        logger.info("%d exceptions from %s", len(table), path)
    if args.max_exceptions is not None and len(exceptions) > args.max_exceptions:
        exceptions = _cut_exceptions(exceptions, tokens, groups, args.max_exceptions)
        logger.info("kept %d exceptions, whole words by tokens per entry", len(exceptions))
    st = AlbanianStemmer(st.steps, st.min_stem, st.rewrites, frozenset(stop), st.conditions,
                         tuple(exceptions.items()))
    ident = AlbanianStemmer((), 99)
    report: dict[str, Any] = {"lexicon": args.lexicon, "words": len(lexicon),
                              "rules": args.rules, "fingerprint": st.fingerprint(),
                              "args": vars(args)}
    for name, c in (("train", train), ("held-out", test), ("all", full)):
        report[name] = c.score(st)
        logger.info("%-8s %s", name, fmt(report[name]))
    if book_train is not None and book_test is not None:
        report["book-train"], report["book-held-out"] = (book_train.score(st),
                                                         book_test.score(st))
        logger.info("book train    %s", fmt_book(report["book-train"]))
        logger.info("book held-out %s", fmt_book(report["book-held-out"]))
    report["no-stemming-all"] = full.score(ident)
    logger.info("no stemming (folding only), all: %s", fmt(report["no-stemming-all"]))

    Path(args.json).write_text(json.dumps(st.to_json(), ensure_ascii=False, indent=1) + "\n")
    logger.info("wrote %s", args.json)
    if args.sbl:
        Path(args.sbl).with_name("stop.txt").write_text(stop_list(st, spelling_freq),
                                                         encoding="utf-8")
        write_snowball(st, Path(args.sbl), args.snowball,
                       Path(args.postgres) if args.postgres else None)
    if args.report:
        Path(args.report).write_text(json.dumps(report, indent=1, default=float) + "\n")
        logger.info("wrote %s", args.report)
    return 0


def _cut_exceptions(exceptions: dict[str, str], tokens: dict[str, int],
                    groups: list[list[str]], n: int) -> dict[str, str]:
    """At most *n* exceptions, keeping each word's entries together: a verb
    with only some of its forms listed would map them to a stem the rest no
    longer reach (shitur to ``shes``, but shes to ``she``). Words go in by
    corpus tokens per entry, while they fit."""
    groups = [g for g in groups if g]
    groups.sort(key=lambda g: (-sum(tokens.get(f, 0) for f in g) / len(g), g))
    keep: dict[str, str] = {}
    for g in groups:
        if len(keep) + len(g) <= n:
            keep |= {f: exceptions[f] for f in g}
    return keep


def snowball_notes(st: AlbanianStemmer) -> dict[str, str]:
    """The comments the Snowball program groups *st*'s endings under."""
    notes: dict[str, str] = {}
    for comment, ends in (*SURFACE_STEP1, *SURFACE_STEP2):  # first group listing it wins
        for e in ends:
            notes.setdefault(e, comment)
    for e in PARTICIPLE_ENDINGS:
        notes.setdefault(e, PARTICIPLE_NOTE)
    if len(st.steps) > 2:  # --derivational: per step, "step3:im"
        for e, _ in DERIVATIONAL_STEP:
            notes[f"step{len(st.steps)}:{e}"] = DERIVATIONAL_NOTE
    return notes


STOP_LIST_HEADER = """\
 | An Albanian stop word list. Comments begin with vertical bar. Each stop
 | word is at the start of a line.

 | Function words (articles and particles, pronouns, prepositions,
 | conjunctions, and the auxiliaries jam "be" and kam "have" in their
 | commonest forms) chosen from lemma-tagged lexicons of Albanian text: words
 | Stanza tagged mostly as function words that uniparser-albanian also reads
 | as closed-class words.

 | Much Albanian text is written without ë and ç, so a word that has them is
 | listed in both spellings (është, eshte). The stemmer folds them, so both
 | spellings get the same stem.
"""


def stop_list(st: AlbanianStemmer, spelling_freq: collections.Counter) -> str:
    """*st*'s stopwords as a Snowball ``stop.txt``: each in its commonest
    spelling in the lexicon and, if that has ë or ç, also without them."""
    best: dict[str, str] = {}
    for w, n in sorted(spelling_freq.items(), key=lambda x: (-x[1], x[0])):
        best.setdefault(fold(w), w)
    words = {best.get(f, f) for f in st.stopwords} | set(st.stopwords)
    return STOP_LIST_HEADER + "\n" + "".join(
        w + "\n" for w in sorted(words, key=lambda w: (fold(w), w)))


def stopwords_header(st: AlbanianStemmer) -> str:
    """*st*'s stopwords as the sorted C array the Postgres extension searches."""
    words = sorted(st.stopwords, key=lambda w: w.encode())  # strcmp order
    return ("/* Generated by albanian_stemmer.fit from albanian.json. Do not edit; rebuild. */\n"
            "/* The rules' stopwords, folded (ë→e, ç→c), in strcmp order for bsearch. */\n"
            "static const char *const albanian_stopwords[] = {\n"
            + "".join(f'\t"{w}",\n' for w in words) + "};\n")


def write_snowball(st: AlbanianStemmer, sbl: Path, compiler: str | None,
                   postgres: Path | None = None) -> None:
    """Write *st* as Snowball source and, given the compiler, as the Python
    module it compiles to (``albanian_stemmer.py`` beside it) and, given
    *postgres*, as the C the Postgres extension builds from there
    (``stem_UTF_8_albanian.c``/``.h`` and ``albanian_stopwords.h``)."""
    import subprocess

    sbl.write_text(st.to_snowball(SNOWBALL_HEADER, snowball_notes(st)))
    logger.info("wrote %s", sbl)
    if not compiler:
        return
    out = sbl.with_name("albanian_stemmer")
    subprocess.run([compiler, str(sbl), "-python", "-eprefix", "_",
                    "-n", "AlbanianSnowballStemmer", "-o", str(out)], check=True)
    py = out.with_suffix(".py")
    # The compiler imports its runtime relatively; use the snowballstemmer package's.
    py.write_text(py.read_text().replace("from .basestemmer ", "from snowballstemmer.basestemmer ")
                  .replace("from .among ", "from snowballstemmer.among "))
    logger.info("wrote %s", py)
    if postgres is None:
        return
    postgres.mkdir(parents=True, exist_ok=True)
    # C for UTF-8 text, including the runtime as runtime/snowball_runtime.h.
    subprocess.run([compiler, str(sbl), "-utf8", "-eprefix", "albanian_UTF_8_", "-r", "runtime",
                    "-o", str(postgres / "stem_UTF_8_albanian")], check=True)
    (postgres / "albanian_stopwords.h").write_text(stopwords_header(st))
    logger.info("wrote the Postgres extension's C in %s", postgres)


if __name__ == "__main__":
    sys.exit(main())
