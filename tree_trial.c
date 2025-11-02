#include <stdio.h>
#include <assert.h>
#include "tree.h"

int main(void) {
	node_t* root = tree_create(sizeof(int), (void*)42);
	assert(root);
	assert(root->value == (void*)42);
	assert(root->child == NULL);
	assert(root->sibling == NULL);

	node_t* node1 = node_add_child(root, (void*)37);
	assert(node1);
	assert(node1->value == (void*)37);
	assert(root->child == node1);
	assert(root->sibling == NULL);
	assert(node1->sibling == NULL);

	node_t* found_node = tree_find(root, (void*)37);
	assert(found_node == node1);

	tree_free(root, NULL);
	return 0;
}
