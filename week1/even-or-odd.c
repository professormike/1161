/*
 * Reads in an integer from the user and then displays a message
 * indicating whether that integer is even or odd.
 *
 * Michael Burrell
 */

#include <stdio.h>

int
main(void)
{
	int x;
	printf("Please enter in an integer:\n");
	if (scanf("%d", &x) == 1) {
		if (x % 2 == 0) {
			printf("%d is even\n", x);
		} else {
			printf("%d is odd\n", x);
		}
	} else {
		fprintf(stderr, "That was not an integer\n");
		return 1;	// 1 means failure
	}
	return 0;	// 0 means success
}
