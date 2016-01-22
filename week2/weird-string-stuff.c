#include <stdio.h>

int
main(void)
{
	char x[6];
	x[0] = 'h';
	x[1] = 'i';
	x[2] = 0;	// NUL character ('\0')
	x[3] = 'x';
	x[4] = 'o';
	x[5] = 0;
	printf("%s %s\n", &x[0], &x[3]);
	return 0;
}
