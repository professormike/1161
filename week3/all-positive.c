#include <stdio.h>

static
int
all_positive(void *array, size_t n, size_t sz,
int (*is_positive)(void *))
/*
 * 'array' is a pointer to the first element of an array
 * of 'n' elements. Each element is 'sz' bytes in size. The
 * function 'is_positive' can tell us whether any given
 * element is positive.
 * Returns 0 if at least one element is negative (or 0)
 * Returns 1 if all elements are positive
 */
{
	for (size_t i = 0; i < n; i++) {
		void *elem_i_location = array + sz * i;
		if (!(*is_positive)(elem_i_location)) {
			return 0;
		}
	}
	return 1;
}

static
int
is_positive_double(void *ptr)
{
	return *(double *)ptr >= 0;
}

int
main(void)
{
	double x[] = { 5, 6, 9, -3, 4, 2 };
	printf("all numbers are positive? %s\n",
		all_positive(x, sizeof x / sizeof *x, sizeof *x, &is_positive_double) ? "yes" : "no");
	return 0;
}






