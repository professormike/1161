/*
 * Implementation of a hash table with chaining (linked list)
 */

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

struct linked_list_node {
	unsigned int name_hash;
	double grade;
	struct linked_list_node *next;
};

struct table_entry {
	struct linked_list_node *head;
};

#define TABLE_SIZE	5

// = { 0 } initializes the whole table to be empty
static struct table_entry table[TABLE_SIZE] = { 0 };

static
unsigned int
hash_string(char const *x)
// courtesy of Clifton
{
	unsigned int s = 0;
	int fiba = 1;
	int fibb = 1;
	for (size_t i = 1; x[i] != '\0'; i++) {
		s += x[i] * fibb;
		int c = fiba + fibb;
		fiba = fibb;
		fibb = c;
	}
	return s;
}

void
insert_student(char const *student_name, double student_grade)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % TABLE_SIZE;
	struct table_entry *e = &table[position];
	struct linked_list_node *new_node = malloc(sizeof *new_node);
	new_node->name_hash = hash;
	new_node->grade = student_grade;
	new_node->next = e->head;
	e->head = new_node;
}

double
find_student(char const *student_name)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % TABLE_SIZE;
	struct table_entry const *e = &table[position];
	struct linked_list_node const *n = e->head;
	while (n != NULL) {
		if (n->name_hash == hash) {
			return n->grade;
		} else {
			n = n->next;
		}
	}
	return -1;
}

