"""Build the frequent-noun conflict table (more ``exceptions`` in the rules file).

A light suffix stripper splits some frequent nouns: *problem*, *problemin*
(``problem``) but *problemi* (``probl``); *pjesa*, *pjesës* (``pjes``) but
*pjesë* (``pje``); *dorë*, *dora* (``dor``) but *duar*. Like the Lithuanian
Snowball stemmer's ``fix_conflicts``, this maps the forms that split off to
the stem the rest of the paradigm gets::

    uv run --extra fit python tools/build_noun_conflicts.py \\
        --out data/grammar/noun_conflicts.json \\
        data/lexicons/web-sq-2026-11.tsv.gz

Then pass it to the fit after the irregular verbs:
``--exceptions data/grammar/irregular_verbs.json data/grammar/noun_conflicts.json``.

* **Forms**: lexicon words whose standard (most frequent) spelling uniparser
  reads only as a noun, all readings of one lemma. Stopwords and the verb
  table's forms are left out.
* **Paradigms**: lemmas with at least ``--min-lemma`` tokens; a form needs
  ``--min-form`` tokens.
* **Stem**: of the stems the rules (with the verb table, ``--verbs``) give the paradigm's
  forms, the one most of its forms get, then the one with the most of its
  tokens net of other words' (*pjesa*'s ``pjes``, not *pjesë*'s ``pje``;
  *bashkëpunimi*'s ``bashkepun``, which the verb has too, not the bare
  *bashkëpunim*'s ``bashkepu``). ``--target-by tokens`` takes the latter
  alone. A lemma is skipped when other words still have more tokens on that
  stem than the paradigm does.
  Only forms the rules stem differently go in the table, so rebuild it
  whenever the endings change.
"""

from __future__ import annotations

import argparse
import collections
import json
import logging
import sys
from pathlib import Path

from albanian_stemmer.lexicon import load_lexicon
from albanian_stemmer.rules import SURFACE_RULES_PATH, AlbanianStemmer
from albanian_stemmer.text import fold

logger = logging.getLogger("build_noun_conflicts")


def build(lexicons: list[str], rules: AlbanianStemmer, verb_forms: dict[str, str],
          min_lemma: int, min_form: int, pos: str = "NOUN", target_by: str = "forms") -> dict:
    from uniparser_albanian import AlbanianAnalyzer

    st = AlbanianStemmer(rules.steps, rules.min_stem, rules.rewrites, rules.stopwords,
                         rules.conditions)  # without any exception table

    def stem(f: str) -> str:
        return verb_forms.get(f) or st.stem(f)

    freq: collections.Counter = collections.Counter()
    spellings: dict[str, set[str]] = collections.defaultdict(set)
    spell_freq: collections.Counter = collections.Counter()
    for p in lexicons:
        for e in load_lexicon(p):
            f = fold(e.word)
            freq[f] += e.occurrences
            spellings[f].add(e.word)
            spell_freq[e.word] += e.occurrences
    standard = {f: max(sorted(ws), key=lambda w: spell_freq[w]) for f, ws in spellings.items()
                if f not in st.stopwords and f not in verb_forms and freq[f] >= min_form}
    words = sorted(standard.values())
    an = AlbanianAnalyzer()
    noun_of: dict[str, str] = {}
    for i in range(0, len(words), 50_000):
        part = words[i: i + 50_000]
        for w, anas in zip(part, an.analyze_words(part)):
            rs = [(fold(x.lemma), (x.gramm or "").split(",")[0]) for x in anas if x.lemma]
            if rs and all(g == pos for _, g in rs) and len({lem for lem, _ in rs}) == 1:
                noun_of[fold(w)] = rs[0][0]

    forms: dict[str, list[str]] = collections.defaultdict(list)
    for f, lem in noun_of.items():
        forms[lem].append(f)
    forms = {lem: fs for lem, fs in forms.items() if sum(freq[f] for f in fs) >= min_lemma}
    family = {f for fs in forms.values() for f in fs}
    outside: collections.Counter = collections.Counter()
    for f in spellings:
        if f not in family:
            outside[stem(f)] += freq[f]

    table: dict[str, str] = {}
    paradigms, skipped = {}, {}
    for lem, fs in sorted(forms.items()):
        by_stem: collections.Counter = collections.Counter()
        for f in fs:
            by_stem[stem(f)] += freq[f]
        n_forms = collections.Counter(stem(f) for f in fs)
        # The paradigm's stem with the most of its tokens, net of other words';
        # with target_by="forms", the one most of its forms already have.
        target = max(sorted(by_stem), key=lambda t: (n_forms[t], by_stem[t] - outside[t])
                     if target_by == "forms" else by_stem[t] - outside[t])
        tokens = by_stem[target]
        moved = sorted((f for f in fs if stem(f) != target), key=lambda f: -freq[f])
        if not moved:
            continue
        if outside[target] > tokens:
            skipped[lem] = {"stem": target, "paradigm_tokens": tokens,
                            "other_tokens": outside[target]}
            continue
        table |= {f: target for f in moved}
        paradigms[lem] = {"stem": target, "moved": {f: stem(f) for f in moved}}
    logger.info("%d forms of %d words in the table (%d words with %d+ tokens; %d skipped: "
                "their stem is mostly other words')", len(table), len(paradigms), len(forms),
                min_lemma, len(skipped))
    return {"exceptions": dict(sorted(table.items())),
            # corpus tokens per entry: fit --max-exceptions keeps the most frequent
            "tokens": {f: freq[f] for f in sorted(table)},
            # each noun's entries: fit --max-exceptions keeps or drops a noun whole
            "groups": {lem: sorted(p["moved"]) for lem, p in sorted(paradigms.items())},
            "paradigms": paradigms,
            "skipped": skipped,
            "min_lemma_tokens": min_lemma, "min_form_tokens": min_form,
            "lexicons": [Path(p).name for p in lexicons]}


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("lexicons", nargs="+", help="corpus lexicons the forms are taken from")
    ap.add_argument("--out", required=True, help="table to write (JSON)")
    ap.add_argument("--rules", default=str(SURFACE_RULES_PATH),
                    help="rules whose stems the table maps to (their own exception "
                         "table is ignored) "
                         "(default: %(default)s)")
    ap.add_argument("--verbs", default="data/grammar/irregular_verbs.json",
                    help="irregular-verb table, applied before this one (default: %(default)s)")
    ap.add_argument("--pos", default="NOUN",
                    help="uniparser part of speech of the words (default: %(default)s; "
                         "A for adjectives)")
    ap.add_argument("--target-by", choices=("forms", "tokens"), default="forms",
                    help="the stem a paradigm's forms move to: the one most of its forms "
                         "get, then most tokens net of other words' (default), or by "
                         "tokens alone")
    ap.add_argument("--min-lemma", type=int, default=200,
                    help="tokens a noun needs across its forms (default: %(default)s)")
    ap.add_argument("--min-form", type=int, default=5,
                    help="tokens a form needs (default: %(default)s)")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")
    rules = AlbanianStemmer.from_json(json.loads(Path(args.rules).read_text()))
    verbs = json.loads(Path(args.verbs).read_text())["exceptions"]
    out = build(args.lexicons, rules, verbs, args.min_lemma, args.min_form, args.pos,
                args.target_by)
    Path(args.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n")
    logger.info("wrote %s", args.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
