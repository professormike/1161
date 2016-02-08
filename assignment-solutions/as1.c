#include <stdio.h>
#include <ctype.h>

static
void
scan_sentence(char const *s, int *shortest, int *longest)
/*
 * The parameter 's' is a string to be scanned. The value pointed to by
 * 'shortest' will be updated with the length of the shortest word in
 * the string. The value pointed to by 'largest' will be updated with
 * the length of the longest word in the string
 */
{
	// initialize these to -1 so that we can detect in the loop that
	// they haven't been set yet
	*shortest = -1;
	*longest = -1;

	// go through the string, character by character
	size_t word_start = 0;
	for (size_t i = 0; s[i] != '\0'; i++) {
		if (isspace(s[i])) {
			size_t word_len = i - word_start;
			if (*shortest == -1 || word_len < *shortest)
				*shortest = word_len;
			if (*longest == -1 || word_len > *longest)
				*longest = word_len;

			// the next word should start AFTER the space
			word_start = i + 1;
		}
	}
}

int
main(void)
{
	char line[102];
	while (1) {
		fgets(line, sizeof line, stdin);
		if (line[0] == '\n') {	// the user just hit enter
			printf("Goodbye!\n");
			return 0;
		}
		int shortest, longest;
		scan_sentence(line, &shortest, &longest);
		printf("The shortest word had %d characters and the longest word had %d characters\n",
			shortest, longest);
	}
}
