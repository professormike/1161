#include "tree.h"
#include <stdio.h>

int
main(void)
{
	struct tree t = { .root = NULL };	// empty tree
	for (int i = 1000000; i >= 0; i--) {
		insert_in_tree(&t, i);
	}
	print_tree(&t);
/*
	insert_in_tree(&t, 12);
	insert_in_tree(&t, 7);
	insert_in_tree(&t, 20);
	insert_in_tree(&t, 3);
	insert_in_tree(&t, 11);
	insert_in_tree(&t, 14);
	insert_in_tree(&t, 22);
	remove_from_tree(&t, 12);
	for (int i = 1; i <= 22; i++) {
		if (search_in_tree(&t, i)) {
			printf("%d is in the tree\n", i);
		} else {
			printf("%d is NOT in the tree\n", i);
		}
	}
*/
	free_tree(&t);
	return 0;
}
