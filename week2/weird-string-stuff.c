#include <stdio.h>

int
main(void)
{
	char x[5];
	x[0] = 'h';
	x[1] = 'i';
	x[2] = 0;	// NUL character ('\0')
	x[3] = 'x';
	x[4] = 0;
	printf("%s\n", x);
	return 0;
}
