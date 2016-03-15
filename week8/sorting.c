#include <stdio.h>
#include <string.h>	// for memcpy

void
selection_sort(int *array, size_t n)
{
	for (size_t i = 0; i < n - 1; i++) {
		// find the smallest number
		size_t smallest_num_pos = i;
		for (size_t j = i + 1; j < n; j++) {
			if (array[j] < array[smallest_num_pos]) {
				smallest_num_pos = j;
			}
		}
		// swap the smallest number to the front of the array
		int temp = array[i];
		array[i] = array[smallest_num_pos];
		array[smallest_num_pos] = temp;
	}
}

void
merge(int const *x, size_t xsize, int const *y, size_t ysize,
int *output)
{
	size_t x_pos = 0;
	size_t y_pos = 0;
	for (size_t out_pos = 0; out_pos < xsize + ysize; out_pos++) {
		// x_pos < x_size means that we're not at the end of x yet
		// y_pos == ysize means we ARE at the end of y already
		if (x_pos < xsize &&
		(y_pos == ysize || x[x_pos] < y[y_pos])) {
			output[out_pos] = x[x_pos];
			x_pos++;
		} else {
			output[out_pos] = y[y_pos];
			y_pos++;
		}
	}
}

void
mergesort(int *array, size_t n)
{
	if (n == 1) {
		// do nothing: already sorted
	} else {
		// dividing 'array' in half by copying each half into
		// a new array
		size_t midpoint = n / 2;
		int left[midpoint];
		int right[n - midpoint];
		memcpy(left, array, sizeof left);
		memcpy(right, &array[midpoint], sizeof right);
		// now sort each half of the array
		mergesort(left, sizeof left / sizeof *left);
		mergesort(right, sizeof right / sizeof *right);
		// now merge the two halves together
		merge(left, sizeof left / sizeof *left,
			right, sizeof right / sizeof *right,
			array);
	}
}

int
main(void)
{
#include "big.h"
	mergesort(x, sizeof x / sizeof *x);
	for (size_t i = 0; i < sizeof x / sizeof *x; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
}

