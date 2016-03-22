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



static
struct node *
immediate_predecessor(struct node *n)
{
	n = n->left;
	while (n->right != NULL) {
		n = n->right;
	}
	return n;
}

static
struct node *
remove_node(struct node *n, int x)
{
	if (n == NULL) {
		// value doesn't exist in this tree. do nothing
	} else if (x < n->data) {
		n->left = remove_node(n->left, x);
	} else if (x > n->data) {
		n->right = remove_node(n->right, x);
	} else if (x == n->data) {	// we found what needs to be removed!
		struct node *killed_node = n;
		if (n->left == NULL && n->right == NULL) {	// no children
			free(n);
			n = NULL;
		} else if (n->left == NULL && n->right != NULL) {
			n = n->right;
			free(killed_node);
		} else if (n->left != NULL && n->right == NULL) {
			n = n->left;
			free(killed_node);
		} else if (n->left != NULL && n->right != NULL) {
			struct node *pred = immediate_predecessor(n);
			// copy the data from the new root of this subtree
			n->data = pred->data;
			// remove the node that we just copied from
			n->left = remove_node(n->left, pred->data);
		}
	}
	return n;
}

void
remove_from_tree(struct tree *t, int x)
{
	t->root = remove_node(t->root, x);
}



static
void
free_node(struct node *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		free_node(n->left);
		free_node(n->right);
		free(n);
	}
}

void
free_tree(struct tree *t)
{
	free_node(t->root);
	t->root = NULL;
}



