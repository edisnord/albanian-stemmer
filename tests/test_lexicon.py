"""Lexicon IO, the corpus reader and language filter, scoring and its baselines."""

from __future__ import annotations

import gzip
import json

import pytest

from albanian_stemmer import build_lexicon, evaluate
from albanian_stemmer.lexicon import LexWord, load_lexicon, write_lexicon
from albanian_stemmer.metrics import Corpus, PrefixStemmer, top_words
from albanian_stemmer.rules import AlbanianStemmer, default_stemmer

SQ = "Sëmundjet e mollës dhe të pemëve duhet të trajtohen në kohë nga fermerët."
EN = "The diseases of apples and other fruit trees must be treated in time by farmers."
IT = "Le malattie delle mele e degli alberi da frutto devono essere trattate in tempo."


def test_lexicon_roundtrip_with_and_without_tagged_column(tmp_path):
    words = [LexWord("dhe", ["dhe"], 100, 90, 95), LexWord("mollës", ["mollë"], 7, 0, 3),
             LexWord("molla", ["mollë", "mollë"], 5, 0, 0)]
    path = tmp_path / "lex.tsv.gz"
    assert write_lexicon(path, words) == 3
    back = {e.word: e for e in load_lexicon(path)}
    assert back["dhe"].is_stopword and not back["mollës"].is_stopword
    assert back["mollës"].tagged == 3
    old = tmp_path / "old.tsv"
    old.write_text("dhe\tdhe\t100\t90\n")  # four columns: every occurrence tagged
    (e,) = load_lexicon(old)
    assert e.tagged is None and e.is_stopword


def test_language_filter_keeps_albanian_with_or_without_diacritics():
    assert build_lexicon.albanian_tokens(SQ, 5, 0.1)
    plain = SQ.replace("ë", "e").replace("ç", "c")
    assert build_lexicon.albanian_tokens(plain, 5, 0.1)
    assert build_lexicon.albanian_tokens(EN, 5, 0.1) is None
    assert build_lexicon.albanian_tokens(IT, 5, 0.1) is None
    assert build_lexicon.albanian_tokens("Kreu Lajme Kontakt", 5, 0.1) is None  # a menu


def test_reader_handles_text_jsonl_and_compression(tmp_path):
    (tmp_path / "a.txt").write_text(f"{SQ}\n\n  {EN}  \n")
    (tmp_path / "sub").mkdir()
    with gzip.open(tmp_path / "sub" / "b.jsonl.gz", "wt", encoding="utf-8") as f:
        f.write(json.dumps({"text": f"{SQ}\n{IT}", "url": "x"}) + "\n")
        f.write("not json\n")
        f.write(json.dumps({"body": "no text field"}) + "\n")
    units = list(build_lexicon.iter_units([str(tmp_path)]))
    assert units == [SQ, EN, SQ, IT]


def test_count_pass_and_untagged_build(tmp_path):
    pytest.importorskip("uniparser_albanian")
    corpus = tmp_path / "corpus.txt"
    corpus.write_text("\n".join([SQ] * 3 + [EN] * 3) + "\n")
    out = tmp_path / "lex.tsv.gz"
    assert build_lexicon.main([str(corpus), "--out", str(out), "--tagger", "none",
                               "--min-count", "2"]) == 0
    lex = {e.word: e for e in load_lexicon(out)}
    assert "mollës" in lex and "apples" not in lex
    assert lex["mollës"].occurrences == 3 and lex["mollës"].tagged == 0
    assert "mollë" in lex["mollës"].lemmas  # from uniparser
    stats = json.loads((tmp_path / "lex.tsv.gz.work" / "stats.json").read_text())
    assert stats["albanian_units"] == 3 and stats["units"] == 6
    # A rerun reuses the counts instead of reading the corpus again.
    corpus.unlink()
    assert build_lexicon.main([str(corpus), "--out", str(out), "--tagger", "none",
                               "--min-count", "2"]) == 0


LEX = [LexWord(w, [lemma], n, 0) for w, lemma, n in [
    ("molla", "mollë", 10), ("mollës", "mollë", 5), ("mollët", "mollë", 3),
    ("mali", "mal", 8), ("malet", "mal", 4), ("malli", "mall", 2),
    ("punoj", "punoj", 6), ("punuar", "punoj", 2)]]


def test_scores_and_baselines():
    c = Corpus(LEX)
    none = c.score(AlbanianStemmer((), 99))
    assert none["R_type"] == 0 and none["stems"] == len(LEX)
    st = c.score(default_stemmer())
    assert st["R_type"] > 0.5 and st["P_type"] > 0.5
    p3 = c.score(PrefixStemmer(3))  # merges mal and mall
    assert p3["P_type"] < 1


def test_top_words_and_evaluate_cli(tmp_path, capsys):
    assert [e.word for e in top_words(LEX, 2)] == ["molla", "mali"]
    path = tmp_path / "lex.tsv"
    write_lexicon(path, LEX)
    report = tmp_path / "eval.json"
    assert evaluate.main(["--lexicon", str(path), "--report", str(report)]) == 0
    scores = json.loads(report.read_text())["scores"]
    assert {"none", "prefix-4", "prefix-5", "prefix-6"} <= set(scores)
    assert "held-out" in capsys.readouterr().out


class _FakeWord:
    def __init__(self, text: str):
        self.text, self.lemma = text, text.rstrip("sëtn") or text
        self.upos = "CCONJ" if text.lower() in {"dhe", "e", "të"} else "NOUN"


class _FakeDoc:
    def __init__(self, _sentences, text: str):
        self.sentences = [type("S", (), {"words": [_FakeWord(t) for t in text.split()]})()]


class _FakeNLP:
    def __init__(self):
        self.seen: list[str] = []

    def bulk_process(self, docs):
        self.seen += [" ".join(w.text for w in d.sentences[0].words) for d in docs]
        return docs


@pytest.fixture
def fake_stanza(monkeypatch):
    import sys
    import types

    mod = types.ModuleType("stanza")
    mod.Document = _FakeDoc  # type: ignore[attr-defined]
    monkeypatch.setitem(sys.modules, "stanza", mod)
    nlp = _FakeNLP()
    monkeypatch.setattr(build_lexicon.StanzaTagger, "_pipeline", lambda self: nlp)
    return nlp


UNITS = ["molla dhe dardha janë të ëmbla nuk", "molla dhe dardha janë të ëmbla nuk",
         "fiqtë dhe ftonjtë nuk janë të thartë", "molla dhe fiqtë nuk janë të ëmbla"]


def test_tagger_picks_units_for_words_still_wanted_and_resumes(tmp_path, fake_stanza):
    vocab = {"molla", "dhe", "fiqtë", "ftonjtë"}
    t = build_lexicon.StanzaTagger(vocab, 1, tmp_path / "state.pkl", batch_units=1)
    t.run(iter(UNITS), 5, 0.1, None)
    assert fake_stanza.seen == [UNITS[0], UNITS[2]]  # the repeat and unit 4 add nothing new
    assert t.tags["dhe"][1:] == [2, 2]  # tagged twice, a function word both times
    assert t.tags["molla"] == [{"molla"}, 1, 0]  # the fake lemmatizer keeps it
    # Done: a rerun loads the state and tags nothing more.
    t2 = build_lexicon.StanzaTagger(vocab, 1, tmp_path / "state.pkl", batch_units=1)
    t2.run(iter(UNITS), 5, 0.1, None)
    assert fake_stanza.seen == [UNITS[0], UNITS[2]] and t2.tags == t.tags


def test_tagger_budget_stop_continues_on_rerun(tmp_path, fake_stanza):
    vocab = {"molla", "fiqtë"}
    t = build_lexicon.StanzaTagger(vocab, 1, tmp_path / "state.pkl", batch_units=1)
    t.run(iter(UNITS), 5, 0.1, max_chars=1)
    assert fake_stanza.seen == [UNITS[0]] and "fiqtë" not in t.tags
    t2 = build_lexicon.StanzaTagger(vocab, 1, tmp_path / "state.pkl", batch_units=1)
    t2.run(iter(UNITS), 5, 0.1, None)
    assert fake_stanza.seen == [UNITS[0], UNITS[2]] and t2.tags["fiqtë"][1] == 1
