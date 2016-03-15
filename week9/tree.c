#include <stdio.h>

struct node {
	int value;
	struct node *left, *right;
};

struct tree {
	struct node *root;
};

int
search_node(struct node const *n, int x)
{
	if (n == NULL) {
		return 0;	// false. It does not exist in the tree
	} else if (n->value == x) {
		return 1;	// true. We found it
	} else if (x < n->value) {
		return search_node(n->left, x);
	} else {
		return search_node(n->right, x);
	}
}

int
search_tree(struct tree const *t, int x)
{
	return search_node(t->root, x);
}

int
main(void)
{
	struct node a = { .value = 1, .left = NULL, .right = NULL };
	struct node c = { .value = 7, .left = NULL, .right = NULL };
	struct node b = { .value = 3, .left = &a, .right = &c };
	struct node e = { .value = 12, .left = NULL, .right = NULL };
	struct node g = { .value = 31, .left = NULL, .right = NULL };
	struct node f = { .value = 26, .left = &e, .right = &g };
	struct node d = { .value = 9, .left = &b, .right = &f };
	struct tree t = { .root = &d };
	int x;
	printf("What number do you want to find?\n");
	scanf("%d", &x);
	if (search_tree(&t, x)) {
		printf("It's there!\n");
	} else {
		printf("It's not there :(\n");
	}
	return 0;
}
