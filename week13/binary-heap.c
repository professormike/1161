/*
 * Binary heap, represented as an array
 */

#include <stdlib.h>

struct heap {
	size_t size;
	int *elements;
};

static
size_t
parent_of(size_t position)
{
	return (position - 1) / 2;
}

static
size_t
left_child(size_t position)
{
	return 2 * position + 1;
}

static
size_t
right_child(size_t position)
{
	return 2 * position + 2;
}

static
void
swap(struct heap *h, size_t pa, size_t pb)
{
	int temp = h->elements[pa];
	h->elements[pa] = h->elements[pb];
	h->elements[pb] = temp;
}

void *
empty_heap(void)
{
	struct heap *h = malloc(sizeof *h);
	h->size = 0;
	h->elements = NULL;
	return h;
}

void *
insert(void *h_, int new_value)
{
	struct heap *h = h_;
	h->elements = realloc(h->elements, ++h->size * sizeof *h->elements);
	size_t position = h->size - 1;
	h->elements[position] = new_value;
	// begin the heapify-up operation
	while (position != 0) {
		size_t p = parent_of(position);
		if (h->elements[p] < h->elements[position]) {
			swap(h, p, position);
		}
		position = p;
	}
	return h;
}

int
get_maximum(void const *h_)
{
	struct heap const *h = h_;
	return h->elements[0];
}

void *
remove_maximum(void *h_)
{
	struct heap *h = h_;
	if (--h->size == 0) {	// the heap is now empty
		free(h->elements);
	} else {
		h->elements[0] = h->elements[h->size];
		h->elements = realloc(h->elements, h->size * sizeof *h->elements);
		// begin the heapify-down operation
		size_t position = 0;
		while (left_child(position) < h->size) {
			size_t const lc = left_child(position), rc = right_child(position);
			size_t biggest_child = rc >= h->size ? lc
				: h->elements[lc] > h->elements[rc] ? lc : rc;
			if (h->elements[biggest_child] > h->elements[position]) {
				swap(h, biggest_child, position);
			}
			position = biggest_child;
		}
	}
	return h;
}

void
free_heap(void *h_)
{
	struct heap *h = h_;
	free(h->elements);
	free(h);
}
