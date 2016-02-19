#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct linked_list {
	struct node *head;
};

void
add_to_list(struct linked_list *l, int x)
/*
 * Add the integer 'x' as a new element at the beginning of the
 * list 'l'
 */
{
	struct node *new_node = malloc(sizeof *new_node);
	new_node->data = x;
	new_node->next = l->head;
	l->head = new_node;
}

void
print_list(struct linked_list const *l)
{
	struct node const *current_node = l->head;
	while (current_node != NULL) {
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
}

int
main(void)
{
	struct linked_list list = { .head = NULL };
	add_to_list(&list, 5);
	add_to_list(&list, 6);
	add_to_list(&list, 7);
	add_to_list(&list, 8);
	print_list(&list);
	return 0;
}



