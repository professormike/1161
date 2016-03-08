/*
 * Sample solution to the midterm exam
 *
 * Reads in an unbounded number of complex numbers, then prints out
 * the average magnitude of them
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex {
	double real;
	double imaginary;
};

double
magnitude(struct complex c)
{
	return sqrt(pow(c.real, 2) + pow(c.imaginary, 2));
}

double
average_magnitude(struct complex const *c, size_t n)
{
	double sum = 0;
	for (size_t i = 0; i < n; i++) {
		sum += magnitude(c[i]);
	}
	return sum / n;
}

int
main(void)
{
	struct complex *c = malloc(1 * sizeof *c);
	size_t n = 0;
	double r, i;
	while (scanf("%lf %lf", &r, &i) == 2 &&
	!(r == 0 && i == 0)) {
		c = realloc(c, (n + 1) * sizeof *c);
		c[n].real = r;
		c[n].imaginary = i;
		n++;
	}
	printf("%lf\n", average_magnitude(c, n));
	free(c);
	return 0;
}

