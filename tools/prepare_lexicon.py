"""Merge corpus lexicons into the one the fit and the scores use, and relabel
spellings without ë/ç::

    uv run python tools/prepare_lexicon.py --out data/lexicons/web-sq-2026-11.tsv.gz \\
        runs/fineweb/lexicon.tsv.gz runs/crawl/lexicon.tsv.gz

* **Merge**: a word's occurrences and function-word counts add up, its lemmas
  are the union of the inputs'.
* **Relabel**: web text often drops ë and ç (*shume* for *shumë*, *vetem*,
  *jete*), and Stanza gives such spellings lemmas of their own, often wrong
  ones (*jam*). Since the stemmer folds ë and ç, those spellings would link
  unrelated words in the scores. Every spelling that folds like a more
  frequent one gets that spelling's lemmas.
"""

from __future__ import annotations

import argparse
import collections
import logging
import sys

from albanian_stemmer.lexicon import LexWord, load_lexicon, write_lexicon
from albanian_stemmer.text import fold

logger = logging.getLogger("prepare_lexicon")


def merge(lexicons: list[list[LexWord]]) -> list[LexWord]:
    by_word: dict[str, LexWord] = {}
    for lex in lexicons:
        for e in lex:
            if (o := by_word.get(e.word)) is None:
                by_word[e.word] = LexWord(e.word, list(e.lemmas), e.occurrences,
                                          e.function_occurrences, e.tagged)
                continue
            # tagged None: every occurrence was tagged
            tagged = (o.occurrences if o.tagged is None else o.tagged) + (
                e.occurrences if e.tagged is None else e.tagged)
            o.lemmas = sorted(set(o.lemmas) | set(e.lemmas))
            o.occurrences += e.occurrences
            o.function_occurrences += e.function_occurrences
            o.tagged = None if tagged == o.occurrences else tagged
    return list(by_word.values())


def relabel_spellings(lexicon: list[LexWord]) -> tuple[list[LexWord], int]:
    groups: dict[str, list[LexWord]] = collections.defaultdict(list)
    for e in lexicon:
        groups[fold(e.word)].append(e)
    out, changed = [], 0
    for ws in groups.values():
        best = max(ws, key=lambda e: (e.occurrences, e.word))
        for e in ws:
            if e is not best and set(e.lemmas) != set(best.lemmas):
                changed += 1
            out.append(LexWord(e.word, best.lemmas if e is not best else e.lemmas,
                               e.occurrences, e.function_occurrences, e.tagged))
    return out, changed


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("lexicons", nargs="+", help="lexicons from albanian_stemmer.build_lexicon")
    ap.add_argument("--out", required=True, help="merged lexicon to write (.gz to compress)")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")
    lex = merge([load_lexicon(p) for p in args.lexicons])
    lex, changed = relabel_spellings(lex)
    n = write_lexicon(args.out, lex)
    logger.info("wrote %s: %d words, %d minor spellings relabelled", args.out, n, changed)
    return 0


if __name__ == "__main__":
    sys.exit(main())
