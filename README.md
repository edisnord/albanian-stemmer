# albanian-stemmer

[![build](https://github.com/edisnord/albanian-stemmer/actions/workflows/build.yml/badge.svg)](https://github.com/edisnord/albanian-stemmer/actions/workflows/build.yml)

A light, inflectional stemmer for Albanian. It ships as a Snowball program, as
Python, and as a Postgres text search extension. Its rules are fitted
and scored against a corpus lexicon, and the build is reproducible.

```python
>>> from albanian_stemmer import stem, terms
>>> [stem(w) for w in "mollë molla mollës mollët mollëve molle".split()]
['moll', 'moll', 'moll', 'moll', 'moll', 'moll']
>>> stem("sëmundjeve"), stem("semundjet")          # with or without ë/ç
('semund', 'semund')
>>> stem("kontrolloj"), stem("kontrollit")         # an -oj verb meets its noun
('kontroll', 'kontroll')
>>> stem("përdorimi"), stem("përdorur")            # a noun in -im meets its verb
('perdor', 'perdor')
>>> stem("punëtor")                                 # other derived words keep their own
'punetor'
>>> terms("Sëmundjet e mollës dhe të pemëve")      # stopwords dropped
['semund', 'moll', 'pem']
```

## Install

Python (3.11+):

```bash
pip install git+https://github.com/edisnord/albanian-stemmer@1.0.0
# or the wheel attached to the release:
pip install https://github.com/edisnord/albanian-stemmer/releases/download/1.0.0/albanian_stemmer-1.0.0-py3-none-any.whl
```

Postgres (14–18): each [release](https://github.com/edisnord/albanian-stemmer/releases)
has the extension compiled for Linux x86_64 and aarch64
(`albanian_stemmer-pg<version>-linux-<arch>.tar.gz`, built on Ubuntu 24.04):

```bash
tar xzf albanian_stemmer-pg18-linux-x86_64.tar.gz && cd albanian_stemmer-pg18-linux-x86_64
sudo cp lib/albanian_stemmer.so "$(pg_config --pkglibdir)/"
sudo cp extension/* "$(pg_config --sharedir)/extension/"
psql -c 'CREATE EXTENSION albanian_stemmer'
```

Elsewhere, build it from source ([Postgres](#postgres)). CI
(`.github/workflows/build.yml`) tests, builds both on every push to `main`,
and publishes a release when the version in `pyproject.toml` has no tag yet.

## Why it is useful

1. **Standard tooling has no Albanian stemmer.** Snowball doesn't include
   Albanian, so neither do the libraries built on it (Lucene/Elasticsearch,
   NLTK, PyStemmer), and Postgres has no Albanian text search configuration.
   `albanian_stemmer/snowball/albanian.sbl` is a normal Snowball program. It
   compiles to C, Java, JavaScript, Go, Rust and Python, and is laid out like
   the Romanian stemmer: both languages suffix the definite article and fuse it
   with the case ending.
2. **The rules are measured, not just written down.** The grammar's ending
   tables are pruned against a corpus lexicon. The pruning maximises recall,
   while precision and the grammar book's "derived words stay apart" check
   must stay above fixed floors. The rules are fitted on half the lemmas and
   scored on the other half (see [Results](#results)).
3. **One rule file feeds every runtime, and they stem identically.**
   `albanian.json` is written out as the Snowball program, which compiles to
   the Python package and to the C of a Postgres extension
   ([`postgres/`](#postgres)): `to_tsvector('albanian', …)` works like the
   built-in language configurations.
### What it does not claim (yet)

- **The retrieval evidence comes from generated and translated queries**, not
  from queries written by people (see [Results](#results)).
- **The gold lemmas are machine-made** (Stanza ∪ uniparser). The only human
  check is a 300-family sample labelled by one person
  ([below](#a-human-labelled-sample)).
- **There is no comparison with earlier rule-based Albanian stemmers** from the
  academic literature (e.g. JStem). This is not the first Albanian stemmer;
  as far as we know, it is the first packaged for Snowball and Postgres.
- **It is light by design.** It strips inflection and conflates
  derivations only twice, on purpose: an -oj verb with its noun (*kontrolloj*,
  *kontroll*) and a noun of action in -im with its verb (*përdorim*, *përdor*). Besides
  the stopwords, its word lists are the irregular verbs' forms, which no
  ending reaches, and the forms of frequent nouns the endings split (below).

## Methodology

The stemmer is a Snowball-style suffix stripper whose rules were written down
from a grammar, then pruned and checked against data. In order:

1. **Candidate rules from the grammar.** The initial rules come from the
   Academy grammar, *Gramatika e gjuhës shqipe 1: Morfologjia* (1995)
   ([References](#references)); `data/grammar/book_checks.json` keeps the
   word families and endings read from it. Its ending tables give every
   inflectional ending: a noun's article and case, a verb's person, tense and mood, and the plural
   and stem suffixes in front of them. They are laid out as ordered steps, the
   outer ending first, as Albanian stacks them (*fermer-ë-ve*), with a small
   pool of stem-end alternations (*sëmundj* → *sëmund*, *mik*/*miq*).
2. **Lexicons as a reference.** `build_lexicon` tags a corpus with Stanza in
   context and uniparser per word, keeping each word's lemmas and frequency.
   Two words are counted as the same word when they share a lemma. The rules
   are fitted on a lexicon of formal Albanian from public PDF and DOCX files
   (Common Crawl and Internet Archive; 22k words), and the word lists and the
   general scores use that lexicon merged with a FineWeb-2 one (60k words).
   No document of the retrieval benchmarks below went into either.
3. **Pruning.** `fit` greedily removes or restores one ending, toggles one
   alternation, or gives an ending a condition on the letter before it (vowel,
   non-vowel, or k/g/h), as long as recall improves. Recall is the mean of
   pair recall over word types, over tokens and over the book's paradigms.
   Every move must keep precision over types ≥ 0.80 and over tokens ≥ 0.90,
   and keep ≥ 90% of the book's derivation pairs apart. The fit sees half of
   the lemmas (split by a hash of the lemma); the scores below are on the
   other half. Stems keep at least three letters.
4. **Word lists where endings cannot reach.** Irregular verbs (*jam*, *është*,
   *qenë*) come from published lists of irregular verbs. The frequent nouns
   whose forms the endings split (*problemi*, *duar*) come from a
   Lithuanian-style conflict search over the lexicons. Only forms uniparser
   reads as that word alone are kept. Both tables are cut to the 1,000 entries
   carrying the most tokens, whole words at a time, and are looked up before
   any rule, as in Porter2.
5. **Hand-set additions.** Two sets of endings are added after the fit rather
   than fitted: a noun of action in -im meets its verb (*përdorimi*,
   *përdor*), and the declined participle of an -oj verb loses -uara, -uarit
   and the like whole (*organizuara*, *organizoj*). The lexicon lemmas count
   both as different words, so the fit would never choose them; the
   human-labelled sample and retrieval do.
6. **Validation beyond the lemmas.** A change is kept only if it holds up on
   three checks the fit never sees:
   - BM25 retrieval on 64,590 generated queries over general web text, with a
     sealed set of 1,457 queries used only as a second check;
   - mMARCO, translated MS MARCO;
   - a human-labelled sample of 300 word families.

   Paired per-query differences with standard errors decide what counts as a
   gain. This is how candidates such as length caps, stripping a bare -u or -o,
   and keeping ë in stems were rejected, how -im and -uara were accepted
   against the lemma metrics, and how the fitting lexicon was chosen: rules fitted on
   FineWeb-2 alone, or on FineWeb-2 and the crawl together, scored 0.01–0.02
   MRR@10 lower than rules fitted on the crawl.
7. **One source, several runtimes.** The fitted rules (`albanian.json`) are
   written out as a Snowball program, which compiles to the Python package and
   to the C of the Postgres extension. Tests check that all of them stem the
   same words identically, and the whole build reproduces byte for byte from
   one command.

## Results

Scores from `python -m albanian_stemmer.evaluate` on the two committed
lexicons: `data/lexicons/crawl-sq-2026-11.tsv.gz` (21,906 words, the one the
rules are fitted on) and `data/lexicons/web-sq-2026-11.tsv.gz` (60,182 words,
that one merged with FineWeb-2; see [Data and provenance](#data-and-provenance)).

Two words are *linked* when they share a lemma:

- **Recall (R):** the share of linked pairs that get the same stem.
- **Precision (P):** the share of same-stem pairs that are linked.
- **Types vs tokens:** "types" counts every distinct word once; "tokens"
  weights each pair by the product of the two words' frequencies.
- **Held-out:** lemmas the rules were not fitted on.

| stemmer | lexicon | P types | R types | P tokens | R tokens | stems |
|---|---|---|---|---|---|---|
| **albanian (committed, 1,000 exceptions)** | crawl, held-out | 0.847 | 0.789 | 0.948 | 0.846 | 4,361 |
| | web, held-out | 0.833 | 0.591 | 0.954 | 0.378 | 12,566 |
| | web, all | 0.699 | 0.552 | 0.889 | 0.454 | 21,991 |
| with the full tables (2,188) | web, held-out | 0.842 | 0.615 | 0.954 | 0.379 | 12,268 |
| with 500 exceptions | web, held-out | 0.828 | 0.579 | 0.951 | 0.375 | 12,647 |
| without exceptions | web, held-out | 0.820 | 0.563 | 0.925 | 0.329 | 12,721 |
| without the -im step | web, held-out | 0.878 | 0.590 | 0.971 | 0.378 | 12,722 |
| without the -uara endings | web, held-out | 0.851 | 0.567 | 0.957 | 0.376 | 12,759 |
| no stemming (folding only) | web, all | 1.000 | 0.000 | 1.000 | 0.000 | 54,794 |
| first 4 letters | web, held-out | 0.232 | 0.663 | 0.482 | 0.347 | 7,109 |
| first 5 letters | web, held-out | 0.414 | 0.529 | 0.552 | 0.198 | 10,997 |
| first 6 letters | web, held-out | 0.559 | 0.406 | 0.687 | 0.151 | 14,405 |

Recall on the web lexicon is lower than on the crawl one mostly because web
text carries more irregular verbs, spelling variants and Stanza errors. The
-im step and the -uara endings cost precision here because the lexicon's
lemmas count *përdorim* and *përdor*, or *organizuara* and *organizoj*, as
different words; a human-labelled sample and retrieval both want them
together ([below](#nouns-of-action-in--im)).

Against the grammar book's paradigms and derivations (`data/grammar/book_checks.json`):

| stemmer | paradigm families merged | derivations kept apart |
|---|---|---|
| albanian (committed) | 0.516 | 0.887 |
| with the full tables | 0.521 | 0.890 |
| without exceptions | 0.478 | 0.882 |
| first 4 letters | 0.465 | 0.261 |
| first 6 letters | 0.140 | 0.729 |

Truncating to 4 letters gets similar recall only by merging unrelated words:
token precision 0.48 against 0.96, and only 26% of the book's derivations
kept apart.

**Retrieval.** BM25 (k1 0.9, b 0.4) on 64,590 Gemma-generated queries over
general web text (crawl and FineWeb chunks; each query's source chunk is the
one relevant item; 35k source chunks plus 200k distractors), and on a sealed
set of 1,457 queries over 1,487 chunks plus the same distractors:

| analyzer | MRR@10 | R@10 | sealed MRR@10 |
|---|---|---|---|
| no stemming (folding only) | 0.546 | 0.699 | 0.661 |
| first 5 letters | 0.628 | 0.789 | 0.763 |
| without exceptions | 0.647 | 0.803 | 0.772 |
| without the -im step | 0.650 | 0.806 | 0.781 |
| with 500 exceptions | 0.652 | 0.808 | 0.779 |
| without the -uara endings | 0.653 | 0.809 | 0.782 |
| **albanian (committed)** | **0.654** | **0.810** | **0.783** |
| with the full tables | 0.657 | 0.812 | 0.785 |

The gain holds in every query style (factual, keyword, summary, yes/no) and
for queries typed with and without ë/ç. Of the query words that miss their
source chunk, about three quarters do not occur in it in any form, so a
stemmer cannot reach them. Stems capped at 6–8 letters add at most 0.002
MRR@10.

On Albanian mMARCO (translated MS MARCO; ~503k passages, 3,000 dev queries)
MRR@10 is 0.359 (first 5 letters 0.349, no stemming 0.281, a uniparser
lemmatizer 0.341). On the same queries and passages in English, Porter2
scores 0.499 against 0.477 without stemming.

### The letter before an ending

As in the Finnish, Turkish and Russian Snowball stemmers, an ending can
require a certain letter before it: a vowel (`V`), a non-vowel (`C`) or k, g,
h (`KGH`). So -t comes off *mollët* (after ë) but not *rast*. The letter may
be one of the stem's first three letters (*ujë-t*); the ending may not. The
fit (`--precede`) chooses, per ending, no condition or one of the three; 17
endings have one. On the crawl lexicon (held-out, rules alone) it raises type
recall from 0.681 to 0.722 and token recall from 0.740 to 0.760, with type
precision up (0.846 → 0.856) and token precision about level (0.935 →
0.933). The fit would also lower the minimum stem to 2 when it is free to
(`--fix-min-stem` keeps it at 3), which merges unrelated short words and
costs token recall (0.690).

The Snowball R1/R2 regions (`--regions`) were tried the same way and did less
(type recall 0.704, token recall 0.750), so the fitted steps do not use them;
only the -im step does.

### Irregular verbs

Suffix rules cannot merge *jam*, *është* and *qenë*, or *them*, *thotë* and
*thënë*: the forms share no stem. These verbs are frequent, so on general web
text they carry most of the frequency-weighted pairs a stemmer misses. The
rules therefore look a word up in an exception table first, as the English
Porter2 stemmer does. The full verb table has 628 forms of 62 irregular
verbs (`data/grammar/irregular_verbs.json`, built by
`tools/build_irregular_verbs.py`). On the web lexicon, all words:

| | P types | R types | P tokens | R tokens |
|---|---|---|---|---|
| without exceptions | 0.679 | 0.524 | 0.841 | 0.359 |
| full verb table | 0.695 | 0.544 | 0.873 | 0.421 |
| full verb and noun tables (below) | 0.712 | 0.575 | 0.890 | 0.455 |
| **committed: 1,000 entries of both** | 0.699 | 0.552 | 0.889 | 0.454 |

Precision rises too: each verb gets a stem of its own, where its forms used
to share stems with unrelated words. A form that is also another word stays
with the rules (*parë* "seen"/"first", *tha* "said"/"dried", *jetë*
"be"/"life"). The forms come from the lexicon these scores use, so the gain is
an upper estimate; retrieval and the human-labelled sample below do not share
that bias.

### Frequent nouns

The endings split some frequent nouns: *problem*, *problemin* get `problem`
but *problemi* `probl`; *pjesë* `pje` but *pjesa* `pjes`; and no ending joins
*dorë* to *duar* or *grua* to *gra*. As the Lithuanian Snowball stemmer's
`fix_conflicts` does for its suffix conflicts, a second table maps such forms
to the stem most of their paradigm's forms get: 1,560 forms of 942 nouns
(`data/grammar/noun_conflicts.json`, built by `tools/build_noun_conflicts.py`).
Only nouns with at least 200 tokens are listed, and only forms that
uniparser reads as that noun and nothing else. With the full verb table in
place, adding the full noun table raises MRR@10 on the generated queries from
0.647 to 0.657.

### 1,000 exceptions, not 2,188

The tables are long-tailed: the 1,000 entries kept carry 90% of the corpus
tokens of all 2,188, and nearly all of their gain in token precision and
recall on web text. The committed rules keep 1,000 (`fit --max-exceptions
1000`), two to three times the word lists of the Greek and Ukrainian Snowball
stemmers (Estonian has 344 irregular verb forms, Porter2 23); the generated C
is 170 KB. They are kept whole words at a time, by tokens per entry: a verb
with only some forms listed would map them to a stem the rest no longer reach
(*shitur* to `shes`, but *shes* to `she`). That keeps 34 verbs (*jam, kam,
bëj, them, jap, marr, sjell, nxjerr, ...*) and 316 nouns. An earlier cut at
500 entries (18 verbs, 142 nouns) scored 0.0025 MRR@10 lower on the Gemma
queries (± 0.0003) and 0.024 lower in type recall on the human-labelled
sample: most of the forms that sample found split were irregular verbs left
out of the cut (*sjella*/*solli*, *nxirret*/*nxori*). For an index
where size does not matter, fit without `--max-exceptions` to keep both full
tables.

### Nouns of action in -im

Albanian makes nouns of action from verbs with -im: *përdor* → *përdorim*,
*kultivoj* → *kultivim*, *bashkëpunoj* → *bashkëpunim*. A third step
(`fit --derivational`), fixed rather than fitted, strips -im once step 1 has
taken the article (*përdorimi*), and only in R2, so short words keep it
(*trim*, *klim*, *sjellim*). The fit would never choose it, since the
lexicons' lemmas count noun and verb apart, which is where the precision
above drops. But the human-labelled sample (below) counts them as one word, and
retrieval agrees: +0.004 MRR@10 on the Gemma queries and +0.002 on the sealed
set. Stripping a bare -u after a consonant (*ndryshua*, *drejtues*) or -o
(*punoja*) was tried the same way: the sample favoured them slightly, but
retrieval did not move and -u merges unrelated words (*tregues* "indicator"
with *treg* "market"), so they are left out.

### Declined participles in -uara

Step 1 holds the -oj verbs' participle *punuar*, but not its declined forms:
*organizuara* lost only -ra and -a and kept a stem, `organizu`, apart from
*organizoj* and *organizuar* (`organiz`); likewise the non-active aorist *u
punua* and Gheg *punue*. The misses in the human-labelled sample pointed to
it: -uara, -uarat, -uarave, -uare, -uaresh, -uari, -uarin, -uarit, -uarve,
-ua, -ue and -uem are added to step 1 after the fit (`fit --participles`),
taken off whole. Offered to the fit as candidates they are all kept too, but
the greedy search then takes a different path elsewhere and loses type
precision, so they are added rather than fitted. They raise type recall on
the sample from 0.717 to 0.749 and MRR@10 by 0.0007 ± 0.0002 on the Gemma
queries (sealed +0.0007 ± 0.0017). The lexicon precision drops (above), as
for -im, mostly because Stanza lemmatizes a participle as an adjective of its
own.

With the step, a bare noun and its inflected forms can get different stems
(*bashkëpunim* loses -nim in step 1, *bashkëpunimi* only -im), so the noun
table now joins a paradigm on the stem most of its forms get, not the one with
most tokens (`build_noun_conflicts.py --target-by forms`, the default): that
keeps *bashkëpunimi* with *bashkëpunojmë* and makes the table smaller.

### A human-labelled sample

300 word families from the FineWeb lexicon (3,208 forms proposed by the
stemmer, the lexicon's lemmas and uniparser) were labelled by hand: each form
as the same word as the family's head, a related but different word, or
unrelated. Pairs within a family, scored per pair of forms (by tokens:
weighted by the two forms' frequencies):

| analyzer | R types | P types | related words merged | R tokens | P tokens |
|---|---|---|---|---|---|
| **albanian (committed)** | 0.749 | 0.907 | 0.462 | 0.630 | 0.913 |
| with the full tables | 0.754 | 0.909 | 0.427 | 0.630 | 0.913 |
| with 500 exceptions | 0.725 | 0.904 | 0.462 | 0.619 | 0.911 |
| without exceptions | 0.668 | 0.897 | 0.495 | 0.389 | 0.865 |
| without the -im step | 0.742 | 0.907 | 0.462 | 0.630 | 0.913 |
| without the -uara endings | 0.717 | 0.906 | 0.459 | 0.629 | 0.912 |
| first 5 letters | 0.521 | 0.975 | 0.129 | 0.161 | 0.980 |
| uniparser lemma | 0.567 | 0.974 | 0.110 | 0.506 | 0.977 |
| uniparser lemma, ë removed | 0.359 | 0.969 | 0.129 | 0.315 | 0.969 |

The forms were proposed by the analyzers themselves, so recall is measured
only over what one of them already linked. Most remaining misses need the
exception tables, not endings: *tha*/*thotë*, *dua*/*duhet*, *njeri*/*njerëz*,
*madh*/*mëdha*. Most false merges are homographs once ë is folded (*para*
"money" with *parë* "first", *paqe* "peace" with *pak* "little").

Folding ë is deliberate: of the tokens of words spelled with ë or ç, 4.5% are
written without them in the FineWeb-2 sample and 12.7% in the crawl, and
probably more in typed queries. The same rules with ë kept in the stem gain a
little precision on the sample (0.913 against 0.902) but lose 0.049 MRR@10 on
the Gemma queries and 0.033 on the sealed set, and uniparser loses a third of
its recall when ë is missing.

## How it is built

```
raw text ──build_lexicon──▶ lexicon.tsv.gz ──fit──▶ albanian.json ─┬─▶ albanian.sbl ──snowball─┬─▶ albanian_stemmer.py (Python package)
 (Stanza in context +        (word, lemmas,         (endings,       │                         └─▶ postgres/stem_UTF_8_albanian.c (extension)
  uniparser per word)         counts, POS)           rewrites,       └─▶ AlbanianStemmer (Python)
                                                     stopwords,
                                                     exceptions)
grammar book ──tools/extract_grammar_inflection.py──▶ inflection.json ──tools/book_checks.py──▶ book_checks.json (word families, endings) ──▶ fit / evaluate
verb lists + lexicons ──tools/build_irregular_verbs.py──▶ irregular_verbs.json ──▶ fit --exceptions
lexicons + verb table ──tools/build_noun_conflicts.py───▶ noun_conflicts.json ──▶ fit --exceptions
```

- **`albanian_stemmer/rules.py`**: `AlbanianStemmer` holds the rules as data and
  stems with them. `to_snowball()` writes the Snowball program.
- **`albanian_stemmer/snowball/`**: the committed rules (`albanian.json`), their
  Snowball program, and its compiled Python (what `stem()`/`terms()` run).
- **`postgres/`**: the Postgres extension (below). The fit, given the Snowball
  compiler, also writes its `stem_UTF_8_albanian.c`/`.h` and `albanian_stopwords.h`.
- **`albanian_stemmer/fit.py`**: prunes the grammar's ending tables (`--rules
  surface`, the committed rules). It can also prune lemma-oriented tables
  (`hand`) or learn endings from uniparser's segmentations (`learned`).
- **`albanian_stemmer/metrics.py`**: precision and recall against lemmas and
  against the grammar book's families, the held-out split, and the truncation
  baseline.
- **`albanian_stemmer/build_lexicon.py`**: builds a lexicon from raw text.
- **`albanian_stemmer/evaluate.py`**: scores rule sets and the baselines on any
  lexicon.

`python -m albanian_stemmer.fit --min-precision-types 0.80 --book data/grammar/book_checks.json --precede --fix-min-stem --participles --derivational --exceptions data/grammar/irregular_verbs.json data/grammar/noun_conflicts.json --max-exceptions 1000`
rebuilds the committed `albanian.json` byte for byte from the crawl lexicon (the
default `--lexicon`), in about a minute
(add `--snowball /path/to/snowball` to regenerate the Snowball program, its
Python and the extension's C as well). When
the endings change, rebuild the exception tables (their stems are the
rules' stems) in the order fit → verb table → noun table → fit again (the
tables are attached after the search, so the second fit only attaches them),
building both tables from `data/lexicons/web-sq-2026-11.tsv.gz`.

## Postgres

`postgres/` is a PGXS extension: a text search dictionary template around the
C the Snowball compiler generates from `albanian.sbl` (with Snowball's C
runtime in `postgres/runtime/`, BSD-3-Clause), like Postgres's own
`dict_snowball`. It needs the server's development files (`pg_config`, e.g.
the `postgresql-server-dev-18` package) and a server you may install C
extensions on, so not most managed services (Cloud SQL, RDS).

```bash
cd postgres
make && sudo make install          # PG_CONFIG=/path/to/pg_config for another server
make installcheck                  # regression test against the running server
```

```sql
CREATE EXTENSION albanian_stemmer;
SELECT to_tsvector('albanian', 'Sëmundjet e mollës dhe të pemëve');
--  'moll':3 'pem':6 'semund':1
SELECT ts_lexize('albanian_stem', 'përdorimi');    -- {perdor}
CREATE INDEX ON docs USING gin (to_tsvector('albanian', body));
```

The extension creates the dictionary `albanian_stem` (lowercase, drop the
stopwords, stem; `StopWords = false` keeps them) and the configuration
`albanian`, a copy of `simple` that sends words to it. Tokens come from
Postgres's parser, not `albanian_stemmer.tokenize`, so hyphenated words,
numbers and URLs split as in other configurations, but each word gets the
same stem as `albanian_stemmer.stem()`. The extension is trusted, so a
database owner can create it without being a superuser.

Use a UTF-8 database. The dictionary also works in other server encodings
(LATIN1 included), but Postgres's parser only treats ë and ç as letters when
the database's locale says so: in a LATIN1 database with the C locale it splits
*Sëmundjet* into *S* and *mundjet*, for every configuration, `simple` too.
CI builds it for PostgreSQL 14 to 18 and checks each: `make installcheck`
passes, and in a UTF-8 database `ts_lexize` gives Python's stem (or none, for
a stopword) for every test word, also next to the built-in Snowball
dictionaries in the same session.

## Working with a new corpus (e.g. a web crawl)

```bash
uv sync --extra lexicon --extra dev      # Stanza pulls in PyTorch (several GB)

# 1. Lexicon. Two streaming passes: count words (with an Albanian-language
#    filter per line), then Stanza-tag only the lines that give each word up
#    to --contexts-per-word tagged occurrences. The state is kept in
#    <out>.work/, so an interrupted run resumes.
uv run python -m albanian_stemmer.build_lexicon ~/corpora/sq-webcrawl/ \
    --out runs/web/lexicon.tsv.gz --min-count 3 --contexts-per-word 3 --gpu
cat runs/web/lexicon.tsv.gz.work/stats.json

# 2. How do the committed rules hold up on the new text?
uv run python -m albanian_stemmer.evaluate --lexicon runs/web/lexicon.tsv.gz \
    --book data/grammar/book_checks.json --report runs/web/eval-committed.json

# 3. Refit on the new lexicon, written to a run directory.
uv run python -m albanian_stemmer.fit --lexicon runs/web/lexicon.tsv.gz \
    --min-precision-types 0.80 --book data/grammar/book_checks.json \
    --max-words 200000 --out runs/web

# 4. Compare old and new rules on both corpora.
for lex in runs/web/lexicon.tsv.gz data/lexicons/web-sq-2026-11.tsv.gz; do
  uv run python -m albanian_stemmer.evaluate --lexicon $lex --book data/grammar/book_checks.json \
      --rules albanian_stemmer/snowball/albanian.json runs/web/albanian.json
done
```

Notes for large corpora:

- **Input formats.** Plain text (one unit per line) or JSON lines
  (`--text-field`), optionally `.gz`/`.bz2`/`.xz`/`.zst`. Directories are read
  recursively.
- **The language filter** keeps a line when it has at least 5 tokens, at least
  10% are common Albanian function words, and one of them is a word other
  nearby languages don't use (`dhe`, `një`, `që`, `nga`, `është`, …). Tune it
  with `--min-tokens` and `--min-marker-share`.
- **Pass 1 memory.** Counting holds every distinct word in memory. A crawl with
  tens of millions of distinct strings needs several GB of RAM.
- **Stanza is the slow part.** Use `--gpu`, and cap it with `--max-tagged-chars`;
  a rerun with a larger cap continues where it stopped. `--tagger none` skips
  Stanza: you get uniparser lemmas only and no stopword candidates, so the
  scores get noisier.
- **Fitting speed.** Every candidate change re-stems every word, so
  `fit --max-words` limits fitting to the most frequent words. `evaluate`
  scores all of them.

To adopt new rules, fit without `--out`; that overwrites `albanian.json` and
`albanian.sbl`. Then pass `--snowball /path/to/snowball` (the compiler from
github.com/snowballstem/snowball) to regenerate `albanian_stemmer.py`, and run
`pytest`. `test_snowball.py` checks that the program, its compiled Python and
the rules agree on more than 5,000 probe words.

## Lexicon format

```
word<TAB>lemma|lemma…<TAB>occurrences<TAB>function_occurrences[<TAB>tagged]
```

Words are lowercased and keep their diacritics. `tagged` is how many
occurrences Stanza tagged, and `function_occurrences` is how many of those were
function words (ADP, AUX, CCONJ, DET, PART, PRON, SCONJ, PUNCT, SYM). A missing `tagged`
column means every occurrence was tagged. See `albanian_stemmer/lexicon.py`.

## Data and provenance

- **`data/lexicons/crawl-sq-2026-11.tsv.gz`** (the fitting lexicon). Built
  in November 2026 with `build_lexicon --min-count 16` from 83,196 text chunks
  of public Albanian PDF and DOCX files found through Common Crawl and the
  Internet Archive (government decisions, reports, papers), then cleaned with
  `tools/prepare_lexicon.py`. Lemmas come from Stanza ∪ uniparser-albanian.
- **`data/lexicons/web-sq-2026-11.tsv.gz`.** That lexicon merged with one built
  the same way from 150,000 FineWeb-2 Albanian chunks (ODC-By). Used for the
  exception tables and the general scores.
- Neither lexicon contains text from the documents of the retrieval
  benchmarks (the generated-query pool, its distractors, or the sealed set).
- **`data/grammar/book_checks.json`.** Word lists from the Academy grammar
  ([References](#references)): 975 families of inflected forms that should
  share a stem (the book's paradigms and the examples of its inflectional
  endings and alternations), 652 derivation pairs that should not, and 159
  inflectional endings. The paradigms were read page by page by
  `tools/extract_grammar_inflection.py` (an LLM with OCR hints; some readings
  are wrong) and reduced to these lists by `tools/book_checks.py`. The book's
  text and tables are not in the repository; the inflected forms of Albanian
  words are not the book's own.
- **`data/grammar/irregular_verbs.json`.** The exception table: each form of
  an irregular verb and its stem, plus the forms left to the rules and why.
  The verbs are those of the englishforlife.edu.mk table of frequent
  irregular verbs, the Academy grammar's stem-changing verbs, and those named by
  L. Dauti and M. Karapinjalli, *Përcaktimi i foljeve të parregullta në
  gjuhën shqipe*, Studime Filologjike 1-2/2018 (who count about 85). The
  forms come from the web lexicon, judged by uniparser-albanian. Rebuild it
  when the endings change: its stems are the rules' stems.
- **`data/grammar/noun_conflicts.json`.** The second exception table: forms of
  frequent nouns mapped to their paradigm's stem, with each noun's moved
  forms and the nouns skipped because their stem mostly belongs to other
  words. Built from the web lexicon, judged by uniparser-albanian.

## Roadmap

- **A larger fitting lexicon.** The crawl lexicon has 22k words; rules fitted
  on noisier web text did worse, so more formal text would be the way to grow it.
- **A second annotator** for the human-labelled sample, and more dialectal and
  non-standard spellings in it.
- **Baselines from the literature** (earlier rule-based Albanian stemmers) and
  a lemmatizer upper bound.
- **A retrieval evaluation on queries written by people**, not generated from
  the passages they should retrieve.
- **Submit to Snowball upstream.** That needs `albanian.sbl`, a test vocabulary
  with expected stems (`voc.txt`/`output.txt`), and a description page.

## Tests

```bash
uv sync --extra fit --extra dev
uv run pytest
# The extension's stemming is compiled with gcc and checked against Python
# without Postgres. To check it in a server too, install it there first:
ALBANIAN_STEMMER_TEST_DSN=postgresql://… uv run pytest tests/test_postgres_c.py
```

## References

- Akademia e Shkencave e Shqipërisë, Instituti i Gjuhësisë dhe i Letërsisë.
  *Gramatika e gjuhës shqipe 1: Morfologjia*. Tiranë: Akademia e Shkencave,
  1995. The initial ending tables, alternations and word families (volume 2,
  *Sintaksa*, 2002, was not used).
- L. Dauti and M. Karapinjalli. *Përcaktimi i foljeve të parregullta në gjuhën
  shqipe*. Studime Filologjike 1-2/2018. The irregular verbs.
- M. F. Porter. *Snowball: A language for stemming algorithms*, 2001; and the
  Snowball stemmers for Romanian (the layout), Finnish, Turkish and Russian
  (letter conditions), Lithuanian (`fix_conflicts`, the noun table) and
  English Porter2 (the exception table).
- FineWeb-2 (Hugging Face, ODC-By 1.0); Stanza (Apache-2.0);
  uniparser-albanian (MIT).

## License

BSD 3-Clause (`LICENSE`), as Snowball. Dependencies: snowballstemmer
(BSD-3-Clause), uniparser-albanian (MIT), Stanza (Apache-2.0);
`postgres/runtime/` is Snowball's C runtime (BSD-3-Clause,
`postgres/runtime/COPYING`). The lexicons in `data/lexicons/` are word counts;
the FineWeb-2 part is under ODC-By 1.0.
