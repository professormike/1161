#include "heap.h"
#include <stdio.h>

int
main(void)
{
	void *heap = empty_heap();
#define ADD(x)	heap = insert(heap, x)
	ADD(14);
	ADD(23);
	ADD(1);
	ADD(29);
	ADD(28);
	ADD(14);
	ADD(29);
	ADD(3);
	ADD(44);
	ADD(1);
	ADD(14);
	ADD(10);
	ADD(31);
	ADD(48);
	ADD(19);
	ADD(33);
	ADD(8);
	ADD(36);
	ADD(27);
	ADD(20);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", get_maximum(heap));
		heap = remove_maximum(heap);
	}
	free_heap(heap);
	return 0;
}
