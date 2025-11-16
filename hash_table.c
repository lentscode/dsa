#include "hash_table.h"

#include <string.h>
#include <stdio.h>

unsigned long _hash_key(char* key) {
	unsigned long sum = 0;
	for (size_t i = 0; key[i] != '\0'; i++) {
		sum += i * key[i];
	}

	return sum;
}

hash_table* hash_table_create(size_t e_size, size_t capacity) {
	if (!e_size) return NULL;

	hash_table* table = (hash_table*)malloc(sizeof(hash_table));
	if (!table) return NULL;

	table->e_size   = e_size;
	table->capacity = capacity == 0 ? HASH_TABLE_DEFAULT_ARR_SIZE : capacity;
	table->arr      = (hash_table_element*)malloc(sizeof(hash_table_element)*table->capacity);
	if (!table->arr) {
		free(table);
		return NULL;
	}

	return table;
}

hash_table_element* hash_table_add(hash_table* table, char* key, void* value) {
	if (!table || !key || !value) return NULL;

	size_t e_index = _hash_key(key) % table->capacity;
	printf("[hash_table_add] hash of '%s': %zu\n", key, e_index);
	for (size_t i = 0; i < table->capacity; i++) {
		size_t index = e_index + i % table->capacity;
		if (table->arr[index].key && strcmp(table->arr[index].key, key) != 0) continue;

		printf("[hash_table_add] inserting element at index: %zu\n", index);

		if (!table->arr[index].key) {
			table->arr[index].key = strdup(key);
			if (!table->arr[index].key) return NULL;

			table->arr[index].value = malloc(table->e_size);
			if (!table->arr[index].value) {
				free(table->arr[index].key);
				return NULL;
			}
		}

		memcpy(table->arr[index].value, value, table->e_size);
		return table->arr + index;
	}

	return NULL;
}

hash_table_element* hash_table_find(hash_table* table, char* key) {
	if (!table || !key) return NULL;

	size_t e_index = _hash_key(key) % table->capacity;
	for (size_t i = 0; i < table->capacity; i++) {
		size_t index = e_index + i % table->capacity;
		if (!table->arr[index].key) continue;

		if (strcmp(table->arr[index].key, key) != 0) continue;

		printf("[hash_table_find] found element with key '%s' at index: %zu\n", key, index);
		return table->arr + index;
	}

	printf("[hash_table_find] element with key '%s' not found\n", key);
	return NULL;
}

void hash_table_remove(hash_table* table, char* key) {
	if (!table || !key) return;

	size_t e_index = _hash_key(key) % table->capacity;
	for (size_t i = 0; i < table->capacity; i++) {
		size_t index = e_index + i % table->capacity;
		if (!table->arr[index].key) continue;

		if (strcmp(table->arr[index].key, key) != 0) continue;

		printf("[hash_table_find] removing element with key '%s' at index: %zu\n", key, index);
		free(table->arr[index].key);
		table->arr[index].key = NULL;
		free(table->arr[index].value);
		table->arr[index].value = NULL;
	}
}

void hash_table_free(hash_table* table, void (*free_value)(const void*)) {
	for (size_t i = 0; i < table->capacity; i++) {
		hash_table_element* e = table->arr + i;	

		free(e->key);
		if (free_value) free_value(e->value);
	}

	free(table->arr);
	free(table);
}
