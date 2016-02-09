#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
char *
read_string(void)
{
	char *p = malloc(sizeof *p);
	int i = 0;
	while (1) {
		p = realloc(p, i + 1);
		p[i] = getchar();
		i++;
		if (p[i - 1] == '\n') {
			p[i - 1] = '\0';
			return p;
		}
	}
}

int
main(void)
{
	char *password = read_string();
	char *confirm = read_string();
	if (strcmp(password, confirm) != 0) {
		fprintf(stderr, "those don't match\n");
		return 1;
	}
	int score = 0;
	for (int i = 0; password[i] != '\0'; i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			score += 2;
		} else if (password[i] >= 'a' && password[i] <= 'z') {
			score += 1;
		} else if (password[i] >= '0' && password[i] <= '9') {
			score += 1;
		} else if ((password[i] >= '!' && password[i] <= '/')
		|| (password[i] >= ';' && password[i] <= '@')) {
			score += 3;
		}
	}
	printf("Your password score is %d\n", score);
	return 0;
}


