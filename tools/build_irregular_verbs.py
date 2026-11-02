"""Build the irregular-verb exception table (``exceptions`` in the rules file).

Suffix rules cannot merge an irregular verb's forms: *vij*, *erdhi*, *ardhur*;
*them*, *thotë*, *thënë*; *mbaj*, *mbajti*, *mbajtur*. This script lists the
verbs, finds their forms in corpus lexicons, and maps each form to one stem::

    uv run --extra fit python tools/build_irregular_verbs.py \\
        --out data/grammar/irregular_verbs.json \\
        data/lexicons/web-sq-2026-11.tsv.gz

Then pass ``--exceptions data/grammar/irregular_verbs.json`` to the fit.

* **Verbs** (:data:`LEMMAS`): the 15 of the englishforlife.edu.mk table of
  frequent irregular verbs, the stem-changing verbs of the Academy grammar
  (*Gramatika e gjuhës shqipe I*), and every verb Dauti &
  Karapinjalli name in their classification of the ~85 irregular verbs
  (*Përcaktimi i foljeve të parregullta në gjuhën shqipe*, Studime
  Filologjike 1-2/2018), plus a few seen splitting on web text.
* **Forms**: every lexicon word whose standard spelling uniparser reads only
  as one of those verbs; a participle may also be read as an adjective or
  noun of its own (tagged ``deriv``: *thënë*, *dashur*, *bërë*). So a form
  that is also another word (*parë* "first", *jetë* "life", *tha* "dried",
  *ditë* "day") stays with the rules; :data:`HOMOGRAPHS` lists the ones
  uniparser misses. Stanza's lemmas are not used: on web text it gives
  foreign words and names *kam*/*jam*.
* **Stem**: the stem the rules give most of the verb's tokens, unless another
  word already stems to it (*marr* would meet *mirë*, *di* *ditë*); then the
  next, the folded lemma, or the lemma plus ``x``. Only forms the rules stem
  differently go in the table. It is computed with the rules *without* any
  exception table, so rebuild it whenever the endings change.
"""

from __future__ import annotations

import argparse
import collections
import json
import logging
import sys
from pathlib import Path

from albanian_stemmer.lexicon import load_lexicon
from albanian_stemmer.rules import SURFACE_RULES_PATH, AlbanianStemmer
from albanian_stemmer.text import fold

logger = logging.getLogger("build_irregular_verbs")

TABLE = "jam kam shoh them jap marr bëj vij bie ha dal dua rri flas shkoj".split()
BOOK = ("vë heq vdes vete lë dredh vjel shpie pjek zë nxë shtie bërtas humbas nxjerr "
        "fle").split()
PAPER = ("arrij gjej luaj brej huaj bluaj mbaj mbërrij mbroj mbruj shuaj ruaj vërej vlej "
         "fyej zbruaj hyj këllas këlthas pëllas thërras bredh hedh tredh mbledh pjerdh vjedh "
         "ndjek kërcas shes rrëshqas zbres pëlcas gërhas godas buças gërgas dhjes shkas ngas "
         "ngre").split()
EXTRA = "di pi sjell mbjell djeg mjel tjerr vras iki rrah".split()
# pres is left out: it is both "cut" and "wait".
LEMMAS = list(dict.fromkeys(TABLE + BOOK + PAPER + EXTRA))
# uniparser's separate non-active lemma for bëhem (bëhet, bëhen) is bëj's.
ALIAS = {"beh": "bej", "behem": "bej"}
# Folded forms uniparser reads only as one of the verbs but that are mostly
# other words: nouns, names, other verbs, English (checked by hand).
HOMOGRAPHS = frozenset(
    "pare jete pa ra ve vu ik ha hash di dit die pit pish lee lea leave ler pam paj "
    "bejlereve bejleret fjeti fle fleme flinte flini flinim flinin flisja dis des deke pac "
    "mar mer tor qe shtim shtime pre prere preu preni preci prec laj lin marke marsh "
    "marshim mare mol vol vilma ver disi pan pine pin kishe dhen dije pru prure ram rat "
    "flesh kij lei mil mili milen diqka dhje dhjet shka shkat feti ngitja".split())


def build(lexicons: list[str], rules: AlbanianStemmer) -> dict:
    from uniparser_albanian import AlbanianAnalyzer

    st = AlbanianStemmer(rules.steps, rules.min_stem, rules.rewrites, rules.stopwords,
                         rules.conditions)  # without any exception table
    freq: collections.Counter = collections.Counter()
    spellings: dict[str, set[str]] = collections.defaultdict(set)
    spell_freq: collections.Counter = collections.Counter()
    for p in lexicons:
        for e in load_lexicon(p):
            f = fold(e.word)
            freq[f] += e.occurrences
            spellings[f].add(e.word)
            spell_freq[e.word] += e.occurrences
    verbs = {fold(v) for v in LEMMAS}
    # The standard (most frequent) spelling of each folded form: undiacritized
    # spellings get poor analyses.
    standard = {f: max(sorted(ws), key=lambda w: spell_freq[w]) for f, ws in spellings.items()
                if f not in st.stopwords}
    words = sorted(standard.values())
    an = AlbanianAnalyzer()
    readings: dict[str, list[tuple[str, list[str]]]] = {}
    for i in range(0, len(words), 50_000):
        part = words[i: i + 50_000]
        for w, anas in zip(part, an.analyze_words(part)):
            readings[w] = [(ALIAS.get(fold(x.lemma), fold(x.lemma)), (x.gramm or "").split(","))
                           for x in anas if x.lemma]

    def verb_of(w: str) -> str | None:
        rs = readings.get(w, [])
        lemmas = {lem for lem, g in rs if g[0] == "V"}
        if len(lemmas) != 1 or not lemmas <= verbs:
            return None
        (lem,) = lemmas
        ptcp = any(x == lem and "ptcp" in g for x, g in rs)
        if all(g[0] == "V" or (ptcp and x == fold(w) and "deriv" in g) for x, g in rs):
            return lem
        return None

    forms: dict[str, list[str]] = collections.defaultdict(list)
    dropped = []
    for f, w in sorted(standard.items()):
        if not {lem for lem, _ in readings.get(w, [])} & verbs:
            continue
        lem = verb_of(w)
        if lem is None or f in HOMOGRAPHS:
            dropped.append(f"{f} ({'/'.join(sorted({x for x, _ in readings.get(w, [])}))})")
        else:
            forms[lem].append(f)

    family = {f for fs in forms.values() for f in fs}
    outside: collections.Counter = collections.Counter()
    for f in spellings:
        if f not in family:
            outside[st.stem(f)] += freq[f]
    table, moved = {}, {}
    for lem, fs in sorted(forms.items()):
        by_stem: collections.Counter = collections.Counter()
        for f in fs:
            by_stem[st.stem(f)] += freq[f]
        cands = [t for t, _ in by_stem.most_common()] + [lem] + [lem + "x" * k for k in (1, 2, 3)]
        target = next((t for t in cands if not outside[t]), None)
        if target is None:
            raise SystemExit(f"no free stem for {lem}: {[(t, outside[t]) for t in cands]}")
        if target != cands[0]:
            moved[lem] = {"rules_stem": cands[0], "other_tokens": outside[cands[0]],
                          "stem": target}
        table |= {f: target for f in fs if st.stem(f) != target}
    logger.info("%d forms of %d verbs in the table; %d candidate forms left to the rules",
                len(table), len(forms), len(dropped))
    return {"exceptions": dict(sorted(table.items())),
            # corpus tokens per entry: fit --max-exceptions keeps the most frequent
            "tokens": {f: freq[f] for f in sorted(table)},
            # each verb's entries: fit --max-exceptions keeps or drops a verb whole
            "groups": {lem: [f for f in sorted(fs) if f in table] for lem, fs in sorted(forms.items())
                       if any(f in table for f in fs)},
            "forms": {lem: sorted(fs) for lem, fs in sorted(forms.items())},
            "stems_moved_off_other_words": moved,
            "left_to_rules": dropped,
            "verbs": LEMMAS,
            "lexicons": [Path(p).name for p in lexicons]}


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("lexicons", nargs="+", help="corpus lexicons the forms are taken from")
    ap.add_argument("--out", required=True, help="table to write (JSON)")
    ap.add_argument("--rules", default=str(SURFACE_RULES_PATH),
                    help="rules whose stems the table maps to (default: %(default)s)")
    args = ap.parse_args(argv)
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(message)s")
    rules = AlbanianStemmer.from_json(json.loads(Path(args.rules).read_text()))
    out = build(args.lexicons, rules)
    Path(args.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n")
    logger.info("wrote %s", args.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
