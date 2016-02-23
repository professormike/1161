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
	struct node *old_head = s->head;
	char bracket_to_return = old_head->bracket;
	s->head = old_head->next;
	free(old_head);
	return bracket_to_return;
}

int
brackets_match(char const *s)
// FIXME: memory leak if a mismatch is found
{
	struct stack t = { .head = NULL };
	for (size_t i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&t, s[i]);
		} else if (s[i] == ')' && pop(&t) != '(') {
			return 0;	// mismatch
		} else if (s[i] == ']' && pop(&t) != '[') {
			return 0;
		} else if (s[i] == '}' && pop(&t) != '{') {
			return 0;
		}
	}
	return t.head == NULL;	// return true if the stack is now empty
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
