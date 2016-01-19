#include <stdio.h>

int
main(void)
{
	int x, y;
	printf("Enter two numbers\n");
	if (scanf("%d %d", &x, &y) != 2) {
		fprintf(stderr, "You didn't enter in two numbers!\n");
		return 1;
	}
	if (x > y) {	// swap them
		int tmp = x;
		x = y;
		y = tmp;
	}
	int sum = 0;
	for (int i = x; i <= y; i++) {
		printf("%d ", i);
		sum += i;
	}
	printf("\n%d\n", sum);
	return 0;
}
