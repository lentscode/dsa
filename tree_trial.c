#include <stdio.h>
#include <assert.h>
#include "tree.h"

int nodes_sum = 0;

void operate(const void* value) {
	int* int_ptr = (int*)value;

	nodes_sum += *int_ptr;
}

int cmp_ints(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main(void) {
	int value1 = 42;
	node_t* root = tree_create(sizeof(int), (void*)&value1);
	assert(root);
	assert(*((int*)root->value) == value1);
	assert(root->child == NULL);
	assert(root->sibling == NULL);

	int value2 = 37;
	node_t* node1 = node_add_child(root, (void*)&value2);
	assert(node1);
	assert(*((int*)node1->value) == value2);
	assert(root->child == node1);
	assert(root->sibling == NULL);
	assert(node1->sibling == NULL);

	node_t* found_node = tree_find(root, (void*)&value2, cmp_ints);
	assert(found_node == node1);

	tree_bfs(root, operate);
	assert(nodes_sum == 42 + 37);
	nodes_sum = 0;
	tree_dfs(root, operate);
	assert(nodes_sum == 42 + 37);
	nodes_sum = 0;
	tree_recursive(root, operate);
	assert(nodes_sum == 42 + 37);

	tree_free(root, NULL);
	return 0;
}
