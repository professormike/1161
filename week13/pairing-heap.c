#include <stdlib.h>

struct heap {
	int value;
	size_t num_children;
	struct heap **children;
};

static
void
add_child(struct heap *h, struct heap *other)
{
	h->children = realloc(h->children, ++h->num_children * sizeof *h->children);
	h->children[h->num_children - 1] = other;
}

void *
empty_heap(void)
{
	return NULL;
}

void *
insert(void *h_, int new_value)
{
	struct heap *h = h_;
	if (h == NULL) {
		h = malloc(sizeof *h);
		h->value = new_value;
		h->num_children = 0;
		h->children = NULL;
	} else if (h->value > new_value) {
		add_child(h, insert(NULL, new_value));
	} else {
		struct heap *new_root = insert(NULL, new_value);
		add_child(new_root, h);
		h = new_root;
	}
	return h;
}

int
get_maximum(void const *h_)
{
	struct heap const *h = h_;
	return h->value;
}

static
struct heap *
merge_pairs(struct heap **heaps, size_t num_heaps)
{
	if (num_heaps == 0) {
		return NULL;
	} else if (num_heaps == 1) {
		return heaps[0];
	} else {
		size_t next_round_size = (num_heaps + 1) / 2;
		struct heap *next_round[next_round_size];
		for (size_t i = 0; i < next_round_size; i++) {
			size_t first = i * 2, second = i * 2 + 1;
			if (second >= num_heaps) {
				next_round[i] = heaps[first];
			} else if (heaps[first]->value > heaps[second]->value) {
				add_child(heaps[first], heaps[second]);
				next_round[i] = heaps[first];
			} else {
				add_child(heaps[second], heaps[first]);
				next_round[i] = heaps[second];
			}
		}
		return merge_pairs(next_round, next_round_size);
	}
}

void *
remove_maximum(void *h_)
{
	struct heap *h = h_;
	struct heap *new_root = merge_pairs(h->children, h->num_children);
	free(h->children);
	free(h);
	return new_root;
}

void
free_heap(void *h_)
{
	struct heap *h = h_;
	for (size_t i = 0; i < h->num_children; i++) {
		free_heap(h->children[i]);
	}
	free(h->children);
	free(h);
}
