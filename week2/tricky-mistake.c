/*
 * This code deliberately has bugs in it!
 * It's supposed to draw out the letter E. For instance,
 * if the user enters in 6, it SHOULD draw:
 *
 *	######
 *  #
 *  #
 *  #
 *  ######
 *  #
 *  #
 *  #
 *  ######
 *
 * But it doesn't do that now! Find the bugs and fix them!
 */

#include <stdio.h>

int
main(void)
{
	int e_size;
	printf("How big would you like the letter E to be?");
	if (scanf("%d", e_size) != 1) {
		fprintf(stderr, "Your input was not good\n");
		return 1;
	}
	for (int j = 0; j < 3; j++) {
		// draw horizontal part
		for (int i = 0; i < e_size; i++)
			printf("#");
		printf("\t");

		// draw vertical part
		if (j < 3) {	// don't draw the vertical part on the list iteration
			for (int i = 0; i < e_size / 2; i++)
				printf("#\n");
		}
	}
	return 0;
}
