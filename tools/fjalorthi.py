"""The facts the irregular-word tables need from fjalorthi.com, an online Albanian
dictionary: the forms of a verb's conjugation table and the plural a noun's entry
gives. Only those are kept (data/grammar/fjalorthi.json); no definition text.

The site's public JSON API is fetched slowly (one request every --delay seconds;
on HTTP 429 the script waits a quarter of an hour), and each answer is cached::

    uv run python tools/fjalorthi.py --cache runs/fjalorthi \\
        --verbs jam kam them ... --nouns-from nouns.txt --out data/grammar/fjalorthi.json

With every answer cached, it only rebuilds the JSON. The verbs are those of
tools/build_paradigm_verbs.py (``--verbs-from-builder``); the nouns were the
lemmas whose forms the rules still split in the Hunspell noun paradigms.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
import unicodedata
import urllib.error
import urllib.parse
import urllib.request
from pathlib import Path

API = "https://fjalorthi.com/prod/"
# Auxiliaries and particles the conjugation tables print with a form ("kam punuar",
# "do të punoj"); the inflected word is the last one left.
_AUX = frozenset(
    "kam ke ka kemi keni kanë kisha kishe kishte kishim kishit kishin pata pate pat pati patëm "
    "patët patën do të u kem kesh ketë kenë paskam paske paska paskemi paskeni paskan duke për "
    "me pa mos qofsha".split())


def fetch(cache: Path, kind: str, word: str, delay: float) -> dict | list:
    """The API's answer for *word* (kind "conjugateverb" or "define"), from *cache* if there."""
    path = cache / kind / f"{word.replace('/', '_')}.json"
    if path.exists():
        return json.loads(path.read_text(encoding="utf-8"))
    path.parent.mkdir(parents=True, exist_ok=True)
    req = urllib.request.Request(API + kind + "/" + urllib.parse.quote(word),
                                 headers={"User-Agent": "albanian-stemmer"})
    while True:
        try:
            body = urllib.request.urlopen(req, timeout=60).read().decode("utf-8")
            break
        except urllib.error.HTTPError as e:
            if e.code == 404:
                body = "[]"
                break
            if e.code != 429:
                raise
            print(f"429 at {word}: waiting 15 min", file=sys.stderr, flush=True)
            time.sleep(900)
    data = json.loads(body)
    path.write_text(body, encoding="utf-8")
    time.sleep(delay)
    return data


def verb_forms(table: list) -> list[str]:
    """Every form a conjugation table prints, lower-case, auxiliaries dropped."""
    out: set[str] = set()

    def walk(x):
        if isinstance(x, dict):
            for v in x.values():
                walk(v)
        elif isinstance(x, list):
            for v in x:
                walk(v)
        elif isinstance(x, str):
            for alt in re.split(r"[,/]", x):
                ws = [w for w in alt.replace("(", " (").split()
                      if w.strip("()").lower() not in _AUX]
                if not ws:
                    continue
                w = ws[-1].lower()
                if m := re.match(r"^([a-zëç]+)\(([a-zëç]+)\)$", w):  # pat(i): both
                    out.update({m[1], m[1] + m[2]})
                elif re.match(r"^[a-zëç]+$", w):
                    out.add(w)

    for entry in table:
        walk({k: v for k, v in entry.items() if k not in ("VERB", "CAT", "TYPE")})
    return sorted(out)


def _unaccent(s: str) -> str:  # drop the stress marks, keep ë and ç
    return unicodedata.normalize("NFC", "".join(
        c for c in unicodedata.normalize("NFD", s) if c != "́"))


def noun_plurals(entry: dict, word: str) -> list[dict]:
    """The noun readings of *word* in a define answer: each one's spelling and plural
    as the entry writes it ("-e(t)" a suffix, "dúar(t)" in full, stress marks dropped)."""
    out = []
    for x in entry.get("exactMatches") or []:
        if _fold(x["word"]) != _fold(word) or "emër" not in (x.get("wordDefinition") or ""):
            continue
        if m := re.search(r"sh\.\s*([^\s,;]+)", x.get("wordOrig") or ""):
            out.append({"word": x["word"], "plural": _unaccent(m[1])})
    return out


def _fold(s: str) -> str:
    return s.lower().replace("ë", "e").replace("ç", "c")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--cache", required=True, help="directory for the API's answers")
    ap.add_argument("--verbs", nargs="*", default=[])
    ap.add_argument("--verbs-from-builder", action="store_true",
                    help="the verbs of tools/build_paradigm_verbs.py")
    ap.add_argument("--nouns-from", help="file with one noun per line")
    ap.add_argument("--delay", type=float, default=3.0, help="seconds between requests")
    ap.add_argument("--out", required=True)
    args = ap.parse_args(argv)
    cache = Path(args.cache)
    verbs = list(args.verbs)
    if args.verbs_from_builder:
        sys.path.insert(0, str(Path(__file__).parent))
        from build_paradigm_verbs import VERBS
        verbs += VERBS
    nouns = ([w.strip() for w in Path(args.nouns_from).read_text(encoding="utf-8").split()
              if w.strip()] if args.nouns_from else [])
    out: dict = {"source": "fjalorthi.com (conjugation tables and dictionary entries; "
                           "only forms and plurals kept)", "verbs": {}, "nouns": {}}
    for v in dict.fromkeys(verbs):
        table = fetch(cache, "conjugateverb", v, args.delay)
        if table:
            out["verbs"][v] = {"participle": table[0]["PARTICIPLE"].split()[0],
                               "forms": verb_forms(table)}
    for w in dict.fromkeys(nouns):
        if (ps := noun_plurals(fetch(cache, "define", w, args.delay), w)):
            out["nouns"][w] = ps
    Path(args.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n",
                              encoding="utf-8")
    print(f"{len(out['verbs'])} verbs, {len(out['nouns'])} nouns -> {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
