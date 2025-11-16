#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

#define HASH_TABLE_DEFAULT_ARR_SIZE 1028

typedef struct {
	char* key;
	void* value;
} hash_table_element;

typedef struct {
	hash_table_element* arr;
	size_t              e_size;
	size_t              capacity;
} hash_table;

hash_table* hash_table_create(size_t e_size, size_t capacity);
hash_table_element* hash_table_add(hash_table* table, char* key, void* value);
hash_table_element* hash_table_find(hash_table* table, char* key);
void hash_table_remove(hash_table* table, char* key);
void hash_table_free(hash_table* table, void (*free_value)(const void*));

#endif // HASHTABLE_H
