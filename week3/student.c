#include <stdio.h>

struct student {
	char name[20];
	int student_no;
};

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
	return 0;
}
