#include <stdio.h>

double
square1(double n)
{
	return n * n;
}

void
square2(double *n)
{
	*n = *n * *n;	// *n *= *n;
}

int
main(void)
{
	double x;
	scanf("%lf", &x);
	square2(&x);
	printf("that squared is %lf\n", x);
	return 0;
}
