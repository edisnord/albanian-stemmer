"""Build the irregular-noun exception table from fjalorthi.com's dictionary entries.

A noun whose plural the dictionary writes in full (*dorë* … sh. *dúar(t)*,
*grua* … sh. *grá(të)*) changes its stem in the plural; one with a suffix plural
(*mal* … sh. *-e(t)*) does not. The plurals are in data/grammar/fjalorthi.json
(see tools/fjalorthi.py)::

    uv run --extra fit python tools/build_irregular_nouns.py \\
        --rules runs/verbs/albanian.json --out data/grammar/irregular_nouns.json

``python -m albanian_stemmer.build --tables`` runs it on the committed rules.

* **Nouns**: a plural of 3 letters or more that starts like the singular (so a
  supplied stem, not a stray cross-reference like *komunë* … sh. *a(t)*).
* **Forms**: the plural's indefinite and definite forms (the entry's suffix),
  its -ve and -sh/-ish cases; a form must occur in the lexicon, and uniparser
  must not read it as a lemma other than the singular or the plural.
* **Stem**: the one ``--rules`` gives the singular (rules with the verb table,
  so a noun form cannot take a verb's stem). Only forms the rules stem
  differently go in the table.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

from albanian_stemmer.lexicon import load_lexicon
from albanian_stemmer.rules import AlbanianStemmer
from albanian_stemmer.text import fold

_FULL = re.compile(r"^([a-zëç]+)(?:\(([a-zëç-]+)\))?$")


def irregular(entries: dict[str, list[dict]]) -> dict[str, tuple[str, str, str]]:
    """Singular → (plural, its definite suffix, the entry's notation)."""
    nouns = {}
    for key, readings in sorted(entries.items()):
        for x in readings:
            pl = x["plural"]
            m = _FULL.match(pl)
            if not pl.startswith("-") and m and len(m[1]) >= 3 and m[1][0] == fold(x["word"])[0]:
                nouns[x["word"]] = (m[1], (m[2] or "").lstrip("-"), pl)
    return nouns


def build(rules: AlbanianStemmer, entries: dict[str, list[dict]], lexicon: str) -> dict:
    from uniparser_albanian import AlbanianAnalyzer

    freq: collections.Counter = collections.Counter()
    for e in load_lexicon(lexicon):
        freq[fold(e.word)] += e.occurrences
    nouns = irregular(entries)
    cand = {}  # indefinite, definite, dative/genitive -ve, ablative -sh/-ish
    for sg, (pl, dsuf, _) in nouns.items():
        fs = {pl, pl + dsuf, pl + "ve", pl + ("sh" if pl[-1] in "aeëiouy" else "ësh"), pl + "ish"}
        cand[sg] = {fold(f) for f in fs if f}
    words = sorted({f for fs in cand.values() for f in fs} | {fold(s) for s in nouns})
    rd = {w: {fold(a.lemma) for a in anas if a.lemma}
          for w, anas in zip(words, AlbanianAnalyzer().analyze_words(words))}
    table: dict[str, str] = {}
    report = {}
    for sg, fs in sorted(cand.items()):
        lem, target = fold(sg), rules.stem(sg)
        keep, drop = [], {}
        for f in sorted(fs):
            if not freq[f]:
                drop[f] = "not in the corpus"
            elif other := rd.get(f, set()) - {lem, fold(nouns[sg][0])}:
                drop[f] = f"also {sorted(other)}"
            else:
                keep.append(f)
        moved = {f: target for f in keep if rules.stem(f) != target}
        table |= moved
        report[sg] = {"plural": nouns[sg][2], "stem": target, "moved": moved, "dropped": drop,
                      "tokens": sum(freq[f] for f in moved)}
    return {"exceptions": dict(sorted(table.items())),
            "tokens": {f: freq[f] for f in sorted(table)},
            "groups": {fold(s): sorted(r["moved"]) for s, r in report.items() if r["moved"]},
            "nouns": report,
            "source": "fjalorthi.com entries whose plural is written in full; lexicon "
                      + Path(lexicon).name}


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--rules", required=True,
                    help="rules fitted with the verb table (not this one)")
    ap.add_argument("--fjalorthi", default="data/grammar/fjalorthi.json")
    ap.add_argument("--lexicon", default="data/lexicons/web-sq-2026-11.tsv.gz")
    ap.add_argument("--out", required=True)
    args = ap.parse_args(argv)
    rules = AlbanianStemmer.from_json(json.loads(Path(args.rules).read_text()))
    entries = json.loads(Path(args.fjalorthi).read_text(encoding="utf-8"))["nouns"]
    out = build(rules, entries, args.lexicon)
    Path(args.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n",
                              encoding="utf-8")
    print(f"{len(out['exceptions'])} forms of {len(out['groups'])} nouns")
    return 0


if __name__ == "__main__":
    sys.exit(main())
