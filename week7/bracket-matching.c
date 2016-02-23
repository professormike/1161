#include <stdio.h>
#include <stdlib.h>

struct node {
	char bracket;
	struct node *next;
};
struct stack {
	struct node *head;
};

void
push(struct stack *s, char b)
{
	struct node *new_node = malloc(sizeof *new_node);
	new_node->bracket = b;
	new_node->next = s->head;
	s->head = new_node;
}

char
pop(struct stack *s)
{
	if (s->head == NULL) {		// stack is empty
		return '\0';
	}
	struct node *old_head = s->head;
	char bracket_to_return = old_head->bracket;
	s->head = old_head->next;
	free(old_head);
	return bracket_to_return;
}

void
free_stack(struct stack *s)
{
	struct node *n = s->head;
	while (n != NULL) {
		struct node *next = n->next;
		free(n);
		n = next;
	}
}

int
brackets_match(char const *s)
{
	struct stack t = { .head = NULL };
	for (size_t i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&t, s[i]);
		} else if (s[i] == ')' && pop(&t) != '(') {
			free_stack(&t);
			return 0;	// mismatch
		} else if (s[i] == ']' && pop(&t) != '[') {
			free_stack(&t);
			return 0;
		} else if (s[i] == '}' && pop(&t) != '{') {
			free_stack(&t);
			return 0;
		}
	}
	int is_empty = t.head == NULL;
	free_stack(&t);
	return is_empty;
}

int
main(void)
{
	char input[100];
	while (1) {
		fgets(input, sizeof input, stdin);
		if (brackets_match(input)) {
			printf("The brackets match\n");
		} else {
			printf("The brackes do NOT match\n");
		}
	}
}
