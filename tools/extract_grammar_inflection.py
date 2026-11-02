#!/usr/bin/env python3
"""Extract inflection data for an Albanian stemmer from the scanned Academy grammar.

Reads *Gramatika e gjuhës shqipe 1: Morfologjia* (Akademia e Shkencave, Tiranë 1995) page by page as images and
asks a vision model to pull out everything a stemmer and stopword list
can use: paradigm tables, inflectional endings and plural-stem suffixes, stem
alternations, irregular words, closed-class word lists (prepositions,
conjunctions, particles, pronoun forms, …), and derivational suffixes (so a
*light* stemmer knows what not to strip).

The scan is two book pages per PDF page. Each spread is split at its gutter
(the emptiest column near the middle) and each book page is sent on its own at
300 dpi, together with:

* the PDF's ABBYY text layer for that half, as a hint — the image is
  authoritative, the hint helps with long runs of text;
* the tail of the previous book page's text layer, so a paradigm table that
  continues across a page break keeps its lemma and column headers.

``--input text`` sends no image: the model gets the text layer and a
Tesseract ``sqi`` OCR of the 300 dpi render side by side and reconciles them.
The two OCRs fail differently (the text layer misreads italic "ft" and splits
letter-spaced footnotes; Tesseract drops some hyphens), and on the paradigm
tables they are usually right where a small local vision model misreads.

Pages are independent given that context, so they run concurrently. Each book
page's result is written to ``<out>/pages/p<NNN><L|R>.json`` as soon as it
arrives; a rerun skips pages already written (``--force`` redoes them), which
is what makes an interrupted run resumable.

``merge`` then folds the page files into one ``inflection.json`` (every item
tagged with the book page it came from; closed-class words and affixes
deduplicated) plus a ``summary.md`` of counts.

Needs poppler (``pdftoppm``, ``pdftotext``, ``pdfinfo``), numpy, pydantic,
httpx, and any OpenAI-compatible chat-completions endpoint with image input
and JSON-schema output: OpenAI itself, or a local server such as llama.cpp's
``llama-server`` or vLLM. The endpoint, key and model come from
``--base-url``/``--model`` or ``$OPENAI_BASE_URL``, ``$OPENAI_API_KEY`` and
``$OPENAI_MODEL``::

    export OPENAI_API_KEY=... OPENAI_MODEL=...      # or OPENAI_BASE_URL=http://localhost:8080/v1
    uv run --with pydantic --with httpx python tools/extract_grammar_inflection.py extract \\
        path/to/gramatika.pdf --out out/gramatika
    uv run --with pydantic --with httpx python tools/extract_grammar_inflection.py extract BOOK.pdf \\
        --out out/gramatika --pages 57-58 --dry-run      # render + hints only
    uv run --with pydantic --with httpx python tools/extract_grammar_inflection.py merge out/gramatika
"""

from __future__ import annotations

import argparse
import json
import logging
import os
import re
import subprocess
import sys
import tempfile
import time
from collections.abc import Iterator
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path
from typing import Literal, TypeVar

import numpy as np
from pydantic import BaseModel, Field

logger = logging.getLogger("extract_grammar_inflection")

_M = TypeVar("_M", bound=BaseModel)

DEFAULT_BASE_URL = os.environ.get("OPENAI_BASE_URL", "https://api.openai.com/v1")
DEFAULT_MODEL = os.environ.get("OPENAI_MODEL")
DPI = 300
CONTEXT_CHARS = 1500


# ─── Output schema (also the model's response schema) ─────────────────────────

POS = Literal[
    "noun", "adjective", "verb", "pronoun", "numeral", "article",
    "adverb", "preposition", "conjunction", "particle", "interjection", "other",
]

FEATURE_TAGS = """\
Feature tags (use only these, as many as apply):
  number: sg, pl
  definiteness: indef, def
  gender: m, f, n
  case: nom, gen, dat, acc, abl, voc
  person: 1, 2, 3
  mood: ind, adm, subj, cond, opt, imp
  tense/aspect: pres, impf, aor, perf, pluperf, aor2, fut, futperf, futpast
  voice: act, nonact
  non-finite: participle, gerund, infinitive, privative, absolutive
  pronoun forms: full, short, merged_clitic
  degree: comparative, superlative"""


# The same tags as an enum, so a grammar-constrained server cannot invent others.
Feature = Literal[
    "sg", "pl", "indef", "def", "m", "f", "n",
    "nom", "gen", "dat", "acc", "abl", "voc", "1", "2", "3",
    "ind", "adm", "subj", "cond", "opt", "imp",
    "pres", "impf", "aor", "perf", "pluperf", "aor2", "fut", "futperf", "futpast",
    "act", "nonact", "participle", "gerund", "infinitive", "privative", "absolutive",
    "full", "short", "merged_clitic", "comparative", "superlative",
]


class Form(BaseModel):
    form: str = Field(description="The word form exactly as printed, keeping the "
                      "book's hyphen between stem and ending (e.g. 'lis-it') and "
                      "any accompanying article/particle (e.g. 'i lis-it', 'të punoj').")
    features: list[Feature] = Field(description="Feature tags from the allowed list.")


class Paradigm(BaseModel):
    section: str = Field(description="Section number the table belongs to, e.g. '3.5.2'.")
    lemma: str = Field(description="Citation form of the ONE word this paradigm "
                       "inflects, e.g. 'ftua', 'punoj'. A table listing several words "
                       "gives one paradigm per word.")
    pos: POS
    inflection_class: str = Field(description="The book's class label, e.g. "
                                  "'lakimi i parë', 'zgjedhimi I, klasa I, nënklasa 1'; "
                                  "empty if none.")
    forms: list[Form]
    continues_from_previous_page: bool = Field(
        description="True if this is the rest of a table begun on the previous page.")
    notes: str = ""


class ExamplePair(BaseModel):
    base: str = Field(description="Base / citation form, e.g. 'lis' or 'punoj'.")
    form: str = Field(description="Inflected or derived form, e.g. 'lisa' or 'punuam'.")


class Affix(BaseModel):
    section: str
    affix: str = Field(description="The affix as printed, with hyphen on the bound "
                       "side: '-it', '-ve', '-ojmë', 'para-'. Variants in parentheses "
                       "as printed, e.g. '-in (-në)'.")
    kind: Literal[
        "case_ending", "plural_stem_suffix", "verb_ending", "adjective_ending",
        "derivational_suffix", "prefix", "article_or_clitic", "other",
    ]
    pos: POS = Field(description="Part of speech the affix attaches to or forms.")
    function: str = Field(description="What it marks or forms, in English, e.g. "
                          "'definite genitive/dative/ablative singular, 1st declension'.")
    features: list[Feature] = Field(description="Feature tags it expresses (empty for "
                                "derivational suffixes).")
    conditions: str = Field(description="Stem shape / class / gender it applies to, as "
                            "stated by the book; empty if unconditioned.")
    examples: list[ExamplePair]


class Alternation(BaseModel):
    section: str
    pattern: str = Field(description="The change, e.g. '-ua → -o', 'a → e (stressed)', "
                         "'-k → -q', 'drop -ë before endings', 'drop e in -ër'.")
    pos: POS
    context: str = Field(description="When it happens (which cases / tenses / plural).")
    examples: list[ExamplePair]


class IrregularWord(BaseModel):
    section: str
    lemma: str
    pos: POS
    forms: list[Form]
    notes: str = ""


class WordList(BaseModel):
    section: str
    category: Literal[
        "preposition", "conjunction", "particle", "personal_pronoun",
        "pronoun_clitic", "demonstrative_pronoun", "possessive_pronoun",
        "interrogative_pronoun", "relative_pronoun", "indefinite_pronoun",
        "reflexive_pronoun", "article", "auxiliary_verb", "pronominal_adverb",
        "numeral", "interjection", "modal_or_other_function_word",
        "inflection_class_members", "other",
    ]
    subcategory: str = Field(description="The book's own grouping, e.g. 'parafjalë të "
                             "parme', 'lidhëza nënrenditëse kohore'; for "
                             "inflection_class_members (words listed as inflecting "
                             "like a pattern, e.g. verbs conjugated like punoj) the "
                             "class or pattern; empty if none.")
    words: list[str] = Field(description="Every member listed on this page, one entry "
                             "per word or multi-word unit, exactly as printed.")


class Rule(BaseModel):
    section: str
    statement: str = Field(description="The morphological rule restated concisely in "
                           "English, specific enough to implement.")
    quote: str = Field(description="Short verbatim Albanian passage it comes from.")
    pos: POS


class PageExtraction(BaseModel):
    printed_page_number: int | None = Field(description="Page number printed on the "
                                            "page, null if none is visible.")
    sections: list[str] = Field(description="Section numbers/headings visible on or "
                                "continuing onto this page, e.g. ['3.5.2 Lakimi i parë'].")
    relevant: bool = Field(description="False if the page has nothing of use for "
                           "stemming or stopwords (syntax, semantics, bibliography, "
                           "front matter); all lists are then empty.")
    paradigms: list[Paradigm]
    affixes: list[Affix]
    alternations: list[Alternation]
    irregular_words: list[IrregularWord]
    word_lists: list[WordList]
    rules: list[Rule]
    uncertain_readings: list[str] = Field(description="Words where the scan was hard "
                                          "to read, each as 'printed → best reading', "
                                          "no explanation.")


_SYSTEM_TEMPLATE = """\
You are extracting data from scanned pages of the Albanian Academy of Sciences \
grammar "Gramatika e gjuhës shqipe I — Morfologjia". The data will be used to \
build a rule-based Albanian stemmer (for keyword search; it strips inflection) and \
a stopword list. You receive ONE book page {source}.

Extract, from this page only:
1. paradigms — every declension/conjugation table or inline paradigm \
(e.g. "E. lis, Gj. i lisi, …"). Give every cell as a form with feature tags. If a \
table continues from the previous page, use the previous-page context to recover \
its lemma and headers and set continues_from_previous_page.
2. affixes — every inflectional ending, plural-stem suffix (-e, -a, -ë, -nj, -ër, \
-enj, -inj, -ra …), verb ending, adjective ending, article/clitic, AND every \
derivational suffix or prefix the page names, with the conditions the book \
states and the examples it gives (base → form).
3. alternations — stem changes in inflection (vowel/consonant changes, dropped \
-ë, -ua→-o, stem extended with -r, plural umlaut like dash/desh, k→q, g→gj, \
ll→j …) with the book's examples.
4. irregular_words — suppletive or irregular nouns, verbs, adjectives with their \
listed forms.
5. word_lists — closed-class members the page lists: prepositions, conjunctions, \
particles, pronoun full and short forms, articles (nyjat), auxiliaries, \
pronominal adverbs, interjections, numerals.
6. rules — any other statement of a morphological regularity that a stemmer \
could implement (e.g. which nouns take which ending, when an ending is dropped).

Rules:
- Transcribe Albanian exactly as printed, with ë and ç. Keep the book's hyphens \
that separate stem and ending. Do not normalize spelling.
- Only extract what is on this page. Never add forms from your own knowledge, even \
when a table is obviously incomplete.
{ocr_rule}
- Ignore discussion of syntax, meaning and usage that states no morphological \
regularity. Pages with none of the above get relevant=false and empty lists.
- Section numbers come from headings like "3.5.2."; if the page has no heading, \
use the section from the previous-page context.
- Record hard-to-read words in uncertain_readings.

{tags}
"""

SYSTEM_PROMPT = _SYSTEM_TEMPLATE.format(
    source="as an image", tags=FEATURE_TAGS,
    ocr_rule="- The OCR text hint is often wrong (ë/e, ç/c, l/i, merged words); the "
             "image wins.")

TEXT_SYSTEM_PROMPT = _SYSTEM_TEMPLATE.format(
    source="as two independent OCR transcriptions of the same scan, both laid out "
           "with spaces so table columns line up", tags=FEATURE_TAGS,
    ocr_rule="""\
- The two OCRs make different mistakes; reconcile them word by word and prefer \
the reading that is real Albanian and consistent with the rest of the table. \
The text layer misreads italic "ft"/"fu" as "fi" (fio-i for fto-i, fiiten for \
futen) and breaks letter-spaced footnotes into fragments ("m bërri-j"). \
Tesseract sometimes drops a stem-ending hyphen ("lisi" for lis-i), reads II as \
TI and -o- as -0-, and leaves stray characters from the page margin at line \
starts; ignore those.""")


# ─── PDF rendering ────────────────────────────────────────────────────────────

@dataclass(frozen=True)
class BookPage:
    pdf_page: int
    side: Literal["L", "R", "S"]          # left/right half of a spread, or single page
    x0: float                              # crop box in PDF points
    width: float
    height: float

    @property
    def key(self) -> str:
        return f"p{self.pdf_page:03d}{self.side}"


def _run(args: list[str]) -> bytes:
    return subprocess.run(args, check=True, capture_output=True).stdout


def _page_size(pdf: Path, page: int) -> tuple[float, float]:
    out = _run(["pdfinfo", "-f", str(page), "-l", str(page), str(pdf)]).decode()
    m = re.search(rf"Page\s+{page} size:\s+([\d.]+) x ([\d.]+)", out)
    if not m:
        raise RuntimeError(f"pdfinfo gave no size for page {page}")
    return float(m.group(1)), float(m.group(2))


def page_count(pdf: Path) -> int:
    out = _run(["pdfinfo", str(pdf)]).decode()
    m = re.search(r"^Pages:\s+(\d+)", out, re.M)
    if not m:
        raise RuntimeError("pdfinfo gave no page count")
    return int(m.group(1))


def _read_pgm(data: bytes) -> np.ndarray:
    # Binary PGM (P5): magic, width, height, maxval, then one byte per pixel.
    fields: list[bytes] = []
    pos = 0
    while len(fields) < 4:
        while data[pos:pos + 1].isspace():
            pos += 1
        if data[pos:pos + 1] == b"#":
            pos = data.index(b"\n", pos) + 1
            continue
        end = pos
        while not data[end:end + 1].isspace():
            end += 1
        fields.append(data[pos:end])
        pos = end
    if fields[0] != b"P5":
        raise ValueError("not a binary PGM")
    w, h = int(fields[1]), int(fields[2])
    return np.frombuffer(data, np.uint8, w * h, pos + 1).reshape(h, w)


def split_spread(pdf: Path, page: int) -> list[BookPage]:
    """The book pages on one PDF page: a landscape spread splits at its gutter."""
    w, h = _page_size(pdf, page)
    if w <= h:
        return [BookPage(page, "S", 0.0, w, h)]
    with tempfile.TemporaryDirectory() as tmp:
        root = Path(tmp) / "low"
        _run(["pdftoppm", "-gray", "-r", "40", "-f", str(page), "-l", str(page),
              "-singlefile", str(pdf), str(root)])
        img = _read_pgm((root.with_suffix(".pgm")).read_bytes())
    ink = (img < 128).sum(axis=0).astype(float)
    ink = np.convolve(ink, np.ones(5) / 5, mode="same")
    lo, hi = int(img.shape[1] * 0.42), int(img.shape[1] * 0.58)
    gutter = (lo + int(np.argmin(ink[lo:hi]))) / img.shape[1] * w
    return [BookPage(page, "L", 0.0, gutter, h),
            BookPage(page, "R", gutter, w - gutter, h)]


def render_png(pdf: Path, bp: BookPage, dpi: int = DPI) -> bytes:
    scale = dpi / 72
    with tempfile.TemporaryDirectory() as tmp:
        root = Path(tmp) / "page"
        _run(["pdftoppm", "-png", "-gray", "-r", str(dpi),
              "-f", str(bp.pdf_page), "-l", str(bp.pdf_page),
              "-x", str(round(bp.x0 * scale)), "-y", "0",
              "-W", str(round(bp.width * scale)), "-H", str(round(bp.height * scale)),
              "-singlefile", str(pdf), str(root)])
        return root.with_suffix(".png").read_bytes()


def tesseract_text(png: bytes) -> str:
    """Tesseract's Albanian OCR of a rendered page, keeping column spacing."""
    out = subprocess.run(
        ["tesseract", "stdin", "stdout", "-l", "sqi", "--psm", "6",
         "-c", "preserve_interword_spaces=1"],
        input=png, check=True, capture_output=True).stdout
    return re.sub(r"\n{3,}", "\n\n", out.decode(errors="replace")).strip()


def text_layer(pdf: Path, bp: BookPage) -> str:
    # pdftotext crops in pixels at -r; at 72 dpi a pixel is a point.
    out = _run(["pdftotext", "-layout", "-r", "72",
                "-f", str(bp.pdf_page), "-l", str(bp.pdf_page),
                "-x", str(round(bp.x0)), "-y", "0",
                "-W", str(round(bp.width)), "-H", str(round(bp.height)),
                str(pdf), "-"])
    return re.sub(r"\n{3,}", "\n\n", out.decode(errors="replace")).strip()


# ─── Model call ───────────────────────────────────────────────────────────────

def _user_prompt(bp: BookPage, hint: str, previous: str,
                 tesseract: str | None = None) -> str:
    """The page prompt; with *tesseract* it is text-only (no image is sent)."""
    parts = [f"Book page: PDF page {bp.pdf_page}, "
             f"{ {'L': 'left', 'R': 'right', 'S': 'single'}[bp.side] } half."]
    if previous:
        parts.append("End of the PREVIOUS book page (OCR text, for context only — do "
                     f"not extract from it):\n<previous>\n{previous}\n</previous>")
    if tesseract is not None:
        parts.append(f"THIS page, PDF text layer OCR:\n<ocr_layer>\n{hint}\n</ocr_layer>")
        parts.append(f"THIS page, Tesseract OCR:\n<ocr_tesseract>\n{tesseract}\n"
                     "</ocr_tesseract>")
        parts.append("Extract the inflection data from this page's OCR text.")
    else:
        if hint:
            parts.append("OCR text layer of THIS page (may contain errors; the image is "
                         f"authoritative):\n<ocr>\n{hint}\n</ocr>")
        parts.append("Extract the inflection data from the page image.")
    return "\n\n".join(parts)


def extract_page(base_url: str, model: str, png: bytes | None, prompt: str, *,
                 timeout: float, thinking: bool | None = None,
                 temperature: float | None = None,
                 schema: type[_M] = PageExtraction,
                 system: str | None = None,
                 retries: int = 2) -> tuple[_M, dict[str, int]]:
    """The page's extraction and the call's token usage (no *png*: text only),
    from an OpenAI-compatible chat-completions endpoint.

    The response schema goes as a ``json_schema`` response format (a local
    server such as llama-server compiles it to a grammar, which constrains
    tokens but never shows the model the field descriptions), so it is also
    spelled out in the system prompt. ``$OPENAI_API_KEY``, if set, is sent as
    the bearer token. *thinking* (Qwen-style ``chat_template_kwargs``) and
    *temperature* are only sent when given, since not every endpoint takes them.
    """
    import base64

    import httpx

    if system is None:
        system = SYSTEM_PROMPT if png else TEXT_SYSTEM_PROMPT
    json_schema = schema.model_json_schema()
    system += ("\n\nAnswer with one JSON object matching this JSON schema (read the "
               "field descriptions):\n"
               + json.dumps(json_schema, ensure_ascii=False, separators=(",", ":")))
    content: list[dict] = [{"type": "text", "text": prompt}]
    if png:
        content.insert(0, {"type": "image_url", "image_url": {
            "url": "data:image/png;base64," + base64.b64encode(png).decode()}})
    body = {
        "model": model,
        "messages": [
            {"role": "system", "content": system},
            {"role": "user", "content": content},
        ],
        "response_format": {"type": "json_schema", "json_schema": {
            "name": schema.__name__, "schema": json_schema}},
    }
    if thinking is not None:
        body["chat_template_kwargs"] = {"enable_thinking": thinking}
    if temperature is not None:
        body["temperature"] = temperature
    key = os.environ.get("OPENAI_API_KEY")
    headers = {"Authorization": f"Bearer {key}"} if key else {}
    url = base_url.rstrip("/") + "/chat/completions"
    for attempt in range(retries + 1):
        try:
            resp = httpx.post(url, json=body, headers=headers, timeout=timeout)
            resp.raise_for_status()
            data = resp.json()
            msg = data["choices"][0]["message"]
            text = msg.get("content") or ""
            # Without a reasoning parser the thinking stays inline in content.
            text = re.sub(r"(?s)^.*?</think>", "", text).strip()
            u = data.get("usage") or {}
            usage = {"input_tokens": u.get("prompt_tokens", 0),
                     "output_tokens": u.get("completion_tokens", 0)}
            return schema.model_validate_json(text), usage
        except (httpx.HTTPError, ValueError, KeyError) as e:
            if attempt == retries:
                raise
            logger.warning("model call failed (%s); retry %d", str(e)[:200], attempt + 1)
            time.sleep(2 ** attempt * 5)
    raise AssertionError("unreachable")


# ─── extract ──────────────────────────────────────────────────────────────────

def _parse_pages(spec: str | None, n: int) -> list[int]:
    if not spec:
        return list(range(1, n + 1))
    pages: set[int] = set()
    for part in spec.split(","):
        a, _, b = part.partition("-")
        pages.update(range(int(a), int(b or a) + 1))
    return sorted(p for p in pages if 1 <= p <= n)


def _book_pages(pdf: Path, pages: list[int]) -> list[BookPage]:
    # Includes the page before the first requested one, so the first requested
    # book page still gets its previous-page context.
    first = pages[0]
    wanted = ([first - 1] if first > 1 else []) + pages
    out: list[BookPage] = []
    for p in wanted:
        out.extend(split_spread(pdf, p))
    return out


def _selected_by_complexity(out_dir: Path, spec: str | None) -> set[str] | None:
    """Book page keys whose ``classify`` rating is in *spec* ("low,medium")."""
    if not spec:
        return None
    wanted = {c.strip() for c in spec.split(",")}
    tsv = out_dir / "complexity.tsv"
    if not tsv.exists():
        raise SystemExit(f"--complexity needs {tsv}; run classify first")
    rows = tsv.read_text().splitlines()
    cols = rows[0].split("\t")
    keys: set[str] = set()
    for line in rows[1:]:
        r = dict(zip(cols, line.split("\t")))
        if r["complexity"] in wanted:
            keys.add(f"p{int(r['pdf_page']):03d}{r['side']}")
    logger.info("%d book pages rated %s", len(keys), "/".join(sorted(wanted)))
    return keys


def cmd_extract(args: argparse.Namespace) -> int:
    pdf = Path(args.pdf).expanduser().resolve()
    out_dir = Path(args.out)
    pages_dir = out_dir / "pages"
    pages_dir.mkdir(parents=True, exist_ok=True)

    pages = _parse_pages(args.pages, page_count(pdf))
    if not pages:
        logger.error("no pages selected")
        return 1
    book_pages = _book_pages(pdf, pages)
    logger.info("%d PDF pages → %d book pages", len(pages),
                sum(bp.pdf_page in set(pages) for bp in book_pages))

    selected = _selected_by_complexity(out_dir, args.complexity)
    hints = {bp.key: text_layer(pdf, bp) for bp in book_pages}
    jobs: list[tuple[BookPage, str]] = []
    done = 0
    prev_key: str | None = None
    for bp in book_pages:
        previous = hints[prev_key][-CONTEXT_CHARS:] if prev_key else ""
        prev_key = bp.key
        if bp.pdf_page not in pages or (selected is not None and bp.key not in selected):
            continue
        if (pages_dir / f"{bp.key}.json").exists() and not args.force:
            done += 1
            continue
        jobs.append((bp, previous))
    logger.info("%d book pages to extract (%d already done)", len(jobs), done)

    text_only = args.input == "text"

    def _page_prompt(bp: BookPage, png: bytes, previous: str) -> str:
        if text_only:
            return _user_prompt(bp, hints[bp.key], previous, tesseract_text(png))
        return _user_prompt(bp, "" if args.no_hint else hints[bp.key], previous)

    if args.dry_run:
        dry = out_dir / "dry-run"
        dry.mkdir(exist_ok=True)
        for bp, previous in jobs:
            png = render_png(pdf, bp)
            (dry / f"{bp.key}.png").write_bytes(png)
            (dry / f"{bp.key}.prompt.txt").write_text(_page_prompt(bp, png, previous))
        logger.info("dry run: images and prompts in %s", dry)
        return 0

    if not args.model:
        sys.exit("name the model: --model or $OPENAI_MODEL")

    def call(png: bytes | None, prompt: str) -> tuple[PageExtraction, dict[str, int]]:
        return extract_page(args.base_url, args.model, png, prompt, timeout=args.timeout,
                            thinking=args.thinking, temperature=args.temperature)

    def work(bp: BookPage, previous: str) -> str:
        png = render_png(pdf, bp)
        prompt = _page_prompt(bp, png, previous)
        t0 = time.monotonic()
        result, usage = call(None if text_only else png, prompt)
        record = {
            "pdf_page": bp.pdf_page, "side": bp.side, "model": args.model,
            "input": args.input,
            "seconds": round(time.monotonic() - t0, 1), "usage": usage,
            **result.model_dump(),
        }
        tmp = pages_dir / f"{bp.key}.json.tmp"
        tmp.write_text(json.dumps(record, ensure_ascii=False, indent=1))
        tmp.replace(pages_dir / f"{bp.key}.json")
        return bp.key

    failed = 0
    with ThreadPoolExecutor(max_workers=args.concurrency) as pool:
        futures = {pool.submit(work, bp, prev): bp for bp, prev in jobs}
        for i, fut in enumerate(as_completed(futures), 1):
            bp = futures[fut]
            try:
                fut.result()
                logger.info("[%d/%d] %s done", i, len(jobs), bp.key)
            except Exception:
                failed += 1
                logger.exception("[%d/%d] %s failed", i, len(jobs), bp.key)
    if failed:
        logger.error("%d pages failed; rerun to retry them", failed)
    return 1 if failed else 0


# ─── classify ─────────────────────────────────────────────────────────────────
# A cheap first pass that routes pages: dense paradigm pages go to the strong
# model, the rest to a local one, and pages with nothing to extract are skipped.

class PageComplexity(BaseModel):
    printed_page_number: int | None
    complexity: Literal["none", "low", "medium", "high"]
    paradigm_tables: int = Field(description="Number of declension/conjugation tables "
                                 "or inline paradigms (E. …, Gj. …, Dh. …) on the page.")
    max_table_columns: int = Field(description="Most columns of word forms in any one "
                                   "table or aligned list; 0 if none.")
    example_forms: int = Field(description="Rough count of italic example word forms "
                               "on the page, including footnotes.")
    word_lists: bool = Field(description="True if the page lists closed-class words "
                             "(prepositions, conjunctions, particles, pronoun forms…).")
    reason: str = Field(description="One short sentence on what the page contains.")


CLASSIFY_PROMPT = """\
You are triaging scanned pages of the Albanian grammar "Gramatika e gjuhës \
shqipe I — Morfologjia" before a detailed extraction of inflection data \
(paradigms, endings, stem alternations, irregular forms, closed-class word lists) \
for building a stemmer. You receive ONE book page. Do not extract anything; \
judge how hard the page would be to extract completely and correctly.

complexity:
- none: nothing morphological — front matter, table of contents, syntax, meaning \
or usage discussion with no stated forms or endings, bibliography.
- low: running prose stating rules, with a handful of inline examples.
- medium: prose with many inline examples or short example pairs (base → form), \
or one simple table, or closed-class word lists.
- high: several paradigm tables, aligned multi-column lists of forms, tables that \
continue from or onto another page, or many forms in footnotes.

Count only what is on the page. Be quick and literal.
"""


def _hyphen_forms(text: str) -> int:
    # Forms printed with the book's stem-ending hyphen ("lis-it", "puno-va");
    # a free text-layer signal to cross-check the model's judgement.
    return len(re.findall(r"\b[^\W\d_]+-[^\W\d_]{1,5}\b", text))


def cmd_classify(args: argparse.Namespace) -> int:
    pdf = Path(args.pdf).expanduser().resolve()
    out_dir = Path(args.out)
    cls_dir = out_dir / "classify"
    cls_dir.mkdir(parents=True, exist_ok=True)

    pages = _parse_pages(args.pages, page_count(pdf))
    book_pages = [bp for p in pages for bp in split_spread(pdf, p)]
    jobs = [bp for bp in book_pages
            if args.force or not (cls_dir / f"{bp.key}.json").exists()]
    logger.info("%d book pages, %d to classify", len(book_pages), len(jobs))

    for i, bp in enumerate(jobs, 1):
        try:
            png = render_png(pdf, bp, dpi=args.dpi)
            t0 = time.monotonic()
            result, usage = extract_page(
                args.base_url, args.model, png, "Classify this page.",
                thinking=False, timeout=args.timeout,
                schema=PageComplexity, system=CLASSIFY_PROMPT)
        except Exception:
            logger.exception("[%d/%d] %s failed", i, len(jobs), bp.key)
            continue
        record = {
            "pdf_page": bp.pdf_page, "side": bp.side, "model": args.model,
            "seconds": round(time.monotonic() - t0, 1), "usage": usage,
            "hyphen_forms": _hyphen_forms(text_layer(pdf, bp)),
            **result.model_dump(),
        }
        tmp = cls_dir / f"{bp.key}.json.tmp"
        tmp.write_text(json.dumps(record, ensure_ascii=False, indent=1))
        tmp.replace(cls_dir / f"{bp.key}.json")
        logger.info("[%d/%d] %s %s (%d tables, %d forms) %.0fs", i, len(jobs), bp.key,
                    result.complexity, result.paradigm_tables, result.example_forms,
                    record["seconds"])

    rows = [json.loads(f.read_text()) for f in sorted(cls_dir.glob("p*.json"))]
    cols = ("pdf_page", "side", "printed_page_number", "complexity", "paradigm_tables",
            "max_table_columns", "example_forms", "hyphen_forms", "word_lists", "reason")
    lines = ["\t".join(cols)]
    lines += ["\t".join(str(r[c]) for c in cols) for r in rows]
    (out_dir / "complexity.tsv").write_text("\n".join(lines) + "\n")
    counts: dict[str, int] = {}
    for r in rows:
        counts[r["complexity"]] = counts.get(r["complexity"], 0) + 1
    logger.info("complexity: %s → %s", counts, out_dir / "complexity.tsv")
    return 0


# ─── merge ────────────────────────────────────────────────────────────────────

def _page_files(pages_dir: Path) -> Iterator[dict]:
    order = {"L": 0, "S": 0, "R": 1}
    files = sorted(pages_dir.glob("p*.json"),
                   key=lambda f: (int(f.stem[1:4]), order[f.stem[4]]))
    for f in files:
        yield json.loads(f.read_text())


def cmd_merge(args: argparse.Namespace) -> int:
    out_dir = Path(args.out)
    lists = ("paradigms", "affixes", "alternations", "irregular_words", "rules",
             "uncertain_readings")
    merged: dict[str, list] = {k: [] for k in lists}
    words: dict[tuple[str, str], dict] = {}
    affix_index: dict[tuple[str, str, str], dict] = {}
    n_pages = n_relevant = 0

    for page in _page_files(out_dir / "pages"):
        n_pages += 1
        n_relevant += bool(page["relevant"])
        ref = {"pdf_page": page["pdf_page"], "side": page["side"],
               "printed_page": page["printed_page_number"]}
        for k in lists:
            for item in page[k]:
                if k == "uncertain_readings":
                    merged[k].append({"reading": item, **ref})
                    continue
                item = {**item, "source": ref}
                if k == "affixes":
                    key = (item["affix"], item["kind"], item["pos"])
                    if key in affix_index:
                        prev = affix_index[key]
                        prev.setdefault("also", []).append(
                            {k2: item[k2] for k2 in ("section", "function", "features",
                                                     "conditions", "examples", "source")})
                        continue
                    affix_index[key] = item
                merged[k].append(item)
        for wl in page["word_lists"]:
            entry = words.setdefault((wl["category"], wl["subcategory"]),
                                     {"category": wl["category"],
                                      "subcategory": wl["subcategory"],
                                      "words": [], "sources": []})
            entry["words"].extend(w for w in wl["words"] if w not in entry["words"])
            entry["sources"].append({**ref, "section": wl["section"]})
    merged["word_lists"] = sorted(words.values(),
                                  key=lambda e: (e["category"], e["subcategory"]))

    (out_dir / "inflection.json").write_text(
        json.dumps(merged, ensure_ascii=False, indent=1))

    by_cat: dict[str, set[str]] = {}
    for wl in merged["word_lists"]:
        by_cat.setdefault(wl["category"], set()).update(wl["words"])
    lines = [
        "# Gramatika inflection extraction", "",
        f"{n_pages} book pages read, {n_relevant} with relevant content.", "",
        "| list | items |", "|---|---|",
        *(f"| {k} | {len(merged[k])} |" for k in (*lists, "word_lists")),
        "", "## Closed-class words by category", "",
        *(f"- **{c}** ({len(ws)}): {', '.join(sorted(ws))}"
          for c, ws in sorted(by_cat.items())),
    ]
    (out_dir / "summary.md").write_text("\n".join(lines) + "\n")
    logger.info("merged %d pages → %s", n_pages, out_dir / "inflection.json")
    return 0


# ─── CLI ──────────────────────────────────────────────────────────────────────

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    ex = sub.add_parser("extract", help="read pages and write pages/*.json")
    ex.add_argument("pdf")
    ex.add_argument("--out", required=True, help="output directory")
    ex.add_argument("--pages", help="PDF pages, e.g. '57-58,138' (default: all)")
    ex.add_argument("--base-url", default=DEFAULT_BASE_URL,
                    help="OpenAI-compatible endpoint (default: $OPENAI_BASE_URL or "
                         "%(default)s), e.g. http://localhost:8080/v1 for llama-server")
    ex.add_argument("--model", default=DEFAULT_MODEL,
                    help="model name, passed as-is (default: $OPENAI_MODEL)")
    ex.add_argument("--thinking", action=argparse.BooleanOptionalAction, default=None,
                    help="llama-server/vLLM with a Qwen-style template: let the model "
                         "think first (default: not sent)")
    ex.add_argument("--temperature", type=float,
                    help="sampling temperature (default: not sent, the endpoint's own)")
    ex.add_argument("--timeout", type=float, default=900,
                    help="seconds per page request")
    ex.add_argument("--concurrency", type=int, default=4)
    ex.add_argument("--force", action="store_true", help="redo pages already extracted")
    ex.add_argument("--complexity",
                    help="only book pages that classify rated so, e.g. 'low,medium' "
                         "(reads <out>/complexity.tsv)")
    ex.add_argument("--input", choices=("image", "text"), default="image",
                    help="send the page image (with the text layer as a hint), or only "
                         "text: the PDF text layer plus Tesseract sqi OCR, no image")
    ex.add_argument("--no-hint", action="store_true",
                    help="don't send the PDF text layer alongside the image")
    ex.add_argument("--dry-run", action="store_true",
                    help="write the page images and prompts, call no model")
    ex.set_defaults(func=cmd_extract)

    mg = sub.add_parser("merge", help="combine pages/*.json into inflection.json")
    mg.add_argument("out", help="the extract --out directory")
    mg.set_defaults(func=cmd_merge)

    cl = sub.add_parser("classify", help="triage pages by extraction difficulty "
                        "with a local model; writes complexity.tsv")
    cl.add_argument("pdf")
    cl.add_argument("--out", required=True, help="output directory")
    cl.add_argument("--pages", help="PDF pages, e.g. '57-58,138' (default: all)")
    cl.add_argument("--base-url", default="http://localhost:8080/v1",
                    help="OpenAI-compatible server (default: local llama-server)")
    cl.add_argument("--model", default="local")
    cl.add_argument("--dpi", type=int, default=150,
                    help="page image resolution; triage needs less than extraction")
    cl.add_argument("--timeout", type=float, default=300)
    cl.add_argument("--force", action="store_true", help="reclassify pages already done")
    cl.set_defaults(func=cmd_classify)

    args = ap.parse_args()
    logging.basicConfig(level=logging.INFO,
                        format="%(asctime)s %(levelname)s %(message)s")
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
