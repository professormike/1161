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

static
void
print_path(struct dijkstra_node const *n)
{
	if (n == NULL) {
		// do nothing
	} else {
		// recursing *BEFORE* printing stuff out will ensure the path
		// is printed in the opposite order that we traverse it
		print_path(n->parent);
		printf("%c with cost %d\n", n->node->label, n->cost);
	}
}

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
	for (size_t i = 0; i < num_nodes; i++) {
		// find the lowest-cost node that has not been visited yet
		// (using a linear search)
		int closest_unvisited = -1;	// there is nothing yet
		for (size_t j = 0; j < num_nodes; j++) {
			if (!table[j].visited && (closest_unvisited == -1
					|| table[j].cost < table[closest_unvisited].cost)) {
				closest_unvisited = j;
			}
		}

		// check to ensure we have found a closest unvisited node
		if (closest_unvisited == -1) {
			break;
		}

		table[closest_unvisited].visited = 1;
		for (size_t j = 0; j < num_nodes; j++) {
			if (edges[closest_unvisited][j] > 0) {	// edge to another node
				int cost_to_j = table[closest_unvisited].cost
					+ edges[closest_unvisited][j];
				if (cost_to_j < table[j].cost) {	// we've find a better
													// path to node j
					// update table to reflect that we've found a
					// lower cost path
					table[j].parent = &table[closest_unvisited];
					table[j].cost = cost_to_j;
				}
			}
		}
	}
	// 3. go through table backwards to find shortest path
	struct dijkstra_node const *ending_node = NULL;
	for (size_t i = 0; i < num_nodes; i++) {
		if (nodes[i].label == end) {
			ending_node = &table[i];
			break;
		}
	}
	print_path(ending_node);
}

int
main(void)
{
	// this graph is the same as the one used in the Dijkstra's algorithm
	// set of slides
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
	shortest_path(nodes, 7, adjacency_matrix, 'A', 'E');
	return 0;
}
