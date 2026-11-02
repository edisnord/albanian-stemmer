"""Build a corpus lexicon (:mod:`albanian_stemmer.lexicon`) from raw Albanian text.

Input: files or directories (searched recursively) of

* plain text (``.txt`` or any other suffix) — each non-empty line is a unit;
* JSON lines (``.jsonl``, ``.ndjson``) — each record's ``--text-field``, split
  into lines;

optionally compressed (``.gz``, ``.bz2``, ``.xz``; ``.zst`` with the
``zstandard`` package). A *unit* is a line or paragraph: the language filter
and the tagger see one unit at a time.

Two passes over the corpus:

1. **Count** every word of every Albanian unit. A unit is Albanian when it has
   at least ``--min-tokens`` tokens, at least ``--min-marker-share`` of them
   are frequent Albanian function words (:data:`MARKERS`, with or without
   ë/ç), and at least one is a word no neighbouring language shares
   (:data:`DISTINCTIVE`). That drops menus, cookie banners and the English,
   Italian and Greek pages a web crawl of Albanian sites carries. Words seen
   fewer than ``--min-count`` times are dropped (typos, run-together words).
2. **Tag** (``--tagger stanza``): Stanza's Albanian pipeline lemmatizes and
   POS-tags units in context — only units holding a word that still has fewer
   than ``--contexts-per-word`` tagged occurrences, so rare words get context
   and frequent ones do not use up the budget (``--max-tagged-chars``). This
   is what gives lemmas to words no dictionary knows and the function-word
   counts the stopword list comes from. ``--tagger none`` skips it (uniparser
   lemmas only, no stopwords).

Then uniparser-albanian adds its dictionary lemmas to every word. Pass 1's
counts and pass 2's progress are kept in ``--work`` (default: next to the
output), so an interrupted run resumes::

    uv run --extra lexicon python -m albanian_stemmer.build_lexicon \\
        ~/corpora/sq-webcrawl/ --out runs/web/lexicon.tsv.gz --min-count 3 --gpu
"""

from __future__ import annotations

import argparse
import bz2
import collections
import gzip
import io
import json
import logging
import lzma
import os
import pickle
import sys
import time
from collections.abc import Iterator
from pathlib import Path
from typing import Any, TextIO

from albanian_stemmer.lexicon import FUNCTION_POS, LexWord, write_lexicon
from albanian_stemmer.metrics import WORD
from albanian_stemmer.text import fold, tokenize

logger = logging.getLogger("albanian_stemmer.build_lexicon")

# Frequent Albanian function words, folded: an Albanian unit is full of them.
MARKERS = frozenset(
    "te e ne dhe i per me qe nje nga se u eshte jane do si nuk ka kane por edhe ku "
    "kur kjo ky keto ato ai ajo duhet mund".split())
# Of those, the ones no neighbouring language (en, it, fr, el in Latin, sr/hr)
# uses as a word: at least one must occur.
DISTINCTIVE = frozenset("dhe nje qe nga eshte jane nuk edhe kjo ky keto duhet mund".split())

_JSONL = {".jsonl", ".ndjson"}
_COMPRESSED = {".gz": gzip.open, ".bz2": bz2.open, ".xz": lzma.open}


# ─── Reading ──────────────────────────────────────────────────────────────────

def _files(paths: list[str]) -> list[Path]:
    out: list[Path] = []
    for p in map(Path, paths):
        if p.is_dir():
            out += sorted(f for f in p.rglob("*") if f.is_file() and not f.name.startswith("."))
        else:
            out.append(p)
    return out


def _open_text(path: Path) -> TextIO:
    if path.suffix == ".zst":
        import zstandard  # optional

        raw = zstandard.ZstdDecompressor().stream_reader(open(path, "rb"))
        return io.TextIOWrapper(raw, encoding="utf-8", errors="replace")
    opener = _COMPRESSED.get(path.suffix)
    if opener is not None:
        return opener(path, "rt", encoding="utf-8", errors="replace")  # type: ignore[return-value]
    return open(path, encoding="utf-8", errors="replace")


def iter_units(paths: list[str], text_field: str = "text") -> Iterator[str]:
    """The corpus's non-empty lines, in a fixed order (so a resumed pass can skip)."""
    for path in _files(paths):
        inner = Path(path.stem) if path.suffix in (*_COMPRESSED, ".zst") else path
        with _open_text(path) as f:
            if inner.suffix in _JSONL:
                for line in f:
                    try:
                        text = json.loads(line).get(text_field)
                    except (json.JSONDecodeError, AttributeError):
                        continue
                    if isinstance(text, str):
                        yield from (u for u in map(str.strip, text.splitlines()) if u)
            else:
                yield from (u for u in map(str.strip, f) if u)


def albanian_tokens(unit: str, min_tokens: int, min_share: float) -> list[str] | None:
    """*unit*'s tokens if it reads as Albanian (see the module doc), else None."""
    toks = tokenize(unit)
    if len(toks) < min_tokens:
        return None
    folded = [fold(t) for t in toks]
    markers = sum(t in MARKERS for t in folded)
    if markers < min_share * len(toks) or not any(t in DISTINCTIVE for t in folded):
        return None
    return toks


# ─── Pass 1: counts ───────────────────────────────────────────────────────────

def count_words(units: Iterator[str], min_tokens: int, min_share: float,
                ) -> tuple[collections.Counter, dict[str, int]]:
    counts: collections.Counter = collections.Counter()
    stats = {"units": 0, "albanian_units": 0, "tokens": 0, "chars": 0}
    t0 = time.monotonic()
    for unit in units:
        stats["units"] += 1
        toks = albanian_tokens(unit, min_tokens, min_share)
        if toks is not None:
            stats["albanian_units"] += 1
            stats["chars"] += len(unit)
            words = [t for t in toks if WORD.match(t)]
            stats["tokens"] += len(words)
            counts.update(words)
        if stats["units"] % 1_000_000 == 0:
            logger.info("count: %d units, %d Albanian, %d tokens, %d types (%.0f s)",
                        stats["units"], stats["albanian_units"], stats["tokens"], len(counts),
                        time.monotonic() - t0)
    return counts, stats


def _save_counts(path: Path, counts: collections.Counter, stats: dict[str, int]) -> None:
    tmp = path.with_suffix(".tmp")
    with gzip.open(tmp, "wt", encoding="utf-8") as f:
        f.write(json.dumps(stats) + "\n")
        for w, n in counts.items():
            f.write(f"{w}\t{n}\n")
    os.replace(tmp, path)


def _load_counts(path: Path) -> tuple[collections.Counter, dict[str, int]]:
    counts: collections.Counter = collections.Counter()
    with gzip.open(path, "rt", encoding="utf-8") as f:
        stats = json.loads(next(f))
        for line in f:
            w, n = line.rstrip("\n").split("\t")
            counts[w] = int(n)
    return counts, stats


# ─── Pass 2: Stanza ───────────────────────────────────────────────────────────

class StanzaTagger:
    """Stanza's Albanian lemmas and function-word counts for the vocabulary,
    from units chosen to give each word up to *k* tagged occurrences."""

    def __init__(self, vocab: set[str], k: int, state_path: Path, *,
                 stanza_dir: str | None = None, gpu: bool = False, batch_units: int = 64,
                 max_unit_chars: int = 3000):
        self.vocab, self.k, self.state_path = vocab, k, state_path
        self.batch_units, self.max_unit_chars = batch_units, max_unit_chars
        self.stanza_dir, self.gpu = stanza_dir, gpu
        # word → [lemmas, tagged occurrences, function occurrences]
        self.tags: dict[str, list[Any]] = {}
        self.need = dict.fromkeys(vocab, k)  # contexts still wanted, per word
        self.next_unit = 0
        self.chars = 0
        if state_path.exists():
            with open(state_path, "rb") as f:
                s = pickle.load(f)
            self.tags, self.need, self.next_unit, self.chars = (
                s["tags"], s["need"], s["next_unit"], s["chars"])
            logger.info("tag: resuming at unit %d (%d chars tagged, %d words still wanted)",
                        self.next_unit, self.chars, sum(v > 0 for v in self.need.values()))

    def _pipeline(self):
        import stanza  # optional `lexicon` extra
        from stanza.pipeline.core import DownloadMethod

        processors = "tokenize,mwt,pos,lemma"
        dirs: dict[str, Any] = {"model_dir": self.stanza_dir} if self.stanza_dir else {}
        stanza.download("sq", processors=processors, verbose=False, **dirs)
        pipeline_dirs: dict[str, Any] = {"dir": self.stanza_dir} if self.stanza_dir else {}
        return stanza.Pipeline("sq", processors=processors, use_gpu=self.gpu, verbose=False,
                               download_method=DownloadMethod.NONE, **pipeline_dirs)

    def _save(self) -> None:
        tmp = self.state_path.with_suffix(".tmp")
        with open(tmp, "wb") as f:
            pickle.dump({"tags": self.tags, "need": self.need, "next_unit": self.next_unit,
                         "chars": self.chars}, f, protocol=pickle.HIGHEST_PROTOCOL)
        os.replace(tmp, self.state_path)

    def _clip(self, unit: str) -> str:
        if len(unit) <= self.max_unit_chars:
            return unit
        cut = unit.rfind(" ", 0, self.max_unit_chars)
        return unit[: cut if cut > 0 else self.max_unit_chars]

    def _tag(self, nlp, batch: list[str]) -> None:
        import stanza

        docs = nlp.bulk_process([stanza.Document([], text=u) for u in batch])
        for unit, doc in zip(batch, docs):
            # Stanza's in-context reading of each surface word in this unit. Its
            # tokenization can differ from ours (clitics, hyphens), so it is keyed
            # by word and our own tokenizer drives.
            seen: dict[str, tuple[set[str], int, int]] = {}
            for sent in doc.sentences:
                for w in sent.words:
                    key = w.text.lower()
                    lemmas, n, fn = seen.get(key, (set(), 0, 0))
                    if w.lemma:
                        lemmas.add(w.lemma.lower())
                    seen[key] = (lemmas, n + 1, fn + (w.upos in FUNCTION_POS))
            for tok in tokenize(unit):
                if tok not in self.vocab:
                    continue
                lemmas, n, fn = seen.get(tok, (set(), 0, 0))
                t = self.tags.setdefault(tok, [set(), 0, 0])
                t[0] |= lemmas
                t[1] += 1
                t[2] += int(n > 0 and fn * 2 > n)
            self.chars += len(unit)

    def run(self, units: Iterator[str], min_tokens: int, min_share: float,
            max_chars: int | None, save_every: int = 50) -> None:
        wanted = sum(v > 0 for v in self.need.values())
        if not wanted or self.next_unit == sys.maxsize:
            return
        nlp = self._pipeline()
        batch: list[str] = []
        batches, t0, chars0 = 0, time.monotonic(), self.chars
        resume_at = sys.maxsize  # done, unless the budget stops us: a rerun skips this pass
        for i, unit in enumerate(units):
            if i < self.next_unit:
                continue
            if max_chars is not None and self.chars >= max_chars:
                logger.info("tag: --max-tagged-chars reached; a rerun with a larger "
                            "budget continues from here")
                resume_at = i
                break
            toks = albanian_tokens(unit, min_tokens, min_share)
            if toks is None or not any(self.need.get(t, 0) > 0 for t in toks):
                continue
            unit = self._clip(unit)
            for t in tokenize(unit):
                if self.need.get(t, 0) > 0:
                    self.need[t] -= 1
                    wanted -= self.need[t] == 0
            batch.append(unit)
            if len(batch) >= self.batch_units:
                self._tag(nlp, batch)
                batch, self.next_unit = [], i + 1
                batches += 1
                if batches % save_every == 0:
                    self._save()
                    rate = (self.chars - chars0) / max(time.monotonic() - t0, 1e-9)
                    logger.info("tag: unit %d, %d chars tagged (%.0f chars/s), "
                                "%d words still wanted", i, self.chars, rate, wanted)
            if wanted == 0:
                break
        if batch:
            self._tag(nlp, batch)
        self.next_unit = resume_at
        self._save()


# ─── Main ─────────────────────────────────────────────────────────────────────

def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("inputs", nargs="+", help="corpus files or directories")
    ap.add_argument("--out", required=True, help="lexicon TSV to write (.gz to compress)")
    ap.add_argument("--work", help="directory for resumable state (default: <out>.work)")
    ap.add_argument("--text-field", default="text", help="JSON lines: the text field")
    ap.add_argument("--min-count", type=int, default=3,
                    help="drop words seen fewer times (default: %(default)s)")
    ap.add_argument("--min-tokens", type=int, default=5,
                    help="shorter units are skipped (default: %(default)s)")
    ap.add_argument("--min-marker-share", type=float, default=0.10,
                    help="share of a unit's tokens that must be Albanian function words "
                         "(default: %(default)s; 0 with --min-tokens 1 keeps everything "
                         "with a distinctive word)")
    ap.add_argument("--tagger", choices=("stanza", "none"), default="stanza")
    ap.add_argument("--contexts-per-word", type=int, default=3,
                    help="tagged occurrences wanted per word (default: %(default)s)")
    ap.add_argument("--max-tagged-chars", type=int,
                    help="stop tagging after this many characters")
    ap.add_argument("--batch-units", type=int, default=64)
    ap.add_argument("--stanza-dir", help="Stanza model directory")
    ap.add_argument("--gpu", action="store_true", help="run Stanza on the GPU")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")

    out = Path(args.out)
    work = Path(args.work or f"{out}.work")
    work.mkdir(parents=True, exist_ok=True)
    units = lambda: iter_units(args.inputs, args.text_field)  # noqa: E731

    counts_path = work / "counts.tsv.gz"
    if counts_path.exists():
        counts, stats = _load_counts(counts_path)
        logger.info("count: reusing %s (%d types)", counts_path, len(counts))
    else:
        counts, stats = count_words(units(), args.min_tokens, args.min_marker_share)
        _save_counts(counts_path, counts, stats)
    vocab = {w for w, n in counts.items() if n >= args.min_count}
    logger.info("count: %d units, %d Albanian, %d tokens, %d types, %d seen >= %d times",
                stats["units"], stats["albanian_units"], stats["tokens"], len(counts),
                len(vocab), args.min_count)

    tags: dict[str, list[Any]] = {}
    if args.tagger == "stanza":
        tagger = StanzaTagger(vocab, args.contexts_per_word, work / "stanza_state.pkl",
                              stanza_dir=args.stanza_dir, gpu=args.gpu,
                              batch_units=args.batch_units)
        tagger.run(units(), args.min_tokens, args.min_marker_share, args.max_tagged_chars)
        tags = tagger.tags
        stats["tagged_chars"] = tagger.chars
        logger.info("tag: %d chars tagged; %d / %d words have a tagged occurrence",
                    tagger.chars, len(tags), len(vocab))

    from albanian_stemmer.fit import uniparser_readings

    words = sorted(vocab)
    readings = uniparser_readings(words)
    lexicon = []
    for w in words:
        lemmas, tagged, fn = tags.get(w, (set(), 0, 0))
        lemmas = set(lemmas) | {lemma.lower() for lemma, _, _ in readings.get(w, [])}
        lexicon.append(LexWord(w, sorted(lemmas), counts[w], fn,
                               tagged if args.tagger == "stanza" else 0))
    n = write_lexicon(out, lexicon)
    stats |= {"lexicon_words": n, "min_count": args.min_count, "tagger": args.tagger,
              "words_with_lemmas": sum(bool(e.lemmas) for e in lexicon),
              "words_tagged": sum(bool(e.tagged) for e in lexicon),
              "stopword_candidates": sum(e.is_stopword for e in lexicon)}
    (work / "stats.json").write_text(json.dumps(stats, indent=1) + "\n")
    logger.info("wrote %s (%d words); stats in %s", out, n, work / "stats.json")
    return 0


if __name__ == "__main__":
    sys.exit(main())
