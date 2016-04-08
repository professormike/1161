#include <stdio.h>
#include <limits.h>	// for INT_MAX

struct node {
	char label;
};

struct dijkstra_node {
	struct node const *node;
	int visited;
	struct dijkstra_node *parent;
	int cost;
};

void
shortest_path(struct node const *nodes, size_t num_nodes,
int **edges, char start, char end)
{
	// 1. build initial table
	struct dijkstra_node table[num_nodes];
	for (size_t i = 0; i < num_nodes; i++) {
		table[i].node = &nodes[i];
		table[i].visited = 0;	// false
		table[i].parent = NULL;
		// the cost is 0 if this node is the start node
		// otherwise the cost is infinity (actually INT_MAX for ints)
		table[i].cost = nodes[i].label == start ? 0 : INT_MAX;
	}
	// 2. go through each iteration of Dijkstra's algorithm
	// 3. go through table backwards to find shortest path
}

int
main(void)
{
	struct node nodes[] =
		{ { 'A' }, { 'B' }, { 'C' }, { 'D' }, { 'E' }, { 'F' }, { 'G' } };
	int *adjacency_matrix[] = {
				//	A	B	C	D	E	F	G
		(int[]){	0,	-1,	-1,	20,	-1,	-1,	75	},	// A
		(int[]){	-1,	0,	-1,	-1,	-1,	-1,	-1	},	// B
		(int[]){	-1,	-1,	0,	-1,	5,	-1,	25	},	// C
		(int[]){	-1,	40,	-1,	0,	35,	10,	45	},	// D
		(int[]){	-1,	20,	-1,	-1,	0,	-1,	10	},	// E
		(int[]){	-1,	5,	15,	-1,	40,	0,	-1	},	// F
		(int[]){	-1,	-1,	-1,	-1,	-1,	-1,	-1	}	// G
	};
	shortest_path(nodes, 5, adjacency_matrix, 'A', 'E');
	return 0;
}
