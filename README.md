# albanian-stemmer

[![build](https://github.com/edisnord/albanian-stemmer/actions/workflows/build.yml/badge.svg)](https://github.com/edisnord/albanian-stemmer/actions/workflows/build.yml)

A light, inflectional stemmer for Albanian. It ships as a Snowball program, as
Python, and as a Postgres text search extension. Its rules come from the
grammar, pruned and checked against corpus lexicons, and the build is
reproducible.

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
pip install git+https://github.com/edisnord/albanian-stemmer@1.2.1
# or the wheel attached to the release:
pip install https://github.com/edisnord/albanian-stemmer/releases/download/1.2.1/albanian_stemmer-1.2.1-py3-none-any.whl
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
  the stopwords, its only word lists are the forms no ending can reach: those
  of 48 irregular verbs and 17 nouns with an irregular plural, and *shtet*
  (below). There is no list of words merely to raise a score.

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
4. **Word lists only where endings cannot reach.** The irregular verbs of the
   grammar's groups 2 and 3 (*vij*, *erdhi*, *ardhur*), every form of their
   full conjugation tables, and the 17 nouns whose plural the dictionary
   writes in full (*dorë*/*duar*, *grua*/*gra*); both from fjalorthi.com.
   Only forms uniparser reads as that word alone are kept. They are looked up
   before any rule, as in Porter2.
5. **Hand-set additions.** Some rules are added after the fit rather than
   fitted, each checked by hand and on the benchmarks below: a noun of action
   in -im meets its verb (*përdorimi*, *përdor*); the declined participle
   loses -uara and the like whole (*organizuara*, *organizoj*); the
   -jt- aorist of the vowel + j verbs (*mbajti*); the stressed -i nouns'
   forms (*shtëpia*, *shtëpisë*); conditions on the letters before an ending
   where a word's own letters look like it (*pjesë*, *problem*,
   *bashkëpunim*); and a few stem alternations (*artikull*/*artikuj*,
   *qytet*/*qyteti*). The lexicon lemmas count some of these as different
   words, so the fit would not choose them; the human-labelled sample and
   retrieval do.
6. **Validation beyond the lemmas.** A change is kept only if it holds up on
   three checks the fit never sees:
   - BM25 retrieval on 64,590 generated queries over general web text, with a
     sealed set of 1,457 queries used only as a second check;
   - mMARCO, translated MS MARCO;
   - a human-labelled sample of 300 word families.

   Paired per-query differences with standard errors decide what counts as a
   gain. This is how candidates such as length caps, stripping a bare -u or -o,
   the Hunspell dictionary's extra suffixes, and keeping ë in stems were rejected, how -im and -uara were accepted
   against the lemma metrics, and how the fitting lexicon was chosen: rules fitted on
   FineWeb-2 alone, or on FineWeb-2 and the crawl together, scored 0.01–0.02
   MRR@10 lower than rules fitted on the crawl.
7. **One source, several runtimes.** The rules (`albanian.json`) are
   written out as a Snowball program, which compiles to the Python package and
   to the C of the Postgres extension. Tests check that all of them stem the
   same words identically, and the whole build reproduces byte for byte from
   one command.

Steps 1–5 produced release 1.2.0. The search converged to the same endings on
every run, and most of the rules came from the hand-set additions anyway, so
from 1.2.0 on the rules are frozen: `albanian.json` is edited by hand, a change
is checked with `evaluate` and the step 6 benchmarks, and `fit` is kept as an
analysis tool ([How it is built](#how-it-is-built)). Release 1.2.1 is the first
such edit ([below](#release-121-the--ka-ending)); the tables below are of 1.2.0.

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
| **albanian 1.2.0** | crawl, held-out | 0.828 | 0.798 | 0.913 | 0.848 | 4,266 |
| | web, held-out | 0.818 | 0.606 | 0.931 | 0.393 | 12,182 |
| | web, all | 0.684 | 0.564 | 0.862 | 0.465 | 21,091 |
| release 1.1.0 | crawl, held-out | 0.847 | 0.789 | 0.948 | 0.846 | 4,361 |
| | web, held-out | 0.834 | 0.591 | 0.955 | 0.388 | 12,566 |
| without exceptions | web, held-out | 0.810 | 0.586 | 0.911 | 0.353 | 12,249 |
| without the -im step | web, held-out | 0.864 | 0.605 | 0.951 | 0.392 | 12,337 |
| without the -uara endings | web, held-out | 0.838 | 0.582 | 0.935 | 0.391 | 12,417 |
| no stemming (folding only) | web, all | 1.000 | 0.000 | 1.000 | 0.000 | 54,794 |
| first 4 letters | web, held-out | 0.232 | 0.663 | 0.482 | 0.347 | 7,109 |
| first 5 letters | web, held-out | 0.414 | 0.529 | 0.552 | 0.198 | 10,997 |
| first 6 letters | web, held-out | 0.559 | 0.406 | 0.687 | 0.151 | 14,405 |

Recall on the web lexicon is lower than on the crawl one mostly because web
text carries more irregular verbs, spelling variants and Stanza errors. The
-im step and the -uara endings cost precision here because the lexicon's
lemmas count *përdorim* and *përdor*, or *organizuara* and *organizoj*, as
different words; a human-labelled sample and retrieval both want them
together ([below](#nouns-of-action-in--im)). Against 1.1.0, 1.2.0 trades
some lexicon precision for recall: the letter conditions join noun paradigms
1.1.0's table joined word by word, and the new rewrites join stems the
lexicons' lemmas keep apart (*rëndësishëm*, *rëndësishme*).

Against the grammar book's paradigms and derivations (`data/grammar/book_checks.json`):

| stemmer | paradigm families merged | derivations kept apart |
|---|---|---|
| **albanian 1.2.0** | 0.562 | 0.880 |
| release 1.1.0 | 0.536 | 0.887 |
| without exceptions | 0.484 | 0.877 |
| first 4 letters | 0.465 | 0.261 |
| first 6 letters | 0.140 | 0.729 |

Truncating to 4 letters gets similar recall only by merging unrelated words:
token precision 0.48 against 0.93, and only 26% of the book's derivations
kept apart.

**Retrieval.** BM25 (k1 0.9, b 0.4) on 64,590 Gemma-generated queries over
general web text (crawl and FineWeb chunks; each query's source chunk is the
one relevant item; 35k source chunks plus 200k distractors), and on a sealed
set of 1,457 queries over 1,487 chunks plus the same distractors (these query
sets are not published; mMARCO, below, is the check anyone can rerun):

| analyzer | MRR@10 | R@10 | sealed MRR@10 |
|---|---|---|---|
| no stemming (folding only) | 0.546 | 0.699 | 0.661 |
| first 5 letters | 0.628 | 0.789 | 0.763 |
| without the -im step | 0.649 | 0.804 | 0.778 |
| without exceptions | 0.651 | 0.807 | 0.775 |
| without the -uara endings | 0.651 | 0.807 | 0.779 |
| **albanian 1.2.0** | **0.652** | **0.808** | **0.780** |
| release 1.1.0 | 0.654 | 0.810 | 0.783 |

1.1.0's table of 1,000 frequent forms scored 0.002–0.003 higher here; 1.2.0
gives that up for tables that hold only irregular words
([below](#irregular-plurals)).

The gain holds in every query style (factual, keyword, summary, yes/no) and
for queries typed with and without ë/ç. Of the query words that miss their
source chunk, about three quarters do not occur in it in any form, so a
stemmer cannot reach them. Stems capped at 6–8 letters add at most 0.002
MRR@10.

On Albanian mMARCO (translated MS MARCO; ~503k passages, 3,000 dev queries)
MRR@10 is 0.360 and R@100 0.712 (1.1.0: 0.359 and 0.703; first 5 letters
0.349, no stemming 0.281, a uniparser lemmatizer 0.341). On the same queries and passages in English, Porter2
scores 0.499 against 0.477 without stemming.

### Against embedding models

The same BM25 (k1 0.9, b 0.4, stemmer 1.2.0) against multilingual embedding
models, on four query sets:

- **Gemma queries and sealed:** the generated queries above, here searched
  over the whole corpus of 890,940 chunks (crawl and FineWeb-2), so the scores
  differ from the 200k-distractor table.
- **WebFAQ:** the Albanian part of WebFAQ v2 (30,628 questions searched over
  32,398 answers; [michaeldinzinger/webfaq-v2](https://huggingface.co/datasets/michaeldinzinger/webfaq-v2)).
- **mMARCO:** the 3,000 dev queries over 503,424 passages used above, in
  Albanian and in the English original.

Every model sees at most 512 tokens, with the query and passage prompts from
its model card. Embeddings were computed with vLLM and checked against
sentence-transformers. "Hybrid" fuses arctic and BM25 rankings with reciprocal
rank fusion (k 60). "Reranked" passes each first stage's top 100 to
[bge-reranker-v2-m3](https://huggingface.co/BAAI/bge-reranker-v2-m3), on a
sample of 3,000 queries per set (all 1,457 sealed). MRR@10:

| retriever | Gemma | sealed | WebFAQ | mMARCO | mMARCO, English |
|---|---|---|---|---|---|
| **BM25, albanian stemmer** | 0.666 | 0.654 | 0.667 | 0.360 | 0.499 (Porter2) |
| BM25, no stemming | 0.556 | 0.543 | 0.605 | 0.281 | 0.477 |
| [snowflake-arctic-embed-l-v2.0](https://huggingface.co/Snowflake/snowflake-arctic-embed-l-v2.0) | 0.596 | 0.681 | 0.821 | 0.563 | 0.749 |
| [bge-m3](https://huggingface.co/BAAI/bge-m3) (dense) | 0.577 | 0.664 | 0.812 | 0.528 | 0.696 |
| [multilingual-e5-large](https://huggingface.co/intfloat/multilingual-e5-large) | 0.393 | 0.567 | 0.741 | 0.546 | 0.744 |
| [harrier-oss-v1-0.6b](https://huggingface.co/microsoft/harrier-oss-v1-0.6b) | 0.391 | 0.540 | 0.649 | 0.463 | |
| [harrier-oss-v1-270m](https://huggingface.co/microsoft/harrier-oss-v1-270m) | 0.389 | 0.515 | 0.691 | 0.434 | |
| [Qwen3-Embedding-0.6B](https://huggingface.co/Qwen/Qwen3-Embedding-0.6B) | 0.326 | 0.443 | 0.549 | 0.341 | |
| [multilingual-e5-small](https://huggingface.co/intfloat/multilingual-e5-small) | 0.257 | 0.353 | 0.615 | 0.377 | |
| hybrid, arctic + BM25 | 0.682 | 0.723 | 0.769 | 0.490 | 0.664 |
| BM25 → reranked | 0.780 | 0.810 | 0.865 | 0.557 | |
| arctic → reranked | 0.753 | 0.805 | 0.876 | 0.627 | |

On web text, BM25 with the stemmer beats every embedding model on the Gemma
queries and is within 0.03 MRR@10 of the best on the sealed set. On FineWeb-2
chunks alone, arctic and BM25 are about level; on the crawl chunks, BM25
leads by about 0.09. The generated queries reuse their passage's words, which
favours BM25. People's questions (WebFAQ) and translated queries (mMARCO)
reuse fewer of them, and there the large embedders lead by 0.15–0.20.

A reranker on BM25's top 100 does about as well as one on arctic's on web
text and FAQs, without an embedding index. On mMARCO it is held back by
BM25's recall: the relevant passage is in the top 100 for 72% of queries,
against 89% for arctic.

From English to Albanian mMARCO, the embedders keep 73–76% of their MRR@10,
BM25 with the stemmer 72% and BM25 without stemming 59%. Of the queries English
BM25 answers and Albanian BM25 misses, most differ because the query and
the passage were translated with different words. Splits the stemmer could
fix (*klasë*, *klasës*) account for about a quarter, and the suffix-rule fixes
tried for them changed MRR@10 by under 0.001 ([1.2.1](#release-121-the--ka-ending)).

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

Some endings need more than one letter's class: they test the letters
themselves (`fit --guards`). Each was read off the web lexicon, by counting,
for every word with the ending, whether its lemma is the word itself (the
letters are the word's own) or another word (they are an inflection):

| ending | condition | strips | keeps |
|---|---|---|---|
| -em, -emi | not after iz, bl, st | *hapem*, *falem*, *folëm* | *organizëm*, *problem*, *sistem* |
| -së | after a vowel, not after je | *shtëpisë* | *pjesë*, *ndjesë*, *punonjëse* |
| -nim | after o or a, not after io | *punonim*, *mbanim* | *bashkëpunim*, *shënim*, *funksionim* |
| -nte | not after e | *punonte* | *dokumente* |
| -ve | not after o or ti | *punëve* | *Kosovë*, *sportive* |
| -ra, -rat, -rave | after ë | *gjëra* | *mënyra*, *kultura* |
| -hem | not after s | *punohem* | *rëndësishëm* |

Before -em, -së and -nim the counts are clear: after *bl*, *je* or *u*, under
0.1% of the tokens are inflections. Before -et they are not: the plural and
the non-active -et follow every consonant, and *shtet* "state" has the same
letters before it as *kushtet* (*kusht* + *et*). Two stem rewrites cover the
-itet and -ytet nouns instead, which lose -et only in the bare form
(*aktivitet*, *aktiviteti* → `aktivit`; *qytet*, *qyteti* → `qyt`). For *shtet*
the matching rewrite would give `sht`, the stem of *shtoj* "add", so its bare
form is the one entry of `data/grammar/ambiguous_nouns.json`.

### Irregular verbs

Suffix rules cannot merge *vij*, *erdhi* and *ardhur*, or *them*, *thotë*
and *thënë*: the forms share no stem. These verbs are frequent, so on general web
text they carry most of the frequency-weighted pairs a stemmer misses. The
rules therefore look a word up in an exception table first, as the English
Porter2 stemmer does. The verbs are the irregular ones of the Academy
grammar's groups 2 and 3 (*jam, kam, them, jap, bie, dua, ha, vij, shoh, dal,
flas, marr, vdes, bëj, hedh, heq, sjell, nxjerr, shes, ngre, shkoj, …*: 48),
and their forms are every form of their conjugation tables on fjalorthi.com
(`data/grammar/fjalorthi.json`, fetched by `tools/fjalorthi.py`) plus those
found in the lexicons: 1,606 forms (`data/grammar/irregular_verbs.json`, built
by `tools/build_paradigm_verbs.py`). A form that is also another word stays
with the rules: a form of two of the verbs (*vinte*, of *vij* and *vë*), or
one uniparser also reads as another word (*parë* "seen"/"first", *tha*
"said"/"dried", *jetë* "be"/"life"). On the web lexicon, all words:

| rules | P tokens | R tokens | paradigm families merged |
|---|---|---|---|
| without exceptions | 0.830 | 0.387 | 0.484 |
| with the verb table | 0.860 | 0.463 | 0.558 |
| with the verb and noun tables | 0.862 | 0.465 | 0.562 |

The auxiliaries *jam* "be" and *kam* "have" are mostly stopwords, which
`terms()` and the Postgres dictionary drop before stemming. Their stopword
forms are in the table all the same (*jam*, *është*, *ishte*, *qenë* →
`je`; *kam*, *kishte*, *pasur* → `kisht`), so a search engine that stems
every word still gets one stem per verb; *ka*, *kanë* and *kisha* stay with
the rules, being also "ox", "oxen" and "church". Keeping the stopwords
instead of dropping them changes BM25 retrieval by no more than its noise
(−0.0003 ± 0.0005 MRR@10 on the Gemma queries, +0.004 ± 0.003 on the
sealed set): their low IDF already discounts them, so the list mainly makes
the index smaller. `albanian_stemmer/snowball/stop.txt` is the list in
Snowball's format, each word in its standard spelling and, if that has ë
or ç, also without them.

### Irregular plurals

No ending joins *dorë* to *duar* or *grua* to *gra*. A noun whose plural the
dictionary writes in full (*dorë* … sh. *dúar(t)*), not as a suffix (*mal* …
sh. *-e(t)*), changes its stem in the plural; of the 571 nouns looked up on
fjalorthi.com, 17 do (*njeri, grua, dorë, natë, mashkull, djalë, vëlla, yll,
truall, breg, shtrat, shteg, thua, thes, skllav, derë, kalë*). Their plural
forms (indefinite, definite, -ve, -sh) map to the singular's stem: 50 forms
(`data/grammar/irregular_nouns.json`, built by `tools/build_irregular_nouns.py`),
again only forms uniparser reads as that noun alone.

Release 1.1.0 had instead a table of 1,000 forms of frequent nouns the
endings split (*problemi*, *pjesë*), mapped to their paradigm's stem. It
raised the scores, but it was a list of words the rules got wrong. 1.2.0
drops it: the letter conditions and rewrites above fix those nouns by rule,
and the tables keep only what no rule can reach.

### Nouns of action in -im

Albanian makes nouns of action from verbs with -im: *përdor* → *përdorim*,
*kultivoj* → *kultivim*, *bashkëpunoj* → *bashkëpunim*. A third step
(`fit --derivational`), fixed rather than fitted, strips -im once step 1 has
taken the article (*përdorimi*), and only in R2, so short words keep it
(*trim*, *klim*, *sjellim*). The fit would never choose it, since the
lexicons' lemmas count noun and verb apart, which is where the precision
above drops. But the human-labelled sample (below) counts them as one word, and
retrieval agrees: +0.003 MRR@10 on the Gemma queries and +0.001 on the sealed
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
the sample from 0.729 to 0.760 and MRR@10 by 0.0004 on the Gemma queries
(sealed +0.0002, within noise). The lexicon precision drops (above), as
for -im, mostly because Stanza lemmatizes a participle as an adjective of its
own.

With the step, a bare noun could lose -nim in step 1 (*bashkëpunim* →
`bashkepu`) while its inflected forms lose only -im (*bashkëpunimi* →
`bashkepun`). The imperfect -nim follows only o or a (*punonim*, *mbanim*), so
step 1 now takes it only there, and the noun meets its verb.

### Release 1.2.1: the -ka ending

Most feminine nouns join their definite form (*rrugë*, *rruga*; *punë*, *puna*),
but 1.2.0 took -ka (the admirative, *hapka* "he opens, it turns out") off the
nouns whose root ends in k: *banka* → `ban`, while *bankë*, *bankën*, *bankës*
→ `banq`; likewise *maska*, *marka*, *darka*, *varka*, *Danimarka*. In the web
lexicon such nouns carry 40 times the tokens of any verb form, and the frequent
irregular admiratives (*qenka*, *paska*, *ardhka*, *dashka*) are in the exception
table, so 1.2.1 drops -ka; only the 3rd singular admirative of regular
consonant-stem verbs (*hapka*) loses its verb (-kam, -kan, -kemi, -keni stay).

| | 1.2.0 | 1.2.1 |
|---|---|---|
| web lexicon, held-out: P / R types | 0.818 / 0.606 | 0.819 / 0.606 |
| human-labelled sample: R / P types | 0.760 / 0.908 | 0.761 / 0.909 |
| grammar book families merged | 0.562 | 0.560 (*hapka*) |
| Gemma queries MRR@10 / sealed | 0.6518 / 0.7796 | 0.6522 / 0.7802 |
| mMARCO MRR@10 | 0.3603 | 0.3605 |

Restricting -së to fewer letters was tried too and rejected: with ë folded,
the -esë nouns (*kërkesë*, *kërkesa*) look like the feminine of the -ës and
-as words (*bartëse*, *vendase*) and the genitive of the stressed -a nouns
(*kalasë*), which need it; it cost 1.5 points of type recall on the sample.

### A human-labelled sample

300 word families from the FineWeb lexicon (3,208 forms proposed by the
stemmer, the lexicon's lemmas and uniparser) were labelled by hand: each form
as the same word as the family's head, a related but different word, or
unrelated. Pairs within a family, scored per pair of forms (by tokens:
weighted by the two forms' frequencies):

| analyzer | R types | P types | related words merged | R tokens | P tokens |
|---|---|---|---|---|---|
| **albanian 1.2.0** | 0.760 | 0.908 | 0.403 | 0.681 | 0.918 |
| release 1.1.0 | 0.749 | 0.907 | 0.462 | 0.656 | 0.916 |
| without exceptions | 0.682 | 0.897 | 0.454 | 0.418 | 0.873 |
| without the -im step | 0.754 | 0.907 | 0.403 | 0.681 | 0.917 |
| without the -uara endings | 0.729 | 0.906 | 0.402 | 0.680 | 0.917 |
| first 5 letters | 0.521 | 0.975 | 0.129 | 0.161 | 0.980 |
| uniparser lemma | 0.567 | 0.974 | 0.110 | 0.506 | 0.977 |
| uniparser lemma, ë removed | 0.359 | 0.969 | 0.129 | 0.315 | 0.969 |

The forms were proposed by the analyzers themselves, so recall is measured
only over what one of them already linked. Most remaining misses need the
exception tables, not endings: *tha*/*thotë* (*tha* is also "dried"), *dua*/*duhet*,
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
raw text ──build_lexicon──▶ lexicon.tsv.gz ──fit (to 1.2.0)──▶ albanian.json ──build─┬─▶ albanian.sbl ──snowball─┬─▶ albanian_stemmer.py (Python package)
 (Stanza in context +        (word, lemmas,                       (hand-edited:       │                         └─▶ postgres/stem_UTF_8_albanian.c (extension)
  uniparser per word)         counts, POS)                         endings,           ├─▶ stop.txt
                                                                   conditions,        └─▶ AlbanianStemmer (Python)
                                                                   rewrites,
                                                                   stopwords)
grammar book ──tools/extract_grammar_inflection.py──▶ inflection.json ──tools/book_checks.py──▶ book_checks.json (word families, endings) ──▶ fit / evaluate
fjalorthi.com ──tools/fjalorthi.py──▶ fjalorthi.json (verb forms, noun plurals)
verb lists + lexicons ──tools/build_irregular_verbs.py──▶ corpus_verbs.json (corpus forms)
fjalorthi.json + corpus_verbs.json + rules ──tools/build_paradigm_verbs.py──▶ irregular_verbs.json ──▶ build
fjalorthi.json + rules with verb table ──tools/build_irregular_nouns.py──▶ irregular_nouns.json ──▶ build
ambiguous_nouns.json (by hand) ──▶ build
```

- **`albanian_stemmer/rules.py`**: `AlbanianStemmer` holds the rules as data and
  stems with them. `to_snowball()` writes the Snowball program.
- **`albanian_stemmer/snowball/`**: the rules (`albanian.json`, the source), their
  Snowball program, its stop list (`stop.txt`), and its compiled Python (what
  `stem()`/`terms()` run).
- **`postgres/`**: the Postgres extension (below). `build`, given the Snowball
  compiler, also writes its `stem_UTF_8_albanian.c`/`.h` and `albanian_stopwords.h`.
- **`albanian_stemmer/build.py`**: merges the exception tables into the rules
  and writes the Snowball program, its stop list, the Python and the C.
- **`albanian_stemmer/fit.py`**: the search the rules came from: prunes the
  grammar's ending tables (`--rules surface`), or lemma-oriented tables
  (`hand`), or learns endings from uniparser's segmentations (`learned`).
  It writes to a run directory, never over the committed rules.
- **`albanian_stemmer/metrics.py`**: precision and recall against lemmas and
  against the grammar book's families, the held-out split, and the truncation
  baseline.
- **`albanian_stemmer/build_lexicon.py`**: builds a lexicon from raw text.
- **`albanian_stemmer/evaluate.py`**: scores rule sets and the baselines on any
  lexicon.

`albanian.json` holds the endings of each step, their letter conditions, the
stem rewrites, the minimum stem and the stopwords; edit it by hand. Its
`exceptions` come from the tables in `data/grammar`, so they are not edited
there. To rebuild everything from it:

```bash
python -m albanian_stemmer.build --tables --snowball /path/to/snowball
pytest
```

`--tables` first rebuilds the verb table from the rules alone, then the noun
table from the rules with the verb table, since a table's stems are the rules'
stems; it needs the `fit` extra and a few minutes. Without it the tables are
merged as they are. Without `--snowball` only `albanian.json`, `albanian.sbl`
and `stop.txt` are written. On the committed rules the build reproduces every
generated file, the tables included, byte for byte.

To try a change before adopting it, score a copy:

```bash
python -m albanian_stemmer.evaluate --lexicon data/lexicons/web-sq-2026-11.tsv.gz \
    --book data/grammar/book_checks.json --rules albanian_stemmer/snowball/albanian.json runs/try.json
```

Release 1.2.0's rules came from the fit chain, which `fit` still runs into a
run directory:

```bash
FIT="python -m albanian_stemmer.fit --min-precision-types 0.80 --book data/grammar/book_checks.json \
     --precede --fix-min-stem --participles --derivational --i-nouns --guards --past-jt --alternations"
$FIT --out runs/rules --exceptions data/grammar/irregular_verbs.json \
     data/grammar/irregular_nouns.json data/grammar/ambiguous_nouns.json
```

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

To adopt what a refit suggests, carry the change over to `albanian.json` by
hand, check it on the benchmarks, and rebuild with `python -m
albanian_stemmer.build --tables --snowball /path/to/snowball` (the compiler
from github.com/snowballstem/snowball), then run `pytest`. `test_snowball.py` checks that the program, its compiled Python and
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
- **`data/grammar/fjalorthi.json`.** From fjalorthi.com's public dictionary
  API: the forms of the 48 irregular verbs' conjugation tables, and the plural
  each of 571 nouns' entries gives (as the entry writes it, e.g. `dúar(t)`).
  Only these facts of the language are kept, no definitions or other text.
  `tools/fjalorthi.py` fetches them slowly (one request every 3 s) and caches
  the answers.
- **`data/grammar/corpus_verbs.json`.** The forms of irregular verbs found in
  the web lexicon (`tools/build_irregular_verbs.py`): the verbs of the
  englishforlife.edu.mk table, the Academy grammar's stem-changing verbs, and
  those named by L. Dauti and M. Karapinjalli, *Përcaktimi i foljeve të
  parregullta në gjuhën shqipe*, Studime Filologjike 1-2/2018, judged by
  uniparser-albanian. The verb table takes the corpus forms of its verbs from it.
- **`data/grammar/irregular_verbs.json`**, **`irregular_nouns.json`**. The
  exception tables: each form and its stem, plus the forms left to the rules
  and why. Rebuild them when the endings change: their stems are the rules'
  stems.
- **`data/grammar/ambiguous_nouns.json`.** *shtet*, the one noun no rule can
  stem (see [the letter before an ending](#the-letter-before-an-ending)).

## Roadmap

- **A larger fitting lexicon.** The crawl lexicon has 22k words; rules fitted
  on noisier web text did worse, so more formal text would be the way to grow it.
- **A second annotator** for the human-labelled sample, and more dialectal and
  non-standard spellings in it.
- **Baselines from the literature** (earlier rule-based Albanian stemmers) and
  a lemmatizer upper bound.
- **A retrieval evaluation on queries written by people**, not generated from
  the passages they should retrieve.
- **Snowball upstream.** Submitted: snowballstem/snowball#314 (the program),
  snowball-data#45 (test vocabulary), snowball-website#55 (description page).
- **Known gaps.** The stressed -i nouns' -ve form (*shtëpive* → `shtepi`, but
  *shtëpi* → `shtep`): -ive cannot be an ending, since the -iv adjectives
  (*pozitive*, *sportive*) end the same way.

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
- fjalorthi.com, an online Albanian dictionary: conjugation tables and the
  plurals of nouns.
- M. F. Porter. *Snowball: A language for stemming algorithms*, 2001; and the
  Snowball stemmers for Romanian (the layout), Finnish, Turkish and Russian
  (letter conditions) and English Porter2 (the exception table).
- FineWeb-2 (Hugging Face, ODC-By 1.0); Stanza (Apache-2.0);
  uniparser-albanian (MIT).

## License

BSD 3-Clause (`LICENSE`), as Snowball. Dependencies: snowballstemmer
(BSD-3-Clause), uniparser-albanian (MIT), Stanza (Apache-2.0);
`postgres/runtime/` is Snowball's C runtime (BSD-3-Clause,
`postgres/runtime/COPYING`). The lexicons in `data/lexicons/` are word counts;
the FineWeb-2 part is under ODC-By 1.0.
