#include <stdio.h>

int
main(void)
{
	char s[50];
	fgets(s, 50, stdin);
	printf("%s\n", s);
	return 0;
}
