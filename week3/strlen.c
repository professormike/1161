#include <stdio.h>

size_t	// can represent the size of any object in memory
string_length(char const *s)
{
	size_t i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int
main(void)
{
	char *x = "hello";
	printf("%zu\n", string_length(x));
	return 0;
}
