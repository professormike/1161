#include <stdio.h>
#include <stdlib.h>
#include <float.h>

double
average_above_threshold(double const *x, size_t n, double threshold)
{
	double sum = 0;
	size_t count = 0;
	for (size_t i = 0; i < n; i++) {
		if (x[i] > threshold) {
			sum += x[i];
			count++;
		}
	}
	return sum / count;
}

double
average(double const *x, size_t n)
{
	return average_above_threshold(x, n, -DBL_MAX);
}

int
main(void)
{
	double *x = malloc(sizeof *x);
	size_t n = 0;
	double v;
	scanf("%lf", &v);
	while (v != 0) {
		n++;
		x = realloc(x, n * sizeof *x);
		x[n - 1] = v;
		scanf("%lf", &v);
	}
	double avg = average(x, n);
	printf(	"The average is %lg\n"
			"The average of all elements above %lg is %lg\n",
		avg, avg, average_above_threshold(x, n, avg));
	return 0;
}
