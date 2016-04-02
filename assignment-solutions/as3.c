/*
 * Sample solution for assignment 3, which combines mergesort and selection sort
 * together into a hybrid sort
 */

#include <stdio.h>
#include <string.h>	// for memcpy

/*
 * I was using an array of size 100k elements to try to determine the best threshold
 * to size. I used trial and error (using the "time" command), and my numbers were:
 *	threshold	time
 * ------------------
 *		 5		3.16
 *		 6		3.17
 *		 8		2.90
 *		10		2.90
 *		11		2.88
 *		12		2.89
 *		15		2.91
 *		20		2.92
 *		40		3.09
 * Based on these trials, I'm choosing 11 as the threshold for my particular
 * computer.
 */
#define THRESHOLD 11

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
	if (n < THRESHOLD) {
		selection_sort(array, n);
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
static void (*hybrid_sort)(int *, size_t) = mergesort;

#include "as3-big-array.h"

int
main(void)
{
	// sort it 100 times to get better numbers when timing
	for (int i = 0; i < 100; i++) {
		hybrid_sort(x, sizeof x / sizeof *x);
	}
	// now try sorting it as a small array
	hybrid_sort(x, 7);	// only sort the first 7 elements
	return 0;
}

