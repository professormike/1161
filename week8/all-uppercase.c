#include <stdio.h>
#include <ctype.h>

void
print_all_uppercase(char const *s)
{
	if (*s == '\0') {
		// do nothing
	} else {
		putchar(toupper(*s));
		print_all_uppercase(s + 1);
	}
}

int
main(void)
{
	char line[100];
	fgets(line, sizeof line, stdin);
	print_all_uppercase(line);
	return 0;
}
