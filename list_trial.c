#include <stdio.h>
#include <assert.h>

#include "list.h"

int cmp_ints(const void* a, const void* b) {
	return *((int*)b) - *((int*)a);
}

int main(void) {
	int value1 = 6;
	list_node_t* node = list_create((void*)&value1, sizeof(int));
	assert(node);

	int value2 = 42;
	assert(list_add_node(node, (void*)&value2) == 0);
	assert(node->next != NULL);
	assert(*((int*)node->next->value) == 42);

	assert(list_remove_node(node, (void*)&value2, cmp_ints) == 0);
	assert(node->next == NULL);

	int value3 = 4;
	int value4 = 7;
	list_add_node(node, (void*)&value3);
	list_add_node(node, (void*)&value4);
	assert(list_remove_node(node, (void*)&value4, cmp_ints) == 0);
	assert(node->next != NULL);
	assert(node->next->next == NULL);
	assert(*((int*)node->next->value) == 4);

	assert(list_get_length(node) == 2);
	assert(*((int*)list_get_nth_node(node, 0)->value) == 6);
	assert(*((int*)list_get_nth_node(node, 1)->value) == 4);
	assert(list_get_nth_node(node, 2) == NULL);

	int value5 = -32;
	assert(list_get_by_value(node, (void*)&value1, cmp_ints) != NULL);
	assert(list_get_by_value(node, (void*)&value3, cmp_ints) != NULL);
	assert(list_get_by_value(node, (void*)&value5, cmp_ints) == NULL);
	list_free(node, NULL);
	return 0;
}

