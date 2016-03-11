#include <stdio.h>

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

int
main(void)
{
	int x[] = { 3, 0, 9, 4, 16, -5, 6, 2 };
	selection_sort(x, sizeof x / sizeof *x);
	for (size_t i = 0; i < sizeof x / sizeof *x; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
}








