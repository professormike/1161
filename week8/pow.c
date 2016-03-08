/*
 * For positive integers, computes the power, using only recursion
 */

#include <stdio.h>

int
power(int x, int y)
{
	if (y == 0) {
		return 1;
	} else {
		return x * power(x, y - 1);
	}
}

int
main(void)
{
	printf("%d\n", power(2, 3));	// should print 8
	return 0;
}
