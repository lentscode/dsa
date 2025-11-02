#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct node {
	size_t       e_size;
	void*        value;
	struct node* child;
	struct node* sibling;
} node_t;

node_t* tree_create(size_t e_size, void* value);
node_t* node_add_child(node_t* node, void* value);
node_t* tree_find(node_t* root, void* value);
void tree_free(node_t* root, void (*free_value)(void*));

#endif //TREE_H
