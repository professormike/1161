/*
 * Reads in a string from the user, making no assumptions
 * about the maximum length of it, and prints it out
 *
 * Michael Burrell
 */

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	char *s = malloc(1 * sizeof *s);
	size_t n = 0;
	char c = getchar();
	while (c != '\n') {
		s[n] = c;
		n++;
		s = realloc(s, (n + 1) * sizeof *s);
		c = getchar();
	}
	// NUL-terminate the string
	n++;
	s = realloc(s, (n + 1) * sizeof *s);
	s[n] = '\0';

	printf("%s\n", s);
	free(s);
	return 0;
}
