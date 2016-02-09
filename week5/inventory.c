#include <stdio.h>
#include <string.h>

struct item {
	char name[20];
	int quantity;
};

int
main(void)
{
	struct item k[3];
	int num_items = 0;
	char c;
	while (1) {
		printf("%d items in inventory\n", num_items);
		for (int i = 0; i < num_items; i++) {
			printf("%d %s", k[i].quantity, k[i].name);
		}

		printf(	"+ to add to inventory\n"
				"- to remove from inventory\n"
				"q to quit\n");
		scanf(" %c", &c);
		getchar();	// read in newline
		if (c == '+') {
			printf("Inventory name?\n");
			fgets(k[num_items].name, sizeof k[num_items].name, stdin);
			printf("Quantity?\n");
			scanf("%d", &k[num_items].quantity);
			num_items++;
		} else if (c == '-') {
			int remove_pos;
			printf("Which item number to remove?\n");
			scanf("%d", &remove_pos);
			/* this is what we would like to do:
			for (int i = remove_pos; i < num_items - 1; i++) {
				k[i] = k[i + 1];
			}
			*/
			// what we have to do: (it shifts memory to a new
			// position within the array
			memmove(&k[remove_pos], &k[remove_pos + 1],
				(num_items - remove_pos - 1) * sizeof *k);
			num_items--;
		} else if (c == 'q') {
			break;
		}
	}
	return 0;
}
