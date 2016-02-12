#include "inventory.h"
#include <stdio.h>

int
main(void)
{
	size_t n;
	struct item *l = empty_inventory(&n);
	l = add_inventory(l, &n, "bananas", 3);
	l = add_inventory(l, &n, "apples", 2);
	l = add_inventory(l, &n, "oranges", 6);
	l = remove_inventory(l, &n, "apples");
	l = add_inventory(l, &n, "grapes", 450);
	for (size_t i = 0; i < n; i++) {
		printf("%s\t%d\n", l[i].name, l[i].quantity);
	}
	destroy_inventory(l);
	return 0;
}
