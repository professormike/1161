#include <stdio.h>

int
main(void)
{
	char names[3][20];
	for (int i = 0; i < sizeof names / sizeof *names; i++) {
		printf("Enter name %d\n", i);
		fgets(names[i], sizeof names[i] / sizeof *names[i], stdin);
	}
	for (int i = 0; i < sizeof names / sizeof *names; i++) {
		printf("%s\n", names[i]);
	}
	return 0;
}
