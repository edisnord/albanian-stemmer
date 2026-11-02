# Albanian text search for Postgres: a dictionary template wrapping the
# Snowball stemmer generated from ../albanian_stemmer/snowball/albanian.sbl
# (stem_UTF_8_albanian.c and albanian_stopwords.h are written by
# albanian_stemmer.fit; runtime/ is Snowball's C runtime).
#
#   make && make install           (PG_CONFIG=/path/to/pg_config for another server)
#   make installcheck              (regression test against the running server)
#
# Then, in a database: CREATE EXTENSION albanian_stemmer;
#   SELECT to_tsvector('albanian', 'Sëmundjet e mollës dhe të pemëve');

MODULE_big = albanian_stemmer
OBJS = dict_albanian.o albanian_core.o stem_UTF_8_albanian.o \
	runtime/api.o runtime/snowball_runtime.o
EXTENSION = albanian_stemmer
DATA = albanian_stemmer--1.0.sql
PGFILEDESC = "albanian_stemmer - Albanian text search dictionary"
REGRESS = albanian_stemmer

# The Snowball runtime's symbols are renamed (see snowball_prefix.h).
PG_CPPFLAGS = -include $(srcdir)/snowball_prefix.h -I$(srcdir)

PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
