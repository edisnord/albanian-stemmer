"""The corpus lexicon the stemmer is fitted and scored against.

One line per corpus word (lowercased, with its diacritics)::

    word<TAB>lemma|lemma…<TAB>occurrences<TAB>function_occurrences[<TAB>tagged]

* *lemmas* — every lemma a lemmatizer gave the word (Stanza in context ∪
  uniparser-albanian), so two words sharing one are taken to be forms of one
  lexeme;
* *occurrences* — how often the word occurs in the corpus;
* *function_occurrences* — of its *tagged* occurrences, how many Stanza tagged
  as a function word (:data:`FUNCTION_POS`);
* *tagged* — how many of its occurrences were POS-tagged. Optional: a
  four-column file tagged every occurrence (*tagged* = *occurrences*).

A word is a stopword candidate when most of its tagged occurrences are
function words. Built from raw text by :mod:`albanian_stemmer.build_lexicon`.
"""

from __future__ import annotations

import gzip
from collections.abc import Iterable
from dataclasses import dataclass
from pathlib import Path
from typing import TextIO, cast

# Universal POS tags of words that carry no topic.
FUNCTION_POS: frozenset[str] = frozenset(
    {"ADP", "AUX", "CCONJ", "DET", "PART", "PRON", "SCONJ", "PUNCT", "SYM"}
)


@dataclass
class LexWord:
    word: str                  # as stored: lowercased, unfolded
    lemmas: list[str]
    occurrences: int
    function_occurrences: int
    tagged: int | None = None  # None: every occurrence was tagged

    @property
    def is_stopword(self) -> bool:  # tagged a function word in most tagged occurrences
        n = self.occurrences if self.tagged is None else self.tagged
        return self.function_occurrences * 2 > n


def _open(path: str | Path, mode: str) -> TextIO:
    if str(path).endswith(".gz"):
        return cast(TextIO, gzip.open(path, mode, encoding="utf-8"))
    return cast(TextIO, open(path, mode, encoding="utf-8"))


def load_lexicon(path: str | Path) -> list[LexWord]:
    out = []
    with _open(path, "rt") as f:
        for line in f:
            w, lemmas, occ, fn, *rest = line.rstrip("\n").split("\t")
            out.append(LexWord(w, [x for x in lemmas.split("|") if x], int(occ), int(fn),
                               int(rest[0]) if rest else None))
    return out


def write_lexicon(path: str | Path, words: Iterable[LexWord]) -> int:
    n = 0
    with _open(path, "wt") as f:
        for e in sorted(words, key=lambda e: e.word):
            cols = [e.word, "|".join(sorted(e.lemmas)), str(e.occurrences),
                    str(e.function_occurrences)]
            if e.tagged is not None:
                cols.append(str(e.tagged))
            f.write("\t".join(cols) + "\n")
            n += 1
    return n
