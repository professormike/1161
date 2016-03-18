/*
 * Contains an implementation of all Binary Search Tree operations,
 * namely searching, inserting, removing and freeing
 */

#include "tree.h"
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

static
int
search_node(struct node const *n, int x)
{
	if (n == NULL) {
		return 0;	// false. It does not exist in the tree
	} else if (n->data == x) {
		return 1;	// true. We found it
	} else if (x < n->data) {
		return search_node(n->left, x);
	} else {
		return search_node(n->right, x);
	}
}

int
search_in_tree(struct tree const *t, int x)
{
	return search_node(t->root, x);
}


static
struct node *
insert_node(struct node *n, int x)
{
	if (n == NULL) {
		n = malloc(sizeof *n);
		n->data = x;
		n->left = NULL;
		n->right = NULL;
	} else if (x < n->data) {
		n->left = insert_node(n->left, x);
	} else if (x > n->data) {
		n->right = insert_node(n->right, x);
	} else if (x == n->data) {
		// it already exists in the tree, so do nothing!
	}
	return n;
}

void
insert_in_tree(struct tree *t, int x)
{
	t->root = insert_node(t->root, x);
}

