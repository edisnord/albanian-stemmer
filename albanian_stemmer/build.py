"""Build the stemmer from its rules: the release path.

``albanian_stemmer/snowball/albanian.json`` is the source, edited by hand: the
endings of each step, their letter conditions, the stem rewrites, the minimum
stem and the stopwords. Its ``exceptions`` are not edited there: they are the
tables in ``data/grammar`` (``irregular_verbs.json``, ``irregular_nouns.json``,
``ambiguous_nouns.json``), merged in by this command, earlier files first::

    uv run --extra fit python -m albanian_stemmer.build --snowball /path/to/snowball

writes ``albanian.json`` with the tables, the Snowball program ``albanian.sbl``,
its ``stop.txt``, the compiled Python ``albanian_stemmer.py`` and the Postgres
extension's C. Without ``--snowball`` only the first three.

A table's stems are the rules' stems, so after changing an ending, add
``--tables`` to rebuild the verb table from the rules alone, then the noun
table from the rules with the verb table (``tools/build_paradigm_verbs.py``,
``tools/build_irregular_nouns.py``; they need a checkout of the repository).
``ambiguous_nouns.json`` is hand-written.

To try a change before adopting it, score a copy with
``python -m albanian_stemmer.evaluate --rules``; ``albanian_stemmer.fit`` is
the search the rules first came from, kept for analysis.
"""

from __future__ import annotations

import argparse
import collections
import importlib.util
import json
import logging
import sys
import tempfile
from pathlib import Path

from albanian_stemmer import fit
from albanian_stemmer.lexicon import load_lexicon
from albanian_stemmer.rules import POSTGRES_DIR, SURFACE_RULES_PATH, AlbanianStemmer
from albanian_stemmer.text import fold

logger = logging.getLogger("albanian_stemmer.build")

ROOT = Path(__file__).resolve().parents[1]
GRAMMAR = ROOT / "data" / "grammar"
TABLES = (GRAMMAR / "irregular_verbs.json", GRAMMAR / "irregular_nouns.json",
          GRAMMAR / "ambiguous_nouns.json")


def read_tables(paths) -> dict[str, str]:
    """The exception tables merged; a form in two tables keeps the earlier one's stem."""
    exceptions: dict[str, str] = {}
    for path in paths:
        d = json.loads(Path(path).read_text(encoding="utf-8"))
        exceptions = {**d.get("exceptions", d), **exceptions}
    return exceptions


def with_exceptions(st: AlbanianStemmer, exceptions: dict[str, str]) -> AlbanianStemmer:
    return AlbanianStemmer(st.steps, st.min_stem, st.rewrites, st.stopwords, st.conditions,
                           tuple(exceptions.items()))


def _tool(name: str):
    path = ROOT / "tools" / f"{name}.py"
    if not path.exists():
        raise SystemExit(f"--tables needs {path} (a checkout of the repository)")
    sys.path.insert(0, str(path.parent))
    spec = importlib.util.spec_from_file_location(name, path)
    mod = importlib.util.module_from_spec(spec)  # type: ignore[arg-type]
    spec.loader.exec_module(mod)  # type: ignore[union-attr]
    return mod


def rebuild_tables(rules: AlbanianStemmer, verbs: Path, nouns: Path) -> None:
    """The verb table from *rules* alone, then the noun table from *rules* with it."""
    with tempfile.TemporaryDirectory() as tmp:
        bare = Path(tmp) / "rules.json"
        bare.write_text(json.dumps(with_exceptions(rules, {}).to_json(), ensure_ascii=False))
        _tool("build_paradigm_verbs").main(["--rules", str(bare), "--out", str(verbs)])
        with_verbs = Path(tmp) / "verbs.json"
        with_verbs.write_text(json.dumps(with_exceptions(rules, read_tables([verbs])).to_json(),
                                         ensure_ascii=False))
        _tool("build_irregular_nouns").main(["--rules", str(with_verbs), "--out", str(nouns)])


def spellings(stopwords, lexicon: str) -> collections.Counter:
    """Each stopword spelling's occurrences in *lexicon*, for ``stop.txt``."""
    freq: collections.Counter = collections.Counter()
    for e in load_lexicon(lexicon):
        if fold(e.word) in stopwords:
            freq[e.word.lower()] += e.occurrences
    return freq


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--rules", default=str(SURFACE_RULES_PATH),
                    help="the rules, rewritten in place with the tables")
    ap.add_argument("--tables", action="store_true",
                    help="first rebuild the verb and noun tables from the rules")
    ap.add_argument("--exceptions", nargs="+", default=[str(p) for p in TABLES],
                    help="the exception tables, earlier files first")
    ap.add_argument("--lexicon", default=str(fit.LEXICON_PATH),
                    help="for stop.txt: each stopword in its commonest spelling here")
    ap.add_argument("--snowball", help="the Snowball compiler: also write the Python "
                    "module and the Postgres extension's C (github.com/snowballstem/snowball)")
    ap.add_argument("--postgres", default=str(POSTGRES_DIR),
                    help="where the extension's generated C goes (with --snowball)")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")

    rules_path = Path(args.rules)
    st = AlbanianStemmer.from_json(json.loads(rules_path.read_text(encoding="utf-8")))
    if args.tables:
        rebuild_tables(st, Path(args.exceptions[0]), Path(args.exceptions[1]))
    st = with_exceptions(st, read_tables(args.exceptions))
    logger.info("%d exceptions from %d tables", len(st.exceptions), len(args.exceptions))
    rules_path.write_text(json.dumps(st.to_json(), ensure_ascii=False, indent=1) + "\n")
    logger.info("wrote %s", rules_path)
    sbl = rules_path.with_suffix(".sbl")
    sbl.with_name("stop.txt").write_text(
        fit.stop_list(st, spellings(st.stopwords, args.lexicon)), encoding="utf-8")
    fit.write_snowball(st, sbl, args.snowball,
                       Path(args.postgres) if args.snowball and args.postgres else None)
    return 0


if __name__ == "__main__":
    sys.exit(main())
