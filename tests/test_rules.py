"""Albanian light stemmer: rules, serialization, and the Snowball program."""

from __future__ import annotations

import pytest

from albanian_stemmer.rules import AlbanianStemmer, default_stemmer, regions

TOY = AlbanianStemmer(
    steps=(("ve", "t", "it", "s", "i"), ("e", "ra")),
    min_stem=3,
    rewrites=(("ua", "o"), ("j", "")),
    stopwords=frozenset({"dhe", "per"}),
)

# TOY with region conditions: -em/-emi only in R2, -t only in R1.
REGIONAL = AlbanianStemmer(
    steps=(("ve", "t", "it", "s", "i", "em", "emi", "in"), ("e", "ra")),
    min_stem=3,
    rewrites=(("ua", "o"), ("j", "")),
    stopwords=frozenset({"dhe", "per"}),
    conditions=((("em", "R2"), ("emi", "R2"), ("t", "R1")),),
)

# TOY with letter-before conditions: -t/-s after a vowel, -u after k/g/h,
# -in after a non-vowel.
PRECEDING = AlbanianStemmer(
    steps=(("ve", "t", "it", "s", "i", "u", "in"), ("e", "ra")),
    min_stem=3,
    rewrites=(("ua", "o"), ("j", "")),
    conditions=((("t", "V"), ("s", "V"), ("u", "KGH"), ("in", "C")),),
)

WORDS = ["Mollët", "molle", "plehrave", "malet", "mali", "punuar", "sëmundjet", "sëmundje",
         "dhe", "për", "kal", "ujë", "ÇELËSIT", "x", "", "problem", "problemi", "problemin",
         "rast", "rasti", "rastet", "mjeku", "mjekut", "ujet", "ujit", "drurin",
         "malin", "fshatit", "hapem", "zbulojmë" * 40, "qenë", "thënë", "mbajtur", "parë"]


def test_steps_run_in_order_longest_ending_first():
    assert TOY.stem("plehrave") == "pleh"     # -ve, then -ra
    assert TOY.stem("malet") == "mal"         # -t, then -e
    assert TOY.stem("mali") == "mal"
    assert TOY.stem("sëmundjet") == "semund"  # folded, -t, -e, then j → ∅
    assert TOY.stem("kal") == "kal"           # min_stem keeps short words whole
    assert TOY.stem("punuar") == "punuar"     # no listed ending: rewrites need a match


def test_stopwords_fold_and_terms_skip_them():
    assert TOY.is_stopword("Për")
    assert TOY.terms("Mollët dhe malet për ujë") == ["moll", "mal", "uje"]


def test_json_roundtrip_and_rejects_unfolded_rules():
    assert AlbanianStemmer.from_json(TOY.to_json()).to_json() == TOY.to_json()
    with pytest.raises(ValueError):
        AlbanianStemmer((("ë",),), 3)


EXC = AlbanianStemmer(TOY.steps, TOY.min_stem, TOY.rewrites, TOY.stopwords,
                      exceptions=(("qene", "je"), ("jam", "je"), ("ishte", "je")))


def test_exceptions_come_first_and_fold():
    assert {EXC.stem(w) for w in ("jam", "qenë", "QENE", "ishte")} == {"je"}
    assert EXC.stem("malet") == TOY.stem("malet") == "mal"   # not listed: the rules
    assert EXC.stem("qenët") == TOY.stem("qenët")             # whole words only
    assert AlbanianStemmer.from_json(EXC.to_json()).to_json() == EXC.to_json()
    assert "exceptions" not in TOY.to_json()
    with pytest.raises(ValueError):
        AlbanianStemmer((("i",),), 3, exceptions=(("qenë", "je"),))


def test_committed_rules_merge_irregular_verbs():
    st = default_stemmer()
    for family in ("them thotë thënë thoshte", "mbaj mbajti mbajtur", "jap jep dha dhënë",
                   "marr merr marrë merret", "vij vjen erdhi ardhur"):
        assert len({st.stem(w) for w in family.split()}) == 1, family
    # homographs stay with the rules: tha "dried", parë "first", ditë "day"
    assert st.stem("tha") != st.stem("thotë")
    assert st.stem("parë") != st.stem("pashë") and st.stem("ditë") != st.stem("dinte")


def test_regions_follow_snowball():
    # R1 starts after the first non-vowel that follows a vowel; R2 likewise inside R1.
    assert regions("problem") == (4, 7)    # R1 "lem", R2 empty
    assert regions("problemi") == (4, 7)   # R2 "i"
    assert regions("shtepi") == (5, 6)     # R1 "i"
    assert regions("aaa") == (3, 3)        # no consonant: both regions empty
    assert regions("") == (0, 0)


def test_conditions_keep_a_word_whose_letters_look_like_an_ending():
    st = REGIONAL
    assert {st.stem(w) for w in ("problem", "problemi", "problemin")} == {"problem"}
    assert TOY.stem("problemi") == "problem" and AlbanianStemmer(
        REGIONAL.steps, 3).stem("problem") == "probl"  # without regions, -em is stripped
    assert st.stem("malet") == "mal"   # -t lies in R1 ("et"), then -e
    # A region cannot protect a one-syllable word: R1 of "rast" is "t".
    assert st.stem("rast") == "ras" and st.stem("rasti") == "rast"


def test_json_roundtrip_with_conditions_and_rejects_bad_ones():
    assert AlbanianStemmer.from_json(REGIONAL.to_json()).to_json() == REGIONAL.to_json()
    assert "conditions" not in TOY.to_json()
    with pytest.raises(ValueError):
        AlbanianStemmer((("em",),), 3, conditions=((("em", "R3"),),))
    with pytest.raises(ValueError):
        AlbanianStemmer((("em",),), 3, conditions=((("ve", "R1"),),))


def test_preceding_letter_conditions():
    st = PRECEDING
    assert st.stem("mollet") == "moll"     # -t after e, then -e
    assert st.stem("rast") == "rast"       # -t after s stays
    assert st.stem("mjeku") == "mjek"      # -u after k
    assert st.stem("punu") == "punu"       # not after k/g/h
    assert st.stem("drurin") == "drur"     # -in after r
    assert st.stem("malin") == "mal"       # the l before -in may be within min_stem
    assert st.stem("ujet") == "uje"        # likewise the e before -t
    assert st.stem("ujit") == "uji"        # -it would leave 2 letters; -t after i
    assert st.condition(0, "u") == "KGH"
    assert AlbanianStemmer.from_json(st.to_json()).to_json() == st.to_json()
    sb = st.to_snowball()
    assert "AfterKGH" in sb and "test kgh" in sb and "InR1" not in sb and "pr1" not in sb


def test_letters_before_conditions():
    st = AlbanianStemmer(
        steps=(("ra", "oni", "ne", "nte", "jti", "ve", "i", "e"),),
        min_stem=3,
        conditions=((("ra", "E"), ("oni", "NI"), ("ne", "NIO"), ("nte", "NE"), ("jti", "NE"),
                     ("ve", "NOTI")),),
    )
    assert st.stem("gjera") == "gje"           # -ra after ë (folded e)
    assert st.stem("menyra") == "menyra"       # not after y (the r is the stem's)
    assert st.stem("punoni") == "pun"          # -oni after n
    assert st.stem("aksioni") == "aksion"      # not after i: -i instead
    assert st.stem("punojne") == "punoj"       # -ne after j
    assert st.stem("aksione") == "aksion"      # not after io: -e instead
    assert st.stem("punonte") == "puno"        # -nte after o
    assert st.stem("dokumente") == "dokument"  # not after e
    assert st.stem("mbajti") == "mba"          # -jti after a
    assert st.stem("shpejti") == "shpejt"      # not after e
    assert st.stem("shtepive") == "shtepi"     # -ve after i
    assert st.stem("kosove") == "kosov"        # not after o
    assert st.stem("sportive") == "sportiv"    # nor after ti
    assert AlbanianStemmer.from_json(st.to_json()).to_json() == st.to_json()
    sb = st.to_snowball()
    for line in ("define AfterE as ( R1 test 'e' )", "define NotAfterI as ( R1 not 'i' )",
                 "define NotAfterIO as ( R1 not 'io' )", "define NotAfterE as ( R1 not 'e' )",
                 "define NotAfterOTI as ( R1 not among ( 'o' 'ti' ) )"):
        assert line in sb
    assert "setlimit" not in sb.split("define step1")[1].split("define")[0]


def test_snowball_declares_regions_only_when_used():
    assert "InR2" in REGIONAL.to_snowball() and "gopast v gopast non-v" in REGIONAL.to_snowball()
    assert "InR" not in TOY.to_snowball() and "groupings" not in TOY.to_snowball()
