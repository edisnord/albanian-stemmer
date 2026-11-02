/*
 * Albanian text search dictionary, after Postgres's own dict_snowball: a
 * token is lowercased, dropped if it is a stopword, and otherwise stemmed by
 * the Snowball stemmer generated from albanian.sbl (stem_UTF_8_albanian.c),
 * which folds ë/ç, looks irregular forms up in its exception table and strips
 * the endings. The stems match albanian_stemmer.stem() in Python.
 *
 * Options: StopWords = false keeps the stopwords (as their stems).
 */
#include "postgres.h"

#include "catalog/pg_collation.h"
#include "commands/defrem.h"
#include "fmgr.h"
#include "mb/pg_wchar.h"
#include "tsearch/ts_public.h"
#include "utils/formatting.h"

#include "albanian_core.h"
#include "runtime/api.h"
#include "stem_UTF_8_albanian.h"

PG_MODULE_MAGIC;

typedef struct DictAlbanian
{
	struct SN_env *z;
	bool		stopwords;
} DictAlbanian;

PG_FUNCTION_INFO_V1(albanian_dict_init);
PG_FUNCTION_INFO_V1(albanian_dict_lexize);

Datum
albanian_dict_init(PG_FUNCTION_ARGS)
{
	List	   *options = (List *) PG_GETARG_POINTER(0);
	DictAlbanian *d = palloc0(sizeof(DictAlbanian));
	ListCell   *l;

	d->stopwords = true;
	foreach(l, options)
	{
		DefElem    *defel = (DefElem *) lfirst(l);

		if (pg_strcasecmp(defel->defname, "StopWords") == 0)
			d->stopwords = defGetBoolean(defel);
		else
			ereport(ERROR,
					(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
					 errmsg("unrecognized Albanian dictionary parameter: \"%s\"",
							defel->defname)));
	}

	/*
	 * The Snowball runtime allocates with malloc. Its environment lives as
	 * long as the dictionary's cache entry, i.e. until the dictionary is
	 * altered or the backend exits.
	 */
	d->z = albanian_UTF_8_create_env();
	if (d->z == NULL)
		ereport(ERROR,
				(errcode(ERRCODE_OUT_OF_MEMORY),
				 errmsg("out of memory")));
	PG_RETURN_POINTER(d);
}

Datum
albanian_dict_lexize(PG_FUNCTION_ARGS)
{
	DictAlbanian *d = (DictAlbanian *) PG_GETARG_POINTER(0);
	char	   *in = (char *) PG_GETARG_POINTER(1);
	int32		len = PG_GETARG_INT32(2);
	char	   *txt = str_tolower(in, len, DEFAULT_COLLATION_OID);
	TSLexeme   *res = palloc0(sizeof(TSLexeme) * 2);
	int			n;

	if (GetDatabaseEncoding() != PG_UTF8)
	{
		char	   *u = pg_server_to_any(txt, strlen(txt), PG_UTF8);

		if (u != txt)
		{
			pfree(txt);
			txt = u;
		}
	}
	n = albanian_fold(txt, strlen(txt), txt);
	if (n == 0 || (d->stopwords && albanian_is_stopword(txt)))
	{
		pfree(txt);
		PG_RETURN_POINTER(res);	/* a stopword: no lexeme */
	}

	if (SN_set_current(d->z, n, (const symbol *) txt) < 0 ||
		albanian_UTF_8_stem(d->z) < 0)
		ereport(ERROR,
				(errcode(ERRCODE_OUT_OF_MEMORY),
				 errmsg("out of memory")));
	pfree(txt);
	txt = palloc(d->z->l + 1);
	memcpy(txt, d->z->p, d->z->l);
	txt[d->z->l] = '\0';

	if (GetDatabaseEncoding() != PG_UTF8)
	{
		char	   *s = pg_any_to_server(txt, strlen(txt), PG_UTF8);

		if (s != txt)
		{
			pfree(txt);
			txt = s;
		}
	}
	res->lexeme = txt;
	PG_RETURN_POINTER(res);
}
