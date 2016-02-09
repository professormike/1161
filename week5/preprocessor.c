#include <stdio.h>

#define PI 3.14159
#define MIN(x,y)	(x < y ? x : y)
#define until(x)	while(!(x))
#define count(v,st,end) for(int v = st; v < end; v++)

int
main(void)
{
	printf("%lf\n", MIN(PI, 4));
	int x = 5;
	until (x == 0) {
		printf("%d\n", x);
		x--;
	}
	count (i, 0, 5) {
	}
	return 0;
}
