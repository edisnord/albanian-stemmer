"""Build the irregular-verb exception table from the verbs' full conjugation tables.

The irregular verbs of the Academy grammar's groups 2 and 3 (and *bëj*) change
their stem through the paradigm (*vij*, *erdhi*, *ardhur*; *marr*, *merr*,
*mora*). Their forms are those of fjalorthi.com's conjugation tables
(data/grammar/fjalorthi.json, see tools/fjalorthi.py) together with the corpus
forms tools/build_irregular_verbs.py found (data/grammar/corpus_verbs.json)::

    uv run --extra fit python tools/build_paradigm_verbs.py \\
        --rules runs/rules/albanian.json --out data/grammar/irregular_verbs.json

``python -m albanian_stemmer.build --tables`` runs it on the committed rules.

* **Forms** stay out of the table when they are another word too: a form of two
  of the verbs, one in build_irregular_verbs.HOMOGRAPHS (*parë*, *tha*), a
  stopword (unless of *jam*/*kam*), or a spelling uniparser also reads as another
  lemma (a participle may be read as its own adjective or noun: *bërë*).
* **Stem**: the one the rules (``--rules``: fitted *without* any exception table)
  give the infinitive-like lemma, unless a word outside the verb already stems to
  it; then the stem of most of the verb's tokens, the folded lemma, or the lemma
  plus ``x``. Only forms the rules stem differently go in the table.
"""

from __future__ import annotations

import argparse
import collections
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import build_irregular_verbs as B  # noqa: E402

from albanian_stemmer.lexicon import load_lexicon  # noqa: E402
from albanian_stemmer.rules import AlbanianStemmer  # noqa: E402
from albanian_stemmer.text import fold  # noqa: E402

GROUP2 = ("jam kam them jap bie dua ha vij shoh rri lë vë zë nxë shpie shtie vete dal flas fle "
          "marr vdes hyj bëj").split()
GROUP3 = ("hedh heq mbledh vjedh dredh bredh sjell mbjell mjel vjel tjerr ndjek pjek djeg nxjerr "
          "shes zbres ngre shkoj shuaj bluaj tredh pjerdh thërras").split()
VERBS = GROUP2 + GROUP3
# uniparser readings that are no real reading of these forms (bini, binte, bija as mbij)
SPURIOUS = {"mbij"}
# fjalorthi's table of bie "fall" also holds bie "bring" (prura, prufsh): left out
OTHER_VERB = {"bie": ("pru",)}


def build(rules: AlbanianStemmer, paradigms: dict, corpus_forms: dict[str, list[str]],
          lexicon: str) -> dict:
    from uniparser_albanian import AlbanianAnalyzer

    st = AlbanianStemmer(rules.steps, rules.min_stem, rules.rewrites, rules.stopwords,
                         rules.conditions)
    freq: collections.Counter = collections.Counter()
    spellings: dict[str, set[str]] = collections.defaultdict(set)
    spell_freq: collections.Counter = collections.Counter()
    for e in load_lexicon(lexicon):
        f = fold(e.word)
        freq[f] += e.occurrences
        spellings[f].add(e.word)
        spell_freq[e.word] += e.occurrences

    cand: dict[str, dict[str, set[str]]] = collections.defaultdict(dict)
    ptcp: dict[str, str] = {}  # its participle: the noun made from it is the same word (bërë)
    for v in VERBS:
        p = paradigms.get(v)
        if p:
            ptcp[fold(v)] = fold(p["participle"])
        for w in (p or {}).get("forms", []):
            if not fold(w).startswith(OTHER_VERB.get(v, ("\0",))):
                cand[v].setdefault(fold(w), set()).add(w)
        for f in corpus_forms.get(fold(v), []):
            cand[v].setdefault(f, set())
    owners = collections.Counter(f for v in VERBS for f in cand[v])
    check: set[str] = set()
    for v in VERBS:  # check each spelling of 10% or more of a form's tokens
        for f, ws in cand[v].items():
            tot = sum(spell_freq[w] for w in spellings[f])
            ws |= {w for w in spellings[f] if tot and spell_freq[w] / tot >= 0.1}
            check |= ws
    words = sorted(check)
    readings = {w: [(B.ALIAS.get(fold(x.lemma), fold(x.lemma)), (x.gramm or "").split(","))
                    for x in anas if x.lemma]
                for w, anas in zip(words, AlbanianAnalyzer().analyze_words(words))}

    def only_verb(w: str, lem: str) -> bool:
        rs = [(x, g) for x, g in readings.get(w, []) if x not in SPURIOUS]
        if not rs:
            return True  # unknown to uniparser: the table's word
        own_ptcp = any(x == lem and "ptcp" in g for x, g in rs)
        return all((x == lem and g[0] == "V") or (own_ptcp and x == fold(w) and "deriv" in g)
                   or x == ptcp.get(lem) for x, g in rs)

    forms: dict[str, list[str]] = {}
    dropped: dict[str, dict[str, str]] = {}
    for v in VERBS:
        lem = fold(v)
        keep = []
        for f, ws in sorted(cand[v].items()):
            why = ("homograph list" if f in B.HOMOGRAPHS else "two verbs" if owners[f] > 1 else
                   "stopword" if f in st.stopwords and lem not in B.AUXILIARIES else
                   next((f"{w}: {sorted({x for x, _ in readings[w]})}" for w in sorted(ws)
                         if not only_verb(w, lem)), None))
            if why:
                dropped.setdefault(lem, {})[f] = why
            else:
                keep.append(f)
        forms[lem] = keep

    family = {f for v in VERBS for f in cand[v]}  # a verb's own forms never block its stem
    outside: collections.Counter = collections.Counter()
    for f in spellings:
        if f not in family:
            outside[st.stem(f)] += freq[f]
    table: dict[str, str] = {}
    groups: dict[str, list[str]] = {}
    for lem, fs in forms.items():
        by = collections.Counter({st.stem(f): 0 for f in fs})
        for f in fs:
            by[st.stem(f)] += freq[f]
        stems = ([st.stem(lem)] + [t for t, _ in by.most_common()] + [lem]
                 + [lem + "x" * k for k in (1, 2, 3)])
        target = next(t for t in stems if not outside[t])
        moved = {f: target for f in fs if st.stem(f) != target}
        table |= moved
        groups[lem] = sorted(moved)
    return {"exceptions": dict(sorted(table.items())),
            "tokens": {f: freq[f] for f in sorted(table)}, "groups": groups, "forms": forms,
            "dropped": dropped, "verbs": VERBS,
            "source": "fjalorthi.com conjugation tables + corpus forms; lexicon "
                      + Path(lexicon).name}


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--rules", required=True, help="rules fitted without exception tables")
    ap.add_argument("--fjalorthi", default="data/grammar/fjalorthi.json")
    ap.add_argument("--corpus-verbs", default="data/grammar/corpus_verbs.json",
                    help="tools/build_irregular_verbs.py's table (its forms are used)")
    ap.add_argument("--lexicon", default="data/lexicons/web-sq-2026-11.tsv.gz")
    ap.add_argument("--out", required=True)
    args = ap.parse_args(argv)
    rules = AlbanianStemmer.from_json(json.loads(Path(args.rules).read_text()))
    paradigms = json.loads(Path(args.fjalorthi).read_text(encoding="utf-8"))["verbs"]
    corpus = json.loads(Path(args.corpus_verbs).read_text(encoding="utf-8"))["forms"]
    out = build(rules, paradigms, corpus, args.lexicon)
    Path(args.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n",
                              encoding="utf-8")
    print(f"{len(out['exceptions'])} forms of {len(out['forms'])} verbs; "
          f"dropped {sum(map(len, out['dropped'].values()))}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
