/*
 * The Postgres dictionary's stemming without Postgres: for each line of
 * stdin (a word Python has lowercased), print "stem<TAB>0", or "<TAB>1" for a
 * stopword or an empty word, as albanian_dict_lexize decides.
 */
#include <stdio.h>
#include <string.h>

#include "albanian_core.h"
#include "runtime/api.h"
#include "stem_UTF_8_albanian.h"

int
main(void)
{
	struct SN_env *z = albanian_UTF_8_create_env();
	static char line[1 << 16];

	if (z == NULL)
		return 2;
	while (fgets(line, sizeof line, stdin))
	{
		int			n = (int) strcspn(line, "\n");

		n = albanian_fold(line, n, line);
		if (n == 0 || albanian_is_stopword(line))
		{
			puts("\t1");
			continue;
		}
		if (SN_set_current(z, n, (const symbol *) line) < 0 || albanian_UTF_8_stem(z) < 0)
			return 3;
		fwrite(z->p, 1, z->l, stdout);
		puts("\t0");
	}
	albanian_UTF_8_close_env(z);
	return 0;
}
