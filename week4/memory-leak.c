#include <stdio.h>
#include <stdlib.h>	// for malloc
#include <string.h>	// for strlen

char *
read_name(void)
{
	char *name = malloc(100);
	fgets(name, 100, stdin);
	return name;
}

int
main(void)
{
	char *n = NULL;
	do {
		if (n != NULL) {
			free(n);
		}
		printf("Please enter your name: ");
		n = read_name();
		printf("Your name is %s\n", n);
	} while (strlen(n) > 1);
	return 0;
}
