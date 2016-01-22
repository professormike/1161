#include <stdio.h>

int
bar(int x)
{
	x--;
	return x;
}

int
foo(int x)
{
	x = bar(x * 2);
	return x / 2;
}

int
main(void)
{
	int x = 3;
	foo(x);
	printf("%d\n", x);
	return 0;
}
