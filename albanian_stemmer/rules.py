"""Albanian light stemmer and stopword list, as data.

The stemmer folds a word (lowercase, ë→e, ç→c), then runs its ordered
``steps``: each strips the longest of its own endings that leaves at least
``min_stem`` letters (case and person endings first, then plural and thematic
suffixes, as Albanian stacks them: *fermer-ë-ve*, *mal-e-t*). Finally it
rewrites the stem's end by the longest matching alternation
(``j→∅`` so *sëmundjes* and *sëmundje* meet, ``k→q`` so *mik* and its plural
*miq* do). It is light on purpose: endings are inflectional, so derived
words (*punëtor*) keep their own stems — except that a verb in -oj meets the
noun it is made from (*kontrolloj*, *kontroll*) and, with the third step, a
noun of action in -im meets its verb (*përdorimi*, *përdor*): for keyword
search each is one term.

The rules (``snowball/albanian.json``) are the grammar's ending tables,
pruned by :mod:`albanian_stemmer.fit` against a corpus lexicon and the grammar
book, which also writes them as a Snowball program (:meth:`AlbanianStemmer.to_snowball`).
The Snowball compiler turns that into the Python of :mod:`albanian_stemmer.snowball`
and the C of the Postgres extension (``postgres/``), so all stem identically.
"""

from __future__ import annotations

import hashlib
import json
import re
from collections.abc import Mapping
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path

from albanian_stemmer.text import fold, tokenize

# The committed rules and their Snowball program; see albanian_stemmer.snowball.
SURFACE_RULES_PATH = Path(__file__).parent / "snowball" / "albanian.json"
SNOWBALL_PATH = SURFACE_RULES_PATH.with_suffix(".sbl")
# The Postgres extension's sources, in the repository (not the installed package).
POSTGRES_DIR = Path(__file__).parents[1] / "postgres"

_ALPHA = re.compile(r"^[a-z]+$")
VOWELS = frozenset("aeiouy")  # folded: ë → e
REGIONS = ("R1", "R2")
# Conditions on the letter before an ending (as Finnish/Russian/Turkish
# Snowball stemmers test what precedes a suffix): after a vowel, after a
# non-vowel, after k/g/h. The letter itself may be one of the first
# ``min_stem`` letters (mal-in), the ending may not.
# (In the C case anything but a vowel, as Snowball's non-v.)
PRECEDE = {"V": (VOWELS, True), "C": (VOWELS, False), "KGH": (frozenset("kgh"), True)}
# Conditions on the letters before an ending (Snowball: ``test 'e'``,
# ``not 'io'``), each keeping a frequent ending off stems that end like it:
# E   after ë (folded e): -ra/-rat/-rave of plurals like gjëra, ujëra, not the
#     r of mënyra, kultura, natyra;
# NI  not after i, NIO not after io: the verb endings -on…/-n… not on an -ion
#     noun (aksion-i, aksion-e, not aksi-oni, aksio-ne);
# NE  not after e: -jta/-jti/-jte not on an adjective's jt (drejta, shpejti),
#     -nte not on a noun's -ent (dokumente, studente);
# NOTI not after o or ti: -ve not on the v of Kosovë, provë, nor on the
#     adjectives in -iv (sportive, pozitive);
# NS  not after s: -hem (lahem) not on the adjectives in -shëm (rëndësishëm);
# U   after u: -jt of the -ull nouns' plural (artikujt);
# NIZ not after iz: -em not on the -izëm nouns (organizëm);
# NEM not after iz, bl or st: -em not on organizëm, problem, sistem (where it is
#     the word's: mediopassive hapem, falem and aorist folëm keep it);
# VNJE after a vowel but not after je: the genitive -së (shtëpisë), not the së
#     of pjesë, ndjesë, punonjëse;
# OANIO after o or a but not after io: the imperfect -nim (punonim, mbanim), not
#     the -im nouns' n (bashkëpunim, shënim, kombinim, funksionim);
# SHM not after a, e, o, u or y: the rewrite shm → sh of the -shëm adjectives
#     (rëndësishme → rëndësish), not of dëshmi (which would meet desha).
# Each is (strings one of which must precede, strings none of which may, whether
# the letter before must be a vowel).
AFTER = {"E": (("e",), (), False), "NI": ((), ("i",), False), "NIO": ((), ("io",), False),
         "NE": ((), ("e",), False), "NOTI": ((), ("o", "ti"), False),
         "NS": ((), ("s",), False), "U": (("u",), (), False), "NIZ": ((), ("iz",), False),
         "NEM": ((), ("iz", "bl", "st"), False), "VNJE": ((), ("je",), True),
         "OANIO": (("o", "a"), ("io",), False),
         "SHM": ((), ("a", "e", "o", "u", "y"), False)}
# Their routine names in the Snowball program, and the comment each gets there.
AFTER_SNOWBALL = {
    "E": ("AfterE", "-ra: gjëra, not mënyra"),
    "NI": ("NotAfterI", "-oj, -oni: punoni, not aksioni"),
    "NIO": ("NotAfterIO", "-n, -ne, -ni: punojnë, not aksione"),
    "NE": ("NotAfterE", "-nte, -jta: punonte, mbajti, not dokumente, drejta"),
    "NOTI": ("NotAfterOTI", "-ve, not after o or ti: shtëpive, not Kosovë, sportive"),
    "NS": ("NotAfterS", "-hem: lahem, not rëndësishëm"),
    "U": ("AfterU", "-jt: artikujt"),
    "NIZ": ("NotAfterIZ", "-em: hapem, not organizëm"),
    "NEM": ("NotAfterIZBLST", "-em, not after iz, bl or st: hapem, not organizëm, problem, "
                              "sistem"),
    "VNJE": ("AfterVNotJE", "-së, after a vowel but not je: shtëpisë, not pjesë"),
    "OANIO": ("AfterOANotIO", "-nim, after o or a but not io: punonim, not bashkëpunim, "
                              "funksionim"),
    "SHM": ("NotAfterAEOUY", "shm → sh: rëndësishme, not dëshmi"),
}
CONDITIONS = (*REGIONS, *PRECEDE, *AFTER)


def _wrap(head: str, items: list[str], tail: str, width: int = 80) -> list[str]:
    """``head item item … tail``, wrapped at *width*, continuation lines indented."""
    lines, line = [], head
    for it in [*items, tail]:
        if len(line) + 1 + len(it) > width:
            lines.append(line)
            line = "   "
        line += " " + it
    return [*lines, line]


def _letters(strings: tuple[str, ...]) -> str:
    """Snowball for "the letters before the cursor are one of *strings*"."""
    quoted = " ".join(f"'{x}'" for x in strings)
    return quoted if len(strings) == 1 else f"among ( {quoted} )"


def _past_vc(w: str, start: int) -> int:
    """Snowball's ``gopast v gopast non-v``: the position just after the first
    non-vowel that follows a vowel, from *start* (``len(w)`` if none)."""
    i, n = start, len(w)
    while i < n and w[i] not in VOWELS:
        i += 1
    if i >= n:
        return n
    while i < n and w[i] in VOWELS:
        i += 1
    return n if i >= n else i + 1


def regions(w: str) -> tuple[int, int]:
    """Start of R1 and R2 in folded *w*, as Snowball defines them: R1 begins
    after the first non-vowel that follows a vowel, R2 is the same inside R1
    (*problem*: R1 = ``lem``, R2 empty)."""
    r1 = _past_vc(w, 0)
    return r1, _past_vc(w, r1)


@dataclass(frozen=True)
class AlbanianStemmer:
    steps: tuple[tuple[str, ...], ...]
    min_stem: int
    # (x, y) or (x, y, cond): the stem's end x becomes y; cond, one of AFTER's
    # keys, must hold for the letters before x.
    rewrites: tuple[tuple[str, ...], ...] = ()
    stopwords: frozenset[str] = frozenset()
    # Per step: ending → its condition, on top of ``min_stem``: "R1" or "R2",
    # the Snowball region the ending must lie in, or "V", "C", "KGH", the class
    # of the letter before it (see PRECEDE), or one of AFTER's keys ("E", "NI", …), the letters
    # before it (see AFTER). Absent: no condition.
    conditions: tuple[tuple[tuple[str, str], ...], ...] = ()
    # Whole words (folded) → their stem, looked up before any rule: the
    # irregular verbs, whose forms share no stem a suffix rule could reach
    # (vij, erdhi, ardhur; them, thotë, thënë). Like Porter2's exception list.
    exceptions: tuple[tuple[str, str], ...] = ()

    def __post_init__(self) -> None:
        for k, v in self.exceptions:
            if not (_ALPHA.match(k) and _ALPHA.match(v)):
                raise ValueError(f"exceptions must be folded a-z, got {k!r}: {v!r}")
        object.__setattr__(self, "exceptions", tuple(sorted(dict(self.exceptions).items())))
        object.__setattr__(self, "_exceptions", dict(self.exceptions))
        for s in (*(e for step in self.steps for e in step),
                  *(r[0] for r in self.rewrites), *self.stopwords):
            if not _ALPHA.match(s):  # Snowball and C embed them in string literals
                raise ValueError(f"rule strings must be folded a-z, got {s!r}")
        for r in self.rewrites:  # a rewrite may delete (y == "")
            if r[1] and not _ALPHA.match(r[1]):
                raise ValueError(f"rule strings must be folded a-z, got {r[1]!r}")
            if len(r) not in (2, 3) or (len(r) == 3 and r[2] not in AFTER):
                raise ValueError(f"bad rewrite {r!r}")
        conds = [dict(c) for c in self.conditions] + [{}] * (len(self.steps) - len(self.conditions))
        if len(conds) > len(self.steps):
            raise ValueError("more condition tables than steps")
        for step, c in zip(self.steps, conds):
            for e, r in c.items():
                if e not in step or r not in CONDITIONS:
                    raise ValueError(f"bad condition {e!r}: {r!r}")
        # Canonical form: sorted, empty tables dropped from the end.
        canon = [tuple(sorted(c.items())) for c in conds]
        while canon and not canon[-1]:
            canon.pop()
        object.__setattr__(self, "conditions", tuple(canon))
        by_len: list[list[tuple[int, set[str]]]] = []
        for step in self.steps:
            lens: dict[int, set[str]] = {}
            for s in step:
                lens.setdefault(len(s), set()).add(s)
            by_len.append(sorted(lens.items(), reverse=True))
        object.__setattr__(self, "_by_len", by_len)
        object.__setattr__(self, "_conds", conds)
        object.__setattr__(self, "_rewrites", sorted(self.rewrites, key=lambda xy: -len(xy[0])))

    @staticmethod
    def _holds(w: str, start: int, cond: str, lim: dict[str, int]) -> bool:
        if cond in PRECEDE:  # the letter before the ending
            letters, inside = PRECEDE[cond]
            return (w[start - 1] in letters) == inside
        if cond in AFTER:  # the letters before the ending
            must, mustnot, vowel = AFTER[cond]
            stem = w[:start]
            return ((not must or stem.endswith(must)) and not stem.endswith(mustnot or ("\0",))
                    and (not vowel or stem[-1] in VOWELS))
        return start >= lim[cond]

    def condition(self, step: int, ending: str) -> str:
        """The condition on *ending* at *step* ("" for none)."""
        return self._conds[step].get(ending, "")  # type: ignore[attr-defined]

    def stem(self, word: str) -> str:
        w = fold(word)
        exc = self._exceptions.get(w)  # type: ignore[attr-defined]
        if exc is not None:
            return exc
        m = self.min_stem
        if self.conditions:
            r1, r2 = regions(w)
            lim = {"": m, "R1": max(m, r1), "R2": max(m, r2)}
        for step, conds in zip(self._by_len, self._conds):  # type: ignore[attr-defined]
            # The longest ending whose condition holds (Snowball's among falls
            # back to a shorter match when a longer one's routine fails).
            for n, ends in step:
                start = len(w) - n
                if start >= m and w[-n:] in ends and (
                        not conds or self._holds(w, start, conds.get(w[-n:], ""), lim)):
                    w = w[:-n]
                    break
        for x, y, *c in self._rewrites:  # type: ignore[attr-defined]
            if w.endswith(x) and len(w) - len(x) + len(y) >= self.min_stem and (
                    not c or self._holds(w, len(w) - len(x), c[0], {})):
                return w[: len(w) - len(x)] + y
        return w

    def is_stopword(self, word: str) -> bool:
        return fold(word) in self.stopwords

    def terms(self, text: str) -> list[str]:
        """Stems of *text*'s non-stopword tokens, in order (``albanian_terms``)."""
        return [self.stem(t) for t in tokenize(text) if not self.is_stopword(t)]

    # ── serialization ────────────────────────────────────────────────────────

    def fingerprint(self) -> str:
        """Short hash of the rules: an index stemmed by other rules needs a rebuild."""
        blob = json.dumps(self.to_json(), sort_keys=True, ensure_ascii=False)
        return hashlib.sha1(blob.encode()).hexdigest()[:12]

    def to_json(self) -> dict:
        d = {"steps": [sorted(step, key=lambda s: (-len(s), s)) for step in self.steps],
             "min_stem": self.min_stem,
             "rewrites": [list(xy) for xy in self.rewrites],
             "stopwords": sorted(self.stopwords)}
        if self.conditions:  # absent when unused, so older rule files stay byte-identical
            d["conditions"] = [dict(c) for c in self.conditions]
        if self.exceptions:
            d["exceptions"] = dict(self.exceptions)
        return d

    @classmethod
    def from_json(cls, d: dict) -> AlbanianStemmer:
        return cls(steps=tuple(tuple(step) for step in d["steps"]), min_stem=d["min_stem"],
                   rewrites=tuple(tuple(r) for r in d.get("rewrites", [])),
                   stopwords=frozenset(d.get("stopwords", [])),
                   conditions=tuple(tuple(c.items()) for c in d.get("conditions", [])),
                   exceptions=tuple(d.get("exceptions", {}).items()))

    def to_snowball(self, header: str = "", notes: Mapping[str, str] | None = None) -> str:
        """The rules as a Snowball program (https://snowballstem.org), which
        compiles to Python, C, Java, JavaScript and the other Snowball targets.

        Each step is ``setlimit tomark p1 for ([substring]) among (...)``: the
        longest of its endings lying wholly after the first ``min_stem``
        letters, exactly :meth:`stem`'s rule. A rewrite carries the condition
        that keeps its result ``min_stem`` long, so a longer rewrite whose
        condition fails falls back to a shorter one, as in :meth:`stem`.
        A step with letter-before conditions (AfterV...) has no setlimit, so
        the letter before may lie in the first letters; each of its endings
        tests R1 itself instead.
        *notes* (ending → comment) groups each step's endings under comments;
        a ``"step3:im"`` key notes an ending of that step only.
        """
        m = self.min_stem
        used = {r for c in self.conditions for _, r in c}
        regioned = bool(used & set(REGIONS))
        vowels = regioned or bool(used & {"V", "C"}) or any(
            AFTER[a][2] for a in used & set(AFTER))
        cname = {**{r: f"In{r}" for r in REGIONS}, **{p: f"After{p}" for p in PRECEDE},
                 **{a: name for a, (name, _) in AFTER_SNOWBALL.items()}}
        # A rewrite x → y needs the cursor (where x starts) at >= m - len(y).
        need = sorted({m - len(r[1]) for r in self.rewrites if 0 < m - len(r[1]) < m})
        # A rewrite's letter condition carries that length check itself.
        rw_after = {r[2]: m - len(r[1]) for r in self.rewrites if len(r) == 3}
        if set(rw_after) & used:
            raise ValueError("a letter condition is used by both an ending and a rewrite")
        used = used | set(rw_after)
        cond = {k: ("R1" if k == m else f"S{k}") for k in [m, *need]}
        steps = [f"step{i + 1}" for i in range(len(self.steps))]
        regs = [cname[r] for r in CONDITIONS if r in used]
        exc = ["exception"] if self.exceptions else []
        out = [*(f"// {line}".rstrip() for line in header.strip().splitlines()), "",
               *_wrap("routines (", [*["prelude", *exc, "mark_regions"], *cond.values(), *regs,
                                     *steps, *(["stem_end"] if self.rewrites else [])], ")"),
               "",
               "externals ( stem )", "",
               f"integers ( {' '.join(['p1', *(f's{k}' for k in need)])}"
               f"{''.join(f' p{r.lower()}' for r in REGIONS if r in used)} )", "",
               *([f"groupings ( {' '.join(['v'] * vowels + ['kgh'] * ('KGH' in used))} )", ""]
                 if vowels or "KGH" in used else []),
               "stringescapes {}", "",
               "stringdef e\"   '{U+00EB}'  // e diaeresis",
               "stringdef c,   '{U+00E7}'  // c cedilla", "",
               "// Fold the two Albanian diacritics, so that a word typed without them",
               "// (semundjes, molles) stems like its standard spelling.",
               "define prelude as (",
               "    do repeat goto (",
               "        [substring] among ( '{e\"}' (<- 'e') '{c,}' (<- 'c') )",
               "    )",
               ")", "",
               *self._snowball_exceptions(),
               *(["define v 'aeiouy'  // after folding, so e also stands for {e\"}"]
                 if vowels else []),
               *(["define kgh 'kgh'"] if "KGH" in used else []),
               *([""] if vowels or "KGH" in used else []),
               f"// R1 is the region after the first {m} letters: no ending is removed",
               f"// from them, so a stem keeps at least {m} letters.",
               *(["// pr1 and pr2 mark the usual Snowball regions (called R1 and R2 in the",
                  "// rules file): pr1 after the first non-vowel following a vowel, pr2 the",
                  "// same again from pr1. An ending marked InR1 or InR2 must also lie in it."]
                 if regioned else []),
               *(["// An ending marked AfterV, AfterC or AfterKGH must follow a vowel, a",
                  "// non-vowel, or k, g or h, itself outside the first letters."]
                 if used & set(PRECEDE) else []),
               *(["// The other After... and NotAfter... routines test the letters before",
                  "// an ending: it must follow one of them (After), or none (NotAfter).",
                  "// Each keeps a frequent ending off the stems whose own letters end like",
                  "// it; its comment names the ending, a form it takes and one it spares."]
                 if used & set(AFTER) else []),
               "define mark_regions as (",
               "    $p1 = limit",
               f"    do ( hop {m} setmark p1 )",
               *(f"    $s{k} = limit  do ( hop {k} setmark s{k} )" for k in need),
               *([f"    {'  '.join(f'$p{r.lower()} = limit' for r in REGIONS if r in used)}",
                  "    do ( gopast v gopast non-v" + (" setmark pr1" if "R1" in used else "")
                  + ("" if "R2" in used else " )"),
                  *(["         gopast v gopast non-v setmark pr2 )"] if "R2" in used else []),
                  ] if regioned else []),
               ")", "",
               "backwardmode (", "",
               "    define R1 as $p1 <= cursor",
               *(f"    define S{k} as $s{k} <= cursor  // {k} letter{'s' * (k > 1)} precede"
                 f"{'s' * (k == 1)}" for k in need),
               *(f"    define In{r} as ( R1 $p{r.lower()} <= cursor )"
                 for r in REGIONS if r in used),
               *(f"    define After{p} as ( R1 test {g} )" for p, g in
                 (("V", "v"), ("C", "non-v"), ("KGH", "kgh")) if p in used),
               *(line for a, (must, mustnot, vowel) in AFTER.items() if a in used for line in (
                 f"    // {AFTER_SNOWBALL[a][1]}",
                 f"    define {cname[a]} as ( "
                 + (cond.get(rw_after[a], "") if a in rw_after else "R1")
                 + (" test v" if vowel else "") + (f" test {_letters(must)}" if must else "")
                 + (f" not {_letters(mustnot)}" if mustnot else "") + " )"))]
        notes = notes or {}
        order = {c: i for i, c in enumerate(dict.fromkeys(notes.values()))}
        for i, (name, ends) in enumerate(zip(steps, self.steps)):
            groups: dict[str, list[str]] = {}
            for e in sorted(ends, key=lambda s: (len(s), s)):
                groups.setdefault(notes.get(f"{name}:{e}", notes.get(e, "")), []).append(e)
            free = any(self.condition(i, e) in PRECEDE or self.condition(i, e) in AFTER
                       for e in ends)
            out += ["", f"    // The longest ending of {name} in R1, if any, is removed.",
                    f"    define {name} as (",
                    "        [substring] among (" if free else
                    "        setlimit tomark p1 for ([substring]) among ("]
            for comment, group in sorted(groups.items(),
                                         key=lambda kv: order.get(kv[0], len(order))):
                if comment:
                    out.append(f"            // {comment}")
                line = "           "
                for e in group:
                    r = self.condition(i, e)
                    item = f" '{e}'" + (f" {cname[r]}" if r else " R1" if free else "")
                    if len(line) + len(item) > 88:
                        out.append(line)
                        line = "           "
                    line += item
                out.append(line)
            out += ["                (delete)", "        )", "    )"]
        if self.rewrites:
            out += ["", "    // The stem's end, by the longest alternation that leaves it long enough.",
                    "    define stem_end as (", "        [substring] among ("]
            for x, y, *rc in self._rewrites[::-1]:  # type: ignore[attr-defined]
                c = cname[rc[0]] if rc else cond.get(m - len(y), "")
                act = f"<- '{y}'" if y else "delete"
                out.append(f"            '{x}' {c} ({act})".replace("  (", " ("))
            out += ["        )", "    )"]
        body = ["do mark_regions", "backwards (", *(f"    do {s}" for s in steps),
                *(["    do stem_end"] if self.rewrites else []), ")"]
        if self.exceptions:
            body = ["exception or (", *(f"    {line}" for line in body), ")"]
        out += [")", "", "define stem as (", "    do prelude", *(f"    {line}" for line in body),
                ")", ""]
        return "\n".join(out)

    def _snowball_exceptions(self) -> list[str]:
        """The ``exception`` routine: a whole (folded) word found in the table
        is replaced by its stem, and no rule runs (as in Porter2's exception1)."""
        if not self.exceptions:
            return []
        by_stem: dict[str, list[str]] = {}
        for form, st in self.exceptions:
            by_stem.setdefault(st, []).append(form)
        out = ["// Irregular words: their forms share no stem a suffix rule reaches",
               "// (vij, erdhi, ardhur; them, thotë, thënë; dorë, duar), each mapped",
               "// to one stem.",
               "define exception as (", "    [substring] atlimit among ("]
        for st, forms in sorted(by_stem.items()):
            line = "       "
            for f in forms:
                if len(line) + len(f) + 3 > 80:
                    out.append(line)
                    line = "       "
                line += f" '{f}'"
            out += [line, f"            (<- '{st}')"]
        return [*out, "    )", ")", ""]


@lru_cache(maxsize=1)
def default_stemmer() -> AlbanianStemmer:
    """The committed rules (``snowball/albanian.json``)."""
    return AlbanianStemmer.from_json(json.loads(SURFACE_RULES_PATH.read_text()))
