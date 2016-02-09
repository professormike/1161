#include <stdio.h>
#include <stdlib.h>

static
double
calc_median(double const *array, size_t size)
{
	double median;
	if (size % 2 == 1) {
		median = array[size / 2];
	} else {
		size = size / 2;
		median = (array[size] + array[size - 1]) / 2;
	}
	return median;
}

static
int
cmp_double(void const *a_, void const *b_)
{
	double const *a = a_;
	double const *b = b_;
	return *a < *b ? -1 : 1;
}

int
main(void)
{
	double *x = malloc(sizeof *x);
	size_t n = 0;
	double current;
	while (scanf("%lf", &current) == 1) {
		x = realloc(x, (n + 1) * sizeof *x);
		x[n] = current;
		n++;
	}
	qsort(x, n, sizeof *x, &cmp_double);
	for (size_t i = 0; i < n; i++) {
		printf("%lf\n", x[i]);
	}
	printf("The median is %lf\n", calc_median(x, n));
	free(x);
	return 0;
}




