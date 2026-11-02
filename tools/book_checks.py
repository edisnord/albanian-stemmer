"""Reduce a grammar book's extraction to the checks the fit uses::

    uv run python tools/book_checks.py inflection.json --out data/grammar/book_checks.json

``inflection.json`` is what ``tools/extract_grammar_inflection.py`` extracts
from the book; it is not in the repository (the book is copyrighted). What is
kept are word lists only: the forms of each paradigm and the examples of an
inflectional affix or alternation (``families``, which must share a stem),
the examples of a derivational suffix (``apart``, which must not), and the
inflectional endings (``endings``). See :class:`albanian_stemmer.metrics.Book`.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

from albanian_stemmer.metrics import book_checks

SOURCE = ("Akademia e Shkencave e Shqipërisë, Instituti i Gjuhësisë dhe i Letërsisë, "
          "Gramatika e gjuhës shqipe 1: Morfologjia (Tiranë, 1995)")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("extraction", help="inflection.json from tools/extract_grammar_inflection.py")
    ap.add_argument("--out", required=True, help="checks to write (JSON)")
    ap.add_argument("--source", default=SOURCE, help="the book, as cited in the file")
    args = ap.parse_args(argv)
    c = book_checks(json.loads(Path(args.extraction).read_text(encoding="utf-8")))
    Path(args.out).write_text(json.dumps({"source": args.source, **c}, ensure_ascii=False,
                                         indent=0) + "\n", encoding="utf-8")
    print(f"{args.out}: {len(c['families'])} families, {len(c['apart'])} derivation pairs, "
          f"{len(c['endings'])} endings")
    return 0


if __name__ == "__main__":
    sys.exit(main())
