#include <stdio.h>

static
int
calc(int y1, int month1, int d1, int h1, int m1, int s1,
int y2, int month2, int d2, int h2, int m2, int s2)
{
	int t1 = y1;
	t1 = t1 * 12 + month1;
	t1 = t1 * 30 + d1;
	t1 = t1 * 24 + h1;
	t1 = t1 * 60 + m1;
	t1 = t1 * 60 + s1;
	int t2 = y2;
	t2 = t2 * 12 + month2;
	t2 = t2 * 30 + d2;
	t2 = t2 * 24 + h2;
	t2 = t2 * 60 + m2;
	t2 = t2 * 60 + s2;
	return (t2 - t1) / 60 / 60;
}

int
main(void)
{
	int y1, mm1, d1, h1, m1, s1;
	printf("Enter time 1 in format yy/mm/dd hh:mm:ss\n");
	scanf("%d/%d/%d %d:%d:%d", &y1, &mm1, &d1, &h1, &m1, &s1);
	int y2, mm2, d2, h2, m2, s2;
	printf("Enter time 2 in format yy/mm/dd hh:mm:ss\n");
	scanf("%d/%d/%d %d:%d:%d", &y2, &mm2, &d2, &h2, &m2, &s2);
	printf("Those times are %d hours apart\n",
		calc(y1, mm1, d1, h1, m1, d1, y2, mm2, d2, h2, m2, s2));
	return 0;
}





