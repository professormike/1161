/*
 * Motivation for why we need the heap
 */

#include <stdio.h>
#include <stdlib.h>	// needed for malloc

struct x {
	int y;
};

struct x *foo(int y) {
	struct x *r = malloc(sizeof *r);
	r->y = y;
	return r;
}

int
main(void)
{
	struct x *a = foo(3);
	struct x *b = foo(4);
	printf("%d %d\n", a->y, b->y);
	return 0;
}
