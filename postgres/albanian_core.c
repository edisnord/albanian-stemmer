#include <stdlib.h>
#include <string.h>

#include "albanian_core.h"
#include "albanian_stopwords.h"

int
albanian_fold(const char *src, int len, char *dst)
{
	int			i = 0,
				j = 0;

	while (i < len)
	{
		unsigned char c = (unsigned char) src[i];

		if (c == 0xC3 && i + 1 < len)
		{
			unsigned char d = (unsigned char) src[i + 1];

			if (d == 0xAB || d == 0x8B)	/* ë, Ë */
			{
				dst[j++] = 'e';
				i += 2;
				continue;
			}
			if (d == 0xA7 || d == 0x87)	/* ç, Ç */
			{
				dst[j++] = 'c';
				i += 2;
				continue;
			}
		}
		dst[j++] = (char) (c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c);
		i++;
	}
	dst[j] = '\0';
	return j;
}

static int
compare(const void *key, const void *entry)
{
	return strcmp((const char *) key, *(const char *const *) entry);
}

int
albanian_is_stopword(const char *folded)
{
	return bsearch(folded, albanian_stopwords,
				   sizeof(albanian_stopwords) / sizeof(albanian_stopwords[0]),
				   sizeof(albanian_stopwords[0]), compare) != NULL;
}
