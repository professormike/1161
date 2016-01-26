/*
 * A short program that will print out the sizes of
 * various data types in C. Note that you will get
 * different output on different architectures!
 */

#include <stdio.h>

int
main(void)
{
	char a = 'h';
	int b = 5;
	long c = 10;
	printf("size of %c is %zu\n", a, sizeof a);
	printf("size of %d is %zu\n", b, sizeof b);
	printf("size of %ld is %zu\n", c, sizeof c);

	char *ap = &a;
	long *cp = &c;
	printf("size of %p is %zu\n", ap, sizeof ap);
	printf("size of %p is %zu\n", cp, sizeof cp);

	return 0;
}
