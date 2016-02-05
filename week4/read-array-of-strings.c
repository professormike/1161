#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			return r;
		}
	}
}

int
main(void)
{
	char **strings = malloc(1 * sizeof *strings);
	int n = 0;
	// each time through the loop, we will read in 1 string from
	// the user and add it to our array of strings
	while (1) {
		strings[n] = read_string();
		if (strcmp(strings[n], "exit") == 0) {
			free(strings[n]);
			break;
		}
		n++;
		strings = realloc(strings, (n + 1) * sizeof *strings);
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", strings[i]);
	}

	for (int i = 0; i < n; i++) {
		free(strings[i]);
	}
	free(strings);

	return 0;
}




