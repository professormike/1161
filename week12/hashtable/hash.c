#include "hash.h"
#include <stdio.h>

struct student {
	unsigned int name_hash;
	double grade;
};

#define TABLE_SIZE	5

static struct student table[TABLE_SIZE];

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
	table[position].name_hash = hash;
	table[position].grade = student_grade;
}

double
find_student(char const *student_name)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % TABLE_SIZE;
	if (table[position].name_hash == hash) {
		return table[position].grade;
	} else {
		return -1;	// signal that the grade wasn't found
	}
}

