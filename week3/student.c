#include <stdio.h>
#include <string.h>	// for strcpy
#include <stdlib.h>	// for malloc

struct student {
	char name[20];
	int student_no;
};

static
struct student *
new_student(char const *name, int student_no)
{
	struct student *this = malloc(sizeof *this);
	strcpy(this->name, name);	// copies from name into this->name
	this->student_no = student_no;
	return this;
}

int
main(void)
{
	struct student s[3];
	for (int i = 0; i < sizeof s / sizeof *s; i++) {
		printf("Enter name %d\n", i + 1);
		fgets(s[i].name, sizeof s[i].name / sizeof *s[i].name, stdin);
		printf("Enter student number %d\n", i + 1);
		scanf("%d", &s[i].student_no);
		getchar();	// read in and ignore newline character
	}
	for (int i = 0; i < sizeof s / sizeof *s; i++) {
		printf("%d %s\n", s[i].student_no, s[i].name);
	}

	// just for testing out the new_student function/constructor
	struct student *s2 = new_student("Jane Jones", 12345);
	printf("%s %d\n", s2->name, s2->student_no);

	return 0;
}
