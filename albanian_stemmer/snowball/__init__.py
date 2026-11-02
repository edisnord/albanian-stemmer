"""Albanian Snowball stemmer.

``albanian.sbl`` is a Snowball program (https://snowballstem.org), so it
compiles to every Snowball target: Python (``albanian_stemmer.py``, run on the
``snowballstemmer`` runtime), C, Java, JavaScript, Go, Rust. Both are
generated, with the rules they come from (``albanian.json``), by::

    uv run --extra fit python -m albanian_stemmer.fit \\
        --book data/grammar/book_checks.json --snowball /path/to/snowball

They strip the suffixed article and the case endings (*mollës*, *sëmundjeve*,
*fermerët*), so they stem running text with no lemmatizer before them.
"""

from __future__ import annotations

import threading

from albanian_stemmer.text import fold, tokenize

_local = threading.local()
_STOPWORDS: frozenset[str] | None = None


def _stemmer():
    # A Snowball stemmer object keeps its working state on itself: one per thread.
    st = getattr(_local, "stemmer", None)
    if st is None:
        from albanian_stemmer.snowball.albanian_stemmer import AlbanianSnowballStemmer

        st = _local.stemmer = AlbanianSnowballStemmer()
    return st


def stem(word: str) -> str:
    """The stem of *word* (any case, with or without ë/ç)."""
    return _stemmer().stemWord(word.lower())


def stopwords() -> frozenset[str]:
    """The folded stopwords stored with the rules."""
    global _STOPWORDS
    if _STOPWORDS is None:
        import json
        from pathlib import Path

        rules = json.loads(Path(__file__).with_name("albanian.json").read_text())
        _STOPWORDS = frozenset(rules.get("stopwords", ()))
    return _STOPWORDS


def terms(text: str) -> list[str]:
    """Stems of *text*'s non-stopword tokens, in order."""
    stop = stopwords()
    return [stem(t) for t in tokenize(text) if fold(t) not in stop]
