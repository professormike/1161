#include <stdlib.h>
#include <stdio.h>

static
int
compare_ints(const void *a, const void *b)
{
	const int *a_int = a;
	const int *b_int = b;
	if (*a_int < *b_int)
		return -1;
	else if (*a_int == *b_int)
		return 0;
	else
		return +1;
}

int
main(void)
{
	int x[] = { -6, 9, -7, 0, 3, 1, 4, -2, -5 };

	// if you don't like 'x', you can say '&x[0]'
	qsort(x, sizeof x / sizeof *x, sizeof *x, &compare_ints);

	for (int i = 0; i < sizeof x / sizeof *x; i++)
		printf("%d ", x[i]);
	printf("\n");
	return 0;
}







