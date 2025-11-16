#ifndef BST_H
#define BST_H

#include <stdlib.h>

typedef struct node {
	void*        value;
	size_t       e_size;
	struct node* father;
	struct node* left;
	struct node* right;
} bst_node_t;

bst_node_t* bst_create(void* value, size_t e_size);
bst_node_t* bst_add(bst_node_t* tree, void* value, int (*cmp)(const void*, const void*));
bst_node_t* bst_remove(bst_node_t* root, void* value, int (*cmp)(const void*, const void*));
bst_node_t* bst_search(bst_node_t* root, void* value, int (*cmp)(const void*, const void*));
bst_node_t* bst_max(bst_node_t* root);
bst_node_t* bst_pred(bst_node_t* node);

#endif // BST_H
