/*
 * Implementation of a hash table with linear probing
 */

#include "hash.h"
#include <stdio.h>

struct student {
	int taken;	// 1 if this element is taken; 0 if it's empty
	unsigned int name_hash;
	double grade;
};

#define TABLE_SIZE	5

// = { 0 } initializes the whole table to be empty
static struct student table[TABLE_SIZE] = { 0 };

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
	for (size_t i = 0; i < TABLE_SIZE; i++) {
		size_t p = (position + i) % TABLE_SIZE;
		if (!table[p].taken) {
			table[p].name_hash = hash;
			table[p].grade = student_grade;
			table[p].taken = 1;
			return;
		}
	}
}

double
find_student(char const *student_name)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % TABLE_SIZE;
	for (size_t i = 0; i < TABLE_SIZE; i++) {
		size_t p = (position + i) % TABLE_SIZE;
		if (table[p].name_hash == hash) {
			return table[p].grade;
		}
	}	
	return -1;	// signal that the grade wasn't found
}

