#include <stdio.h>

struct node {
	char label;
};

static
void
reach(struct node const *nodes, size_t num_nodes,
int **matrix, int node_position, int *reached)
{
	if (reached[node_position] == 1) {	// already visited this node
		// do nothing
	} else {
		printf("%c\n", nodes[node_position].label);
		reached[node_position] = 1;
		for (size_t i = 0; i < num_nodes; i++) {
			if (matrix[node_position][i] > 0) {
				reach(nodes, num_nodes, matrix, i, reached);
			}
		}
	}
}

void
reachable_from(struct node const *nodes, size_t num_nodes,
int **matrix, int node_position)
{
	int reached[num_nodes];
	// initialize everything to be 0 (false) saying we haven't
	// reached it yet
	for (size_t i = 0; i < num_nodes; i++) {
		reached[i] = 0;
	}
	reach(nodes, num_nodes, matrix, node_position, reached);
}

int
main(void)
{
	struct node nodes[] =
		{ { 'A' }, { 'B' }, { 'C' }, { 'D' }, { 'E' } };
	int *adjacency_matrix[] = {
				//	A	B	C	D	E
		(int[]){ 	0,	10,	5,	15,	30	},	// A
		(int[]){	-1,	0,	-1,	-1,	15	},	// B
		(int[]){	-1,	-1,	0,	20,	-1	},	// C
		(int[]){	-1,	-1,	10,	0,	30	},	// D
		(int[]){	-1,	-1,	-1,	50,	0	}	// E
	};
	reachable_from(nodes, 5, adjacency_matrix, 0);
}
