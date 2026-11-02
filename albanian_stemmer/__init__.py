"""A light, inflectional Albanian stemmer: Snowball, Python and a Postgres extension.

>>> from albanian_stemmer import stem, terms
>>> stem("sëmundjeve"), stem("semundjet")
('semund', 'semund')
>>> terms("Sëmundjet e mollës dhe të pemëve")
['semund', 'moll', 'pem']

:func:`stem` and :func:`terms` run the compiled Snowball program;
:class:`AlbanianStemmer` holds the same rules as data (for fitting, scoring
and Snowball generation).
"""

from albanian_stemmer.rules import AlbanianStemmer, default_stemmer
from albanian_stemmer.snowball import stem, stopwords, terms
from albanian_stemmer.text import fold, tokenize

__all__ = ["AlbanianStemmer", "default_stemmer", "fold", "stem", "stopwords", "terms",
           "tokenize"]
