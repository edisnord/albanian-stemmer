"""Word tokens and diacritic folding for Albanian text.

``fold`` is what the Postgres extension's ``albanian_fold`` (postgres/albanian_core.c)
does to a word Postgres has lowercased.
"""

from __future__ import annotations

import re

_TOKEN = re.compile(r"[^\W_]+", re.UNICODE)
_FOLD = str.maketrans({"ë": "e", "ç": "c"})


def fold(word: str) -> str:
    """Lowercase and drop the Albanian diacritics (ë→e, ç→c)."""
    return word.lower().translate(_FOLD)


def tokenize(text: str) -> list[str]:
    """Lowercased word tokens of *text* (letters/digits, no punctuation)."""
    return [t.lower() for t in _TOKEN.findall(text)]
