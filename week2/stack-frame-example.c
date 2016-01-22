#include <stdio.h>

int
foo(int x)
{
	x--;
	return x;
}

int
bar(int x)
{
	x = foo(x * 2);
	return x / 2;
}

int
main(void)
{
	x = 3;
	foo(x);
	printf("%d\n", x);
	return 0;
}
