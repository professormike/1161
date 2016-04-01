#include <stdio.h>

unsigned int
hash_string(char const *x)
// courtesy of Clifton
{
	unsigned int s = 0;
	int fiba = 1;
	int fibb = 1;
	for (size_t i = 1; x[i] != '\0'; i++) {
		s += x[i] * fibb;
		int c = fiba + fibb;
		fiba = fibb;
		fibb = c;
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
