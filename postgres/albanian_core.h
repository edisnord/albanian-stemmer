/*
 * The steps around the Snowball stemmer that do not need Postgres, shared by
 * the dictionary (dict_albanian.c) and the tests (tests/c/stem_words.c).
 */
#ifndef ALBANIAN_CORE_H
#define ALBANIAN_CORE_H

/*
 * Fold UTF-8 *src* (*len* bytes) into *dst*: ë/Ë → e, ç/Ç → c, A-Z → a-z, as
 * albanian_stemmer.text.fold does for an already lowercased word (a C-collation
 * lower() leaves Ë and Ç alone). *dst* may be *src*; it gets at most *len*
 * bytes and a NUL. Returns the folded length.
 */
extern int	albanian_fold(const char *src, int len, char *dst);

/* Whether a folded word is one of the rules' stopwords. */
extern int	albanian_is_stopword(const char *folded);

#endif
