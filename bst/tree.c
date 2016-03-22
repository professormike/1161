/*
 * Contains an implementation of all Binary Search Tree operations,
 * namely searching, inserting, removing and freeing
 */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *left, *right;
	int height;
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
void
calculate_height(struct node *n)
{
	int left = n->left == NULL ? 0 : n->left->height;
	int right = n->right == NULL ? 0 : n->right->height;
	if (right > left) {
		n->height = right + 1;
	} else {
		n->height = left + 1;
	}
}

static
int
balance_factor(struct node const *n)
{
	int left = n->left == NULL ? 0 : n->left->height;
	int right = n->right == NULL ? 0 : n->right->height;
	return right - left;
}

static
struct node *
rebalance(struct node *n)
{
	// LL imbalance
	if (balance_factor(n) == -2 && balance_factor(n->left) < +1) {
		// "before" diagram
		struct node * const x = n,
					* const y = x->left,
					* const d = x->right,
					* const z = y->left,
					* const c = y->right,
					* const a = z->left,
					* const b = z->right;
		// make it look like the "after" diagram
		y->left = z;
		y->right = x;
		z->left = a;
		z->right = b;
		x->left = c;
		x->right = d;
		// y is the new root node
		n = y;
	}
	return n;
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
	calculate_height(n);
	return rebalance(n);
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
	if (n != NULL) {
		calculate_height(n);
		n = rebalance(n);
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
print_node(struct node const *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		print_node(n->left);
		printf("%d\n", n->data);
		print_node(n->right);
	}
}

void
print_tree(struct tree const *t)
{
	print_node(t->root);
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



