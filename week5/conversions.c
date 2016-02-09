#include <stdio.h>

static
void
convert(int wtc, double value, double *converted)
{
	if (wtc == 1) {
		*converted = value * 2.2;
	} else if (wtc == 2) {
		*converted = value * 9 / 5.0 + 32;
	} else if (wtc == 3) {
		*converted = value * 28.34;
	}
}

int
main(void)
{
	double value;
	int what_to_convert;
	double converted;
	printf("Enter value you want to convert:\n");
	scanf("%lf", &value);
	printf(	"(1) kilograms to pounds\n"
			"(2) Celsius to Farhenheit\n"
			"(3) ounces to grams\n");
	scanf("%d", &what_to_convert);
	convert(what_to_convert, value, &converted);
	printf("%lf\n", converted);
	return 0;
}
