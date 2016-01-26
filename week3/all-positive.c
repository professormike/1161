#include <stdio.h>

static
int
all_positive(int *array, size_t n)
/*
 * 'array' is a pointer to the first element of an array
 * of 'n' integers.
 * Returns 0 if at least one element is negative (or 0)
 * Returns 1 if all elements are positive
 */
{
	for (size_t i = 0; i < n; i++) {
		if (array[i] <= 0) {
			return 0;
		}
	}
	return 1;
}

int
main(void)
{
	int x[] = { 5, 6, 9, -3, 4, 2 };
	printf("all numbers are positive? %d\n",
		all_positive(x, sizeof x / sizeof *x));
	return 0;
}



