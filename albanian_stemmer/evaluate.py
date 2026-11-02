"""Score stemmer rules against a corpus lexicon (and the grammar book), with baselines.

Unlike :mod:`albanian_stemmer.fit`, this fits nothing: it measures given
rules on a (new) lexicon, so the committed rules can be checked against a
larger or more general corpus than they were fitted on, and two rule sets
compared on the same one. Baselines: no stemming (folding only) and
truncation to the first *n* letters::

    uv run python -m albanian_stemmer.evaluate --lexicon runs/web/lexicon.tsv.gz \\
        --book data/grammar/book_checks.json \\
        --rules albanian_stemmer/snowball/albanian.json runs/web/albanian.json \\
        --report runs/web/eval.json

Split ``held-out`` is the lemma half :mod:`albanian_stemmer.fit` does not fit
on; ``all`` is every word. Compare rules fitted on another lexicon on ``all``.
"""

from __future__ import annotations

import argparse
import json
import logging
import os
import sys
from pathlib import Path
from typing import Any

from albanian_stemmer.lexicon import load_lexicon
from albanian_stemmer.metrics import Book, Corpus, PrefixStemmer, Stemmer, top_words
from albanian_stemmer.rules import SURFACE_RULES_PATH, AlbanianStemmer

logger = logging.getLogger("albanian_stemmer.evaluate")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--lexicon", required=True, help="corpus lexicon TSV (.gz ok)")
    ap.add_argument("--rules", nargs="+", default=[str(SURFACE_RULES_PATH)],
                    help="rules JSON files to score (default: the committed rules)")
    ap.add_argument("--book", help="the grammar book's checks (data/grammar/book_checks.json)")
    ap.add_argument("--prefix", type=int, nargs="*", default=[4, 5, 6],
                    help="truncation baselines to score (default: %(default)s)")
    ap.add_argument("--max-words", type=int, help="score the N most frequent words only")
    ap.add_argument("--report", help="write the scores as JSON here")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")

    lexicon = top_words(load_lexicon(args.lexicon), args.max_words)
    logger.info("%d lexicon words", len(lexicon))
    splits = {"held-out": Corpus(lexicon, 1), "all": Corpus(lexicon, None)}
    book = Book(args.book) if args.book else None
    stemmers: dict[str, Stemmer] = {"none": AlbanianStemmer((), 99)}
    stemmers |= {f"prefix-{n}": PrefixStemmer(n) for n in args.prefix}
    for path in args.rules:
        name = ("committed" if Path(path).resolve() == SURFACE_RULES_PATH.resolve()
                else os.path.relpath(path))
        stemmers[name] = AlbanianStemmer.from_json(json.loads(Path(path).read_text()))

    rows: dict[str, dict[str, Any]] = {}
    for name, st in stemmers.items():
        r: dict[str, Any] = {s: c.score(st) for s, c in splits.items()}
        if book is not None:
            r["book"] = book.score(st)
        rows[name] = r

    cols = ["P_type", "R_type", "P_tok", "R_tok", "stems"]
    width = max(len(n) for n in rows)
    print(f"{'stemmer':<{width}}  {'split':<8}  " + "  ".join(f"{c:>7}" for c in cols)
          + ("  book_R  apart" if book else ""))
    for name, r in rows.items():
        for split in splits:
            vals = "  ".join(f"{r[split][c]:>7.0f}" if c == "stems" else f"{r[split][c]:>7.3f}"
                             for c in cols)
            extra = (f"  {r['book']['R_book']:>6.3f}  {r['book']['apart_book']:>5.3f}"
                     if book and split == "all" else "")
            print(f"{name:<{width}}  {split:<8}  {vals}{extra}")
    if args.report:
        Path(args.report).write_text(json.dumps({"lexicon": args.lexicon, "words": len(lexicon),
                                                 "scores": rows}, indent=1, default=float) + "\n")
        logger.info("wrote %s", args.report)
    return 0


if __name__ == "__main__":
    sys.exit(main())
