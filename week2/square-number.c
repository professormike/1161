#include <stdio.h>

double
square1(double n)
{
	return n * n;
}

int
main(void)
{
	double x;
	scanf("%lf", &x);
	double s = square1(x);
	printf("%lf squared is %lf\n", x, s);
	return 0;
}
