#include <stdlib.h>
#include <stdio.h>

struct node {
	double data;
	struct node *next;
};

struct linked_list {
	struct node *head;
};

// functions dealing with appending

static
struct node *
append_node(struct node *n, double v)
{
	if (n == NULL) {
		n = malloc(sizeof *n);
		n->data = v;
		n->next = NULL;
	} else {
		n->next = append_node(n->next, v);
	}
	return n;
}

void
append(struct linked_list *l, double v)
{
	l->head = append_node(l->head, v);
}

// functions dealing with removing

static
struct node *
remove_node(struct node *n, double v)
{
	if (n == NULL) {
		return NULL;
	} else if (n->data == v) {
		struct node *next = n->next;
		free(n);
		return remove_node(next, v);
	} else {
		n->next = remove_node(n->next, v);
		return n;
	}
}

void
remove_data(struct linked_list *l, double v)
{
	l->head = remove_node(l->head, v);
}

// functions dealing with printing

static
void
print_node(struct node const *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		printf("%lf ", n->data);
		print_node(n->next);
	}
}

void
print(struct linked_list const *l)
{
	print_node(l->head);
	printf("\n");
}

// functions dealing with freeing

static
void
free_node(struct node *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		struct node *next = n->next;
		free(n);
		free_node(next);
	}
}

void
free_list(struct linked_list *l)
{
	free_node(l->head);
}

int
main(void)
{
	struct linked_list l = { .head = NULL };
	append(&l, 4.5);
	append(&l, 2.5);
	append(&l, 6);
	remove_data(&l, 2.5);
	append(&l, 4.5);
	append(&l, 9);
	remove_data(&l, 4.5);
	print(&l);
	free_list(&l);
	return 0;
}
