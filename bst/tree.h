struct node;
struct tree {
	struct node *root;
};

// returns true (1) if the given int exists in the tree and returns
// false (0) otherwise
int search_in_tree(struct tree const *, int);

// adds a new int to the tree of ints
void insert_in_tree(struct tree *, int);

// removes the given int from an existing tree
void remove_from_tree(struct tree *, int);

// print out all nodes in a tree, in order (sorted)
void print_tree(struct tree const *);

// deallocates all nodes contained within a tree
void free_tree(struct tree *);
