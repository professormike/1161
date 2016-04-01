#include <stdio.h>

struct student {
	unsigned int name_hash;
	double grade;
};

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
insert_student(struct student *table, size_t table_size,
char const *student_name, double student_grade)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % table_size;
	table[position].name_hash = hash;
	table[position].grade = student_grade;
}

double
find_student(struct student const *table, size_t table_size,
char const *student_name)
{
	unsigned int hash = hash_string(student_name);
	size_t position = hash % table_size;
	if (table[position].name_hash == hash) {
		return table[position].grade;
	} else {
		return -1;	// signal that the grade wasn't found
	}
}

int
main(void)
{
	struct student hash_table[11];
#define ADD(nm, gr) insert_student(hash_table,	\
			sizeof hash_table / sizeof *hash_table, nm, gr)
#define GET(nm)	find_student(hash_table,	\
			sizeof hash_table / sizeof *hash_table, nm)
	ADD("Joe Smith", 80);
	ADD("Jane Jones", 75);
	ADD("Fred Flintstone", 40);
	ADD("Wilma Flintstone", 90);
	printf("Joe's mark: %lf\n", GET("Joe Smith"));
	printf("Jane's mark: %lf\n", GET("Jane Jones"));
	printf("Fred's mark: %lf\n", GET("Fred Flintstone"));
	printf("Wilma's mark: %lf\n", GET("Wilma Flintstone"));
	printf("Gary's mark: %lf\n", GET("Gary"));
	return 0;
}






