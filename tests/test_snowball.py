"""Albanian Snowball stemmer: the committed program, its compiled Python, and
the rules they are generated from agree; paradigms meet; folding holds."""

from __future__ import annotations

import itertools
import json
from concurrent.futures import ThreadPoolExecutor

import pytest

from albanian_stemmer import fit, snowball
from albanian_stemmer.rules import SNOWBALL_PATH, SURFACE_RULES_PATH, AlbanianStemmer

RULES = AlbanianStemmer.from_json(json.loads(SURFACE_RULES_PATH.read_text()))


def test_committed_snowball_matches_committed_rules():
    assert SNOWBALL_PATH.read_text() == RULES.to_snowball(fit.SNOWBALL_HEADER,
                                                          fit.snowball_notes(RULES))


def _probe_words() -> list[str]:
    """Every ending and rewrite on stems of 1–5 letters, so each among entry
    and each length condition is hit on both sides."""
    ends = {e for step in RULES.steps for e in step} | {r[0] for r in RULES.rewrites}
    stems = ["", "p", "pu", "pun", "punu", "punoj", "mollë", "sëmundj", "çel", "ujë"]
    words = {s + e for s, e in itertools.product(stems, sorted(ends))}
    words |= {s + a + b for s in stems[3:6] for a, b in itertools.product(sorted(ends), repeat=2)}
    words |= {k for k, _ in RULES.exceptions}  # every exception, and near misses of some
    words |= {k + "x" for k, _ in RULES.exceptions[::7]} | {k[:-1] for k, _ in RULES.exceptions[::7]}
    return sorted(words | {"", "x", "ç", "ëë", "SHTËPISË", "QENË", "thënë", "Mbajtur"})


def test_compiled_snowball_matches_the_rules():
    words = _probe_words()
    assert len(words) > 5000
    assert [snowball.stem(w) for w in words] == [RULES.stem(w) for w in words]


@pytest.mark.parametrize("family", [
    "molla mollë mollës mollën mollët mollëve molle mollat",
    "sëmundje sëmundja sëmundjes sëmundjen sëmundjet sëmundjeve",
    "pemë pema pemës pemën pemët pemëve pemësh",
    "domate domatja domates domaten domatet domateve",
    "punoj punon punojmë punuar punonte punohet punova punoi",
    "fermer fermeri fermerit fermerët fermerëve",
    "kontroll kontrolli kontrollit kontrolloj kontrollohet",
    # irregular verbs, through the exception table
    "them thotë thënë thoshte thuhet",
    "mbaj mban mbajti mbajtur mbahet",
    "marr merr marrë merret merren",
    "bëj bën bërë bëhet bëjnë",
    "vij vjen erdhi ardhur erdhën",
    # nouns whose own letters look like an ending, kept by letter conditions
    "problem problemi problemin problemit problemet",
    "sistem sistemi sistemin sistemet",
    "pjesë pjesa pjesën pjesës pjesët pjesëve",
    "shtëpi shtëpia shtëpinë shtëpisë shtëpitë",
    # and by stem rewrites: -itet/-ytet, -ull/-uj, -izëm/-izm
    "qytet qyteti qytetin qytetit qytete qytetet",
    "aktivitet aktiviteti aktivitetin aktivitetet",
    "artikull artikulli artikuj artikujt",
    "organizëm organizmi organizmat",
    # irregular plurals, through the noun table
    "dorë dora dorën duar duart duarve",
    "grua gruaja gra grave",
    "derë dera dyer dyert",
    "djalë djali djem djemtë",
    # shtet: no rule tells it from shtoj, so its bare form is listed
    "shtet shteti shtetin shtetit shtetet shteteve",
    # nouns of action in -im meet their verb (step3)
    "përdor përdorim përdorimi përdorimin përdoret",
    "kultivoj kultivim kultivimi kultivohet",
    "bashkëpunojmë bashkëpunim bashkëpunimi bashkëpunimet",
])
def test_paradigms_share_a_stem(family):
    assert len({snowball.stem(w) for w in family.split()}) == 1


@pytest.mark.parametrize("a, b", [
    ("shtet", "shtoj"), ("organizëm", "organizoj"), ("sportive", "sport"),
    ("pjesë", "pjek"), ("kosovë", "kosto"),
])
def test_unrelated_words_stay_apart(a, b):
    assert snowball.stem(a) != snowball.stem(b)


def test_folding_and_case():
    assert snowball.stem("semundjeve") == snowball.stem("Sëmundjeve") == "semund"
    assert snowball.stem("MOLLËS") == "moll"
    assert snowball.stem("kal") == "kal"  # three letters are never cut
    assert snowball.stem("trim") == "trim"  # -im only in R2


def test_terms_skip_stopwords():
    assert snowball.terms("Sëmundjet e mollës dhe të pemëve") == ["semund", "moll", "pem"]


def test_stem_is_thread_safe():
    words = _probe_words()[:2000]
    want = [RULES.stem(w) for w in words]
    with ThreadPoolExecutor(8) as pool:
        got = list(pool.map(lambda _: [snowball.stem(w) for w in words], range(8)))
    assert all(g == want for g in got)
