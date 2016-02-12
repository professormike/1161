#include "inventory.h"
#include <stdlib.h>	// for malloc()/realloc()/free()
#include <string.h>

struct item *
empty_inventory(size_t *n)
/*
 * 'n' is a reference to a variable which keeps track of the size
 * of this array. We return a pointer to the first element of
 * the array
 */
{
	*n = 0;
	struct item *r = malloc(1 * sizeof *r);
	return r;
}

struct item *
add_inventory(struct item *list, size_t *n, char const *name, int q)
{
	(*n)++;
	list = realloc(list, *n * sizeof *list);
	// now put values into the new struct that's been added
	strcpy(list[*n - 1].name, name);
	list[*n - 1].quantity = q;
	return list;
}

struct item *
remove_inventory(struct item *list, size_t *n, char const *name)
{
	// first, search for 'name' in the list
	size_t pos = -1;
	for (size_t i = 0; i < *n; i++) {
		if (strcmp(list[i].name, name) == 0) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {	// searching for something that doesn't exist
		return list;
	}
	// next, shift the other elements down and resize the array
	memmove(&list[pos], &list[pos + 1],
		(*n - pos - 1) * sizeof *list);
	(*n)--;
	list = realloc(list, *n * sizeof *list);
	return list;
}

void
destroy_inventory(struct item *list)
{
	free(list);
}

