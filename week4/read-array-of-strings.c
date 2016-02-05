#include <stdio.h>
#include <stdlib.h>

static
char *
read_string(void)
/*
 * Reads in, from standard input, one character at a time
 * and stores it in an array of characters. There is no
 * limit on the length of the string. The string will be
 * stored on the heap (and must be free()d at some point)
 */
{
	char *r = malloc(sizeof *r);
	int i = 0;
	while (1) {
		r = realloc(r, i + 1);
		r[i] = getchar();
		i++;
		if (r[i - 1] == '\n') {
			r[i - 1] = '\0';
			return 0;
		}
	}
}
