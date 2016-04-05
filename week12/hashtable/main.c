#include "hash.h"
#include <stdio.h>

int
main(void)
{
#define ADD(nm, gr) insert_student(nm, gr)
#define GET(nm)	find_student(nm)
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

