#include <stdio.h>

int
string_length(char const *s)
{
	if (*s == '\0') {
		return 0;	// -1 if you don't want to include the newline
	} else {
		return string_length(s + 1) + 1;
	}
}

int
main(void)
{
	char line[100];
	fgets(line, sizeof line, stdin);
	printf("%d\n", string_length(line));
	return 0;
}
