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

static
int
is_in_node(struct node const *n, char const *s)
{
	if (n == NULL) {
		return 0;
	} else if (*s == '\0') {
		return n->is_word;
	} else {
		int pos = *s - 'a';	// pos=0 for 'a', 1 for 'b', 2 for 'c',...
		return is_in_node(n->children[pos], s + 1);
	}
}

int
is_in_tree(struct prefix_tree const *t, char const *s)
/*
 * returns 1 if 's' exists in the prefix tree 't'
 * returns 0 otherwise
 */
{
/*
	struct node const *n = t->root;
	for (size_t i = 0; s[i] != '\0'; i++) {
		int pos = s[i] - 'a';	// pos=0 for 'a', 1 for 'b', ...
		if (n == NULL) {
			return 0;	// not in the tree if the node is null
		}
		n = n->children[pos];
	}
	return n != NULL && n->is_word;
*/
	return is_in_node(t->root, s);
}

static
void
destroy_nodes(struct node *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		for (int i = 0; i < 26; i++) {
			destroy_nodes(n->children[i]);
		}
		free(n);
	}
}

void
destroy_tree(struct prefix_tree *t)
{
	destroy_nodes(t->root);
}

static
struct node const *
find_prefix(struct node const *n, char const *p)
{
	if (n == NULL) {
		return NULL;
	} else if (*p == '\0') {
		return n;
	} else {
		int pos = *p - 'a';	// pos=0 for 'a', 1 for 'b',...
		return find_prefix(n->children[pos], p + 1);
	}
}

static
int
words_descended_from(struct node const *n)
{
	if (n == NULL) {
		return 0;
	} else {
		int num_words = 0;
		for (int i = 0; i < 26; i++) {
			num_words += words_descended_from(n->children[i]);
		}
		if (n->is_word) {
			num_words++;
		}
		return num_words;
	}
}

int
words_begin_with(struct prefix_tree const *t, char const *prefix)
{
	// find the node corresponding with the prefix
	struct node const *start_point = find_prefix(t->root, prefix);
	if (start_point == NULL) {
		return 0;
	}
	return words_descended_from(start_point);
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
	printf("ba in tree? %d\n", is_in_tree(&t, "ba"));
	printf("bag in tree? %d\n", is_in_tree(&t, "bag"));
	printf("xylophone in tree? %d\n", is_in_tree(&t, "xylophone"));
	printf("%d words begin with b\n",
		words_begin_with(&t, "b"));
	destroy_tree(&t);
	return 0;
}
