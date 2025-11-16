#include <assert.h>
#include "bst.h"

int cmp_ints(const void* a, const void*b) {
	return *(int*)b - *(int*)a;
}

int main(void) {
	int value1 = 32;
	bst_node_t* root = bst_create((void*)&value1, sizeof(int));
	assert(root);

	int value2 = 16;
	bst_node_t* node2 = bst_add(root, (void*)&value2, cmp_ints);
	assert(node2);
	assert(root->left == node2);

	int value3 = 24;
	bst_node_t* node3 = bst_add(root, (void*)&value3, cmp_ints);
	assert(node3);
	assert(node2->right == node3);
	
	bst_node_t* node_found = bst_search(root, (void*)&value2, cmp_ints);
	assert(node_found == node2);

	int value4 = -1;
	bst_node_t* node_not_found = bst_search(root, (void*)&value4, cmp_ints);
	assert(!node_not_found);

	return 0;
}
