#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

struct node {
	char data[20];
	struct node *next;
};
struct queue {
	struct node *head, *tail;
};

void
enqueue(struct queue *q, char const *s)
{
	struct node *new_node = malloc(sizeof *new_node);
	strncpy(new_node->data, s, sizeof new_node->data);
	new_node->next = NULL;
	if (q->tail == NULL) {	// the list is empty, so there's no head
							// or tail
		assert(q->head == NULL);
		q->head = new_node;
		q->tail = new_node;
	} else {
		q->tail->next = new_node;	// the current tail's next is
									// updated
		q->tail = new_node;
	}
}

void
serve(struct queue *q, char *output)
/*
 * 'q' is a pointer to the current queue structure. 'output' is
 * an array which this function will fill up with the data that
 * was stored in the head node's data. We cannot return a string
 * because returning strings is so difficult in C
 */
{
	assert(q != NULL);
	assert(q->head != NULL);
	assert(q->tail != NULL);
	strcpy(output, q->head->data);
	// now remove the head node from the queue
	struct node *old_head = q->head;
	q->head = old_head->next;
	free(old_head);
	if (q->head == NULL) {
		q->tail = NULL;
	}
}

int
main(void)
{
	char input[20];
	struct queue q = { .head = NULL, .tail = NULL };
	while (1) {
		printf(	"Enter +str to add a new string to the queue\n"
				"Enter - to serve a string from the queue\n");
		fgets(input, sizeof input, stdin);
		if (input[0] == '+') {
			enqueue(&q, &input[1]);	// &input[1] to skip over the '+'
		} else if (input[0] == '-') {
			serve(&q, input);
			printf("%s\n", input);
		}
	}
}








