#ifndef INVENTORY_H
#define INVENTORY_H

struct item {
	char name[20];
	int quantity;
};

struct item *empty_inventory(size_t *);
struct item *add_inventory(struct item *, size_t *,
	char const *, int);
struct item *remove_inventory(struct item *, size_t *, char const *);
void destroy_inventory(struct item *);

#endif
