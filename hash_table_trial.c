#include "hash_table.h"

#include <assert.h>
#include <string.h>

int main(void) {
	hash_table* table = hash_table_create(sizeof(int), 2);
	assert(table);	

	int   value1 = 42;
	char* key1   = "foo";
	hash_table_element* e1 = hash_table_add(table, key1, (void*)&value1);
	assert(e1);
	int   value2 = 37;
	char* key2   = "bar";
	hash_table_element* e2 = hash_table_add(table, key2, (void*)&value2);
	assert(e2);

	hash_table_element* e3 = hash_table_find(table, key1);
	assert(e3);
	assert(strcmp(e3->key, e1->key) == 0);

	value1 = 43;
	hash_table_element* e1_mod = hash_table_add(table, key1, (void*)&value1);
	assert(e1_mod == e1);
	assert(*((int*)e1_mod->value) == 43);

	hash_table_remove(table, "bar");

	assert(hash_table_find(table, "bar") == NULL);
	
	hash_table_free(table, NULL);
	return 0;
}
