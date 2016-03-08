#include <stdio.h>

void
move_cards(int from, int to, int num_cards)
{
	if (num_cards == 1) {
		printf("move from %d to %d\n", from, to);
	} else {
		int other = from != 1 && to != 1 ? 1 :
			from != 2 && to != 2 ? 2 :
			3;
		move_cards(from, other, num_cards - 1);
		move_cards(from, to, 1);
		move_cards(other, to, num_cards - 1);
	}
}

int
main(void)
{
	int num_cards;
	scanf("%d", &num_cards);
	move_cards(1, 2, num_cards);
	return 0;
}
