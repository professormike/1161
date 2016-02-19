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
/*
 * Prints out each element in the linked list pointed to be 'l',
 * starting from the head of the list
 */
{
	for (struct node const *current_node = l->head;
			current_node != NULL;
			current_node = current_node->next) {
		printf("%d ", current_node->data);
	}
	printf("\n");
}

void
free_list(struct linked_list *l)
{
	struct node *current_node = l->head;
	while (current_node != NULL) {
		struct node *next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}

void
remove_from_list(struct linked_list *l, int value)
/*
 * searches for 'value' in the list and removes that node, if it's
 * found
 */
{
	while (l->head->data == value) {
		struct node *new_head = l->head->next;
		free(l->head);
		l->head = new_head;
		if (l->head == NULL) {
			return;
		}
	}
	struct node *current_node = l->head;
	while (current_node->next != NULL) {
		if (current_node->next->data == value) {
			struct node *to_be_killed = current_node->next;
			current_node->next = to_be_killed->next;
			free(to_be_killed);
		} else {
			current_node = current_node->next;
		}
	}
}

int
main(void)
{
	struct linked_list list = { .head = NULL };
	add_to_list(&list, 6);
	add_to_list(&list, 6);
	add_to_list(&list, 5);
	add_to_list(&list, 6);
	add_to_list(&list, 6);
	add_to_list(&list, 7);
	add_to_list(&list, 8);
	add_to_list(&list, 6);
	remove_from_list(&list, 6);
	remove_from_list(&list, 6);
	print_list(&list);
	free_list(&list);
	return 0;
}



