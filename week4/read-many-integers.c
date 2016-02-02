/*
 * Reads in a series of integers from the user, until
 * the user enters in a negative number. Then it prints
 * them all out. We do not make any assumptions about
 * the maximum number of integers the user will type in,
 * so we use realloc
 *
 * Michael Burrell
 */

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int *numbers = malloc(1 * sizeof *numbers);
	size_t n = 0;
	int current_number;
	scanf("%d", &current_number);
	while (current_number >= 0) {
		numbers[n] = current_number;
		n++;
		numbers = realloc(numbers, (n + 1) * sizeof *numbers);
		scanf("%d", &current_number);
	}

	for (size_t i = 0; i < n; i++) {
		printf("%d\n", numbers[i]);
	}
	free(numbers);
	return 0;
}
