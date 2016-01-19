/*
 * Read in an integer from the user, n, and then
 * print out an n x n square of asterisks.
 *
 * Michael Burrell
 */

#include <stdio.h>

int
main(void)
{
	int n;
	printf("How big of a square would you like?\n");
	if (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("*");
			}
			printf("\n");
		}
	} else {
		fprintf(stderr, "That was not an integer\n");
		return 1;
	}
	return 0;
}
