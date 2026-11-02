"""How well a stemmer conflates a corpus: precision and recall against lemmas.

Two corpus words are *linked* when they share a lemma in the lexicon
(:mod:`albanian_stemmer.lexicon`). Recall is the share of linked pairs a
stemmer gives one stem; precision the share of same-stem pairs that are
linked; both per word type and per token (a pair weighs f1·f2). Stopwords are
left out. A denominal verb counts as its noun's lemma (*kontrolloj*/*kontroll*,
*punoj*/*punë*, see :func:`denominal_merges`): for keyword search they are one
term.

The grammar book (:class:`Book`) gives a second, hand-checked gold: the forms
of one paradigm must share a stem, and its derivational examples must not.

Both split by lemma into halves (``half=0`` to fit on, ``half=1`` held out),
so held-out words are unseen lexemes.
"""

from __future__ import annotations

import collections
import itertools
import json
import re
import zlib
from pathlib import Path
from typing import Protocol

import numpy as np

from albanian_stemmer.lexicon import LexWord
from albanian_stemmer.text import fold

WORD = re.compile(r"^[a-zëç]+$")


class Stemmer(Protocol):
    def stem(self, word: str) -> str: ...


class PrefixStemmer:
    """Baseline: the first *n* letters of the folded word."""

    def __init__(self, n: int):
        self.n = n

    def stem(self, word: str) -> str:
        return fold(word)[: self.n]


def denominal_merges(lemmas: set[str]) -> dict[str, str]:
    """Folded verb lemma → the folded lemma it is made from, among *lemmas*.

    An -oj verb joins the noun or adjective its stem names (*kontrolloj* →
    *kontroll*, *punoj* → *punë*, *formoj* → *formë*), an -ohem verb its -oj
    verb first (*shtohem* → *shtoj*). Spelling decides, not etymology, so a
    few unrelated pairs join too (*tregoj* "show" and *treg* "market").
    """
    out: dict[str, str] = {}
    for v in lemmas:
        for end, cands in (("ohem", ("oj", "", "e", "a")), ("oj", ("", "e", "a"))):
            if v.endswith(end) and len(v) - len(end) >= 3:
                b = v[: -len(end)]
                out.update({v: b + c for c in reversed(cands) if b + c in lemmas})
                break
    for v in list(out):  # resolve chains: shtohem → shtoj → shtë
        seen = {v}
        while out[v] in out and out[out[v]] not in seen:
            seen.add(out[v])
            out[v] = out[out[v]]
    return out


class Corpus:
    """Folded non-stopword corpus words and the pairs of them sharing a lemma."""

    def __init__(self, lexicon: list[LexWord], half: int | None = None,
                 lemmas: dict[str, list[str]] | None = None):
        """*lemmas* overrides the lexicon's lemmas per word (e.g. uniparser's)."""
        words: dict[str, list] = {}
        merge = denominal_merges({fold(x) for e in lexicon for x in e.lemmas})
        for e in lexicon:
            if e.is_stopword or not WORD.match(e.word):
                continue
            fw = fold(e.word)
            w = words.setdefault(fw, [set(), 0])
            w[0] |= {merge.get(x, x) for x in (fold(y) for y in
                                               (lemmas or {}).get(e.word) or e.lemmas)} or {fw}
            w[1] += e.occurrences
        if half is not None:  # split by lemma, so held-out words are unseen lexemes
            words = {w: v for w, v in words.items()
                     if zlib.crc32(min(v[0]).encode()) % 2 == half}
        self.words = sorted(words)
        self.freq = np.array([words[w][1] for w in self.words], dtype=np.float64)
        by_lemma = collections.defaultdict(list)
        for i, w in enumerate(self.words):
            for lemma in words[w][0]:
                by_lemma[lemma].append(i)
        pairs = {p for m in by_lemma.values() for p in itertools.combinations(m, 2)}
        p = np.array(sorted(pairs), dtype=np.int64).reshape(-1, 2)
        self.pi, self.pj = p[:, 0], p[:, 1]

    def score(self, st: Stemmer) -> dict[str, float]:
        codes: dict[str, int] = {}
        sid = np.array([codes.setdefault(st.stem(w), len(codes)) for w in self.words])
        same = sid[self.pi] == sid[self.pj]
        out: dict[str, float] = {"stems": len(codes)}
        for name, f in (("type", np.ones_like(self.freq)), ("tok", self.freq)):
            pw = f[self.pi] * f[self.pj]
            hit = pw[same].sum()
            gsum, gsq = np.bincount(sid, weights=f), np.bincount(sid, weights=f * f)
            same_stem = ((gsum ** 2 - gsq) / 2).sum()
            out[f"P_{name}"] = hit / same_stem if same_stem else 1.0
            out[f"R_{name}"] = hit / pw.sum() if len(pw) else float("nan")  # no linked pairs
        return out


def fmt(r: dict[str, float]) -> str:
    return (f"types P {r['P_type']:.3f} R {r['R_type']:.3f} | "
            f"tokens P {r['P_tok']:.3f} R {r['R_tok']:.3f} | {int(r['stems'])} stems")


# Articles, particles and auxiliaries the book prints with a form ("i lis-it",
# "do të punoj", "kam punuar"); the inflected word is what is left.
_BOOK_PARTICLES = frozenset(
    "i e të së u do po duke pa me për mos nuk s' a le ta t'i ia kam ke ka kemi keni kanë "
    "jam je është jemi jeni janë kisha isha qe paskam qenkam".split())
_INFLECTIONAL = frozenset({"case_ending", "plural_stem_suffix", "verb_ending",
                           "adjective_ending", "article_or_clitic"})


def book_word(form: str) -> str | None:
    """The folded inflected word of a form as the book prints it, or None."""
    form = re.sub(r"\(.*?\)|[0-9¹²³*,;.!?]", " ", form)
    toks = [t for t in form.split() if t.strip("-")]
    toks = [t for t in toks if t.lower() not in _BOOK_PARTICLES] or toks
    if not toks:
        return None
    w = fold(re.sub(r"[-'’]", "", toks[-1]))
    return w if re.fullmatch(r"[a-z]{2,}", w) else None


def book_checks(extraction: dict) -> dict:
    """The checks a grammar book's extraction (tools/extract_grammar_inflection.py)
    gives the fit, as plain word lists: ``families`` (the forms of one paradigm,
    and the examples of an inflectional affix or alternation, must share a
    stem), ``apart`` (the examples of a derivational suffix must not; the
    stemmer is light) and the inflectional ``endings``."""
    fams: list[set[str]] = []
    for p in extraction["paradigms"]:
        fam = {w for f in p["forms"] if (w := book_word(f["form"]))}
        if (lw := book_word(p["lemma"])):
            fam.add(lw)
        fams.append(fam)
    for a in extraction["alternations"]:
        fams += [{w for x in (ex["base"], ex["form"]) if (w := book_word(x))}
                 for ex in a["examples"]]
    apart: list[tuple[str, str]] = []
    endings: list[str] = []
    for a in extraction["affixes"]:
        if a["kind"] in _INFLECTIONAL:
            e = fold(a["affix"].split("(")[0].strip().strip("-"))
            if re.fullmatch(r"[a-z]{1,6}", e):
                endings.append(e)
        for ex in a["examples"]:
            b, f = book_word(ex["base"]), book_word(ex["form"])
            if not b or not f or b == f:
                continue
            if a["kind"] in _INFLECTIONAL:
                fams.append({b, f})
            elif a["kind"] == "derivational_suffix":
                if denominal_merges({b, f}):
                    fams.append({b, f})
                else:
                    apart.append((b, f))
    return {"endings": endings,
            "families": sorted({tuple(sorted(f)) for f in fams if len(f) > 1}),
            "apart": sorted(set(apart))}


class Book:
    """The grammar book's checks (``data/grammar/book_checks.json``, see
    :func:`book_checks`): word families that must share a stem, derivation
    pairs that must not, and the book's inflectional endings. A full
    extraction (``inflection.json``) is read too."""

    def __init__(self, path: str | Path, half: int | None = None):
        d = json.loads(Path(path).read_text(encoding="utf-8"))
        if "families" not in d:
            d = book_checks(d)
        self.endings: list[str] = list(d["endings"])
        keep = (lambda key: True) if half is None else (
            lambda key: zlib.crc32(key.encode()) % 2 == half)
        self.pairs = sorted({(a, b) for fam in d["families"] if keep(min(fam))
                             for a, b in itertools.combinations(sorted(fam), 2)})
        self.apart = sorted({(a, b) for a, b in d["apart"] if keep(min(a, b))})

    def score(self, st: Stemmer) -> dict[str, float]:
        return {"R_book": sum(st.stem(a) == st.stem(b) for a, b in self.pairs) / len(self.pairs),
                "apart_book": (sum(st.stem(a) != st.stem(b) for a, b in self.apart)
                               / len(self.apart)) if self.apart else 1.0}


def fmt_book(r: dict[str, float]) -> str:
    return f"book families merged {r['R_book']:.3f}, derivations kept apart {r['apart_book']:.3f}"


def top_words(lexicon: list[LexWord], n: int | None) -> list[LexWord]:
    """The *n* most frequent words (all of them when *n* is None)."""
    if n is None or n >= len(lexicon):
        return lexicon
    return sorted(lexicon, key=lambda e: -e.occurrences)[:n]
