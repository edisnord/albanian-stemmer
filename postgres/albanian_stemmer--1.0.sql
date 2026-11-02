/* albanian_stemmer--1.0.sql */

\echo Use "CREATE EXTENSION albanian_stemmer" to load this file. \quit

CREATE FUNCTION albanian_dict_init(internal)
RETURNS internal
AS 'MODULE_PATHNAME'
LANGUAGE C STRICT;

CREATE FUNCTION albanian_dict_lexize(internal, internal, internal, internal)
RETURNS internal
AS 'MODULE_PATHNAME'
LANGUAGE C STRICT;

CREATE TEXT SEARCH TEMPLATE albanian_stem_template (
    INIT = albanian_dict_init,
    LEXIZE = albanian_dict_lexize
);
COMMENT ON TEXT SEARCH TEMPLATE albanian_stem_template IS
    'Albanian Snowball stemmer, with its stopwords (option StopWords = false keeps them)';

CREATE TEXT SEARCH DICTIONARY albanian_stem (TEMPLATE = albanian_stem_template);
COMMENT ON TEXT SEARCH DICTIONARY albanian_stem IS
    'Albanian Snowball stemmer: folds ë/ç, drops stopwords, strips inflection';

-- Like the built-in language configurations: words go to the stemmer, the
-- other token types (numbers, URLs, emails, ...) stay as in 'simple'.
CREATE TEXT SEARCH CONFIGURATION albanian (COPY = pg_catalog.simple);
ALTER TEXT SEARCH CONFIGURATION albanian
    ALTER MAPPING FOR asciiword, word, hword_part, hword_asciipart, asciihword, hword
    WITH albanian_stem;
COMMENT ON TEXT SEARCH CONFIGURATION albanian IS 'configuration for Albanian language';
