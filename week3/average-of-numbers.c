/*
 * Read in 'n' numbers from the user
 * into an array and then calculate
 * and print out the average.
 *
 * Michael Burrell
 */

#include <stdio.h>

static	// kind of like "private" in Java
double
average(double *x, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
	}
	return sum / n;	
}

int
main(void)
{
	int n;
	printf("How many numbers are you going to enter?\n");
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "That was bad input\n");
		return 1;
	}

	double x[n];
	for (int i = 0; i < n; i++) {
		if (scanf("%lf", &x[i]) != 1) {	// &x[i] is the same as x + i
			fprintf(stderr, "That was bad input\n");
			return 1;
		}
	}

	printf("The average is %lf\n", average(x, n));
	return 0;
}






