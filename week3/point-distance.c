#include <stdio.h>
#include <math.h>

struct point {
	double x;
	double y;
};

static
double
distance(struct point p1, struct point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int
main(void)
{
	struct point p1, p2;
	printf("Enter in (x, y) for point #1\n");
	scanf("( %lf , %lf )", &p1.x, &p1.y);
	printf("Enter in (x, y) for point #2\n");
	scanf(" ( %lf , %lf )", &p2.x, &p2.y);

	printf("Point 1 is at (%lf, %lf) and point 2 is at (%lf, %lf)\n",
		p1.x, p1.y, p2.x, p2.y);
	
	printf("The distance between them is %lf\n", distance(p1, p2));

	return 0;
}






