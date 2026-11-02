"""The Postgres extension (postgres/): its generated C is up to date, and its
stemming, compiled with gcc outside Postgres, matches Python's.

With ALBANIAN_STEMMER_TEST_DSN set to a Postgres where the extension is
installed (``make install`` in postgres/), it is also checked in the server.
"""

from __future__ import annotations

import os
import shutil
import subprocess

import pytest

from albanian_stemmer import fit, snowball
from albanian_stemmer.rules import POSTGRES_DIR
from albanian_stemmer.text import fold

from test_snowball import RULES, _probe_words

TEST_DSN = os.environ.get("ALBANIAN_STEMMER_TEST_DSN")
SOURCES = ["albanian_core.c", "stem_UTF_8_albanian.c", "runtime/api.c",
           "runtime/snowball_runtime.c"]


def test_stopword_header_matches_the_rules():
    assert (POSTGRES_DIR / "albanian_stopwords.h").read_text() == fit.stopwords_header(RULES)


def _words() -> list[str]:
    return [w for w in _probe_words() if w] + sorted(RULES.stopwords) + [
        "Sëmundjet", "MOLLËS", "Çelësi", "dhe", "Të", "përdorimi", "kultivimin", "ë"]


@pytest.fixture(scope="module")
def stem_words(tmp_path_factory):
    if not shutil.which("gcc"):
        pytest.skip("gcc not found")
    exe = tmp_path_factory.mktemp("c") / "stem_words"
    subprocess.run(["gcc", "-O2", "-Wall", "-Wextra", "-Werror", "-Wno-unused-parameter",
                    "-include", "snowball_prefix.h", "-I.", "-o", str(exe),
                    *SOURCES, str(POSTGRES_DIR.parent / "tests" / "c" / "stem_words.c")],
                   cwd=POSTGRES_DIR, check=True)
    return exe


def test_c_stems_like_python(stem_words):
    words = _words()
    out = subprocess.run([str(stem_words)], input="".join(w.lower() + "\n" for w in words),
                         capture_output=True, text=True, check=True).stdout.splitlines()
    stop = snowball.stopwords()
    want = [("", "1") if fold(w) in stop else (snowball.stem(w), "0") for w in words]
    assert [tuple(line.split("\t")) for line in out] == want


def test_runtime_symbols_are_renamed(stem_words):
    # Postgres's dict_snowball exports find_among, SN_set_current, ...: ours must not.
    syms = subprocess.run(["nm", "-g", "--defined-only", str(stem_words)],
                          capture_output=True, text=True, check=True).stdout
    names = {line.split()[-1] for line in syms.splitlines() if line.strip()}
    assert "albanian_sb_find_among" in names
    assert not names & {"find_among", "find_among_b", "SN_set_current", "SN_new_env", "slice_from_s"}


def test_in_postgres():
    if not TEST_DSN:
        pytest.skip("ALBANIAN_STEMMER_TEST_DSN not set")
    import psycopg

    words = _words()
    with psycopg.connect(TEST_DSN) as c:
        c.execute("CREATE EXTENSION IF NOT EXISTS albanian_stemmer")
        rows = c.execute("SELECT ts_lexize('albanian_stem', w) FROM unnest(%s::text[]) w",
                         (words,)).fetchall()
        got = [r[0] for r in rows]
        want = [[] if fold(w) in snowball.stopwords() else [snowball.stem(w)] for w in words]
        assert got == want
        v = c.execute("SELECT to_tsvector('albanian', 'Sëmundjet e mollës dhe të pemëve')::text"
                      ).fetchone()[0]
        assert v == "'moll':3 'pem':6 'semund':1"
        c.rollback()
