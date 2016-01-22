#include <stdio.h>

int
main(void)
{
	char x[] = "hello";
	char *y = "hello";
	x[0] = 'j';
	printf("%s %c %s\n", x, y[0], y);
	return 0;
}
