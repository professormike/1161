#include <stdio.h>
#include <stdlib.h>

struct node {
	int is_word;
	struct node *children[26];
};
struct prefix_tree {
	struct node *root;
};

static
struct node *
insert_node(struct node *n, char const *s)
{
	if (n == NULL) {
		n = malloc(sizeof *n);
		for (int i = 0; i < 26; i++) {
			n->children[i] = NULL;
		}
		n->is_word = 0;
	}
	if (*s == '\0') {	// we've hit the end of the string
		n->is_word = 1;
	} else {
		int pos = *s - 'a';	// pos=0 for 'a', 1 for 'b', 2 for 'c',...
		n->children[pos] = insert_node(n->children[pos], s + 1);
	}
	return n;
}

void
insert(struct prefix_tree *t, char const *s)
{
	t->root = insert_node(t->root, s);
}

int
main(void)
{
	struct prefix_tree t = { .root = NULL };
	insert(&t, "ant");
	insert(&t, "aardvark");
	insert(&t, "bat");
	insert(&t, "bag");
	insert(&t, "bags");
	return 0;
}
