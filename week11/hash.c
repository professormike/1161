#include <stdio.h>

unsigned int
hash_string(char const *x)
{
	int s = x[0];
	for (size_t i = 1; x[i] != '\0'; i++) {
		s -= x[i];
	}
	if (s < 0) {
		s = -s;
	}
	return s;
}

int
main(void)
{
	char line[100];
	while (1) {
		fgets(line, sizeof line, stdin);
		printf("%u\n", hash_string(line));
	}
}
