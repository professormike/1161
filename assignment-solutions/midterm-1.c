#include <stdio.h>
#include <stdlib.h>

struct factors {
	int twos;
	int threes;
};

void
factor(int x, struct factors *f)
{
	f->twos = 0;
	f->threes = 0;
	while (x % 2 == 0) {
		f->twos++;
		x /= 2;
	}
	while (x % 3 == 0) {
		f->threes++;
		x /= 3;
	}
}

int
main(void)
{
	int x;
	scanf("%d", &x);
	while (x >= 0) {
		struct factors f;
		factor(x, &f);
		printf("There are %d twos and %d threes\n",
			f.twos, f.threes);
		scanf("%d", &x);
	}
	printf("Goodbye!\n");
	return 0;
}
