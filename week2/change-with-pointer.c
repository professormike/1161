#include <stdio.h>

int
main(void)
{
	double x, y;
	printf("Please enter in values for x and y:\n");
	if (scanf("%lf %lf", &x, &y) == 2) {
		printf("Do you want to change number 1 or number 2?\n");
		int which_number;
		if (scanf("%d", &which_number) == 1) {
			double *z;
			if (which_number == 1) {
				z = &x;
			} else {
				z = &y;
			}
			*z = 0;
			printf(	"x = %lf, y = %lf, *z = %lf\n"
					"&x = %p, &y = %p, z = %p\n",
				x, y, *z, &x, &y, z);
		} else {
			fprintf(stderr, "Bad input\n");
			return 1;
		}
	} else {
		fprintf(stderr, "Bad input\n");
		return 1;
	}
	return 0;
}
