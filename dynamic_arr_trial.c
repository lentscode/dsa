#include <stdio.h>
#include "dynamic_arr.h"
#include <assert.h>

int main(void) {
	dynamic_arr_t* arr = dynamic_arr_create(sizeof(int), 0);
	assert(arr);
	assert(arr->capacity == 1);
	assert(arr->length == 0);

	assert(dynamic_arr_add(arr, (void*)34) == 0);
	assert(arr->capacity == 2);
	assert(arr->length == 1);

	assert(dynamic_arr_add(arr, (void*)36) == 0);
	assert(arr->capacity == 4);
	assert(arr->length == 2);

	assert(dynamic_arr_add(arr, (void*)2) == 0);
	assert(arr->capacity == 8);
	assert(arr->length == 3);

	assert(dynamic_arr_add(arr, (void*)-14) == 0);
	assert(arr->capacity == 8);
	assert(arr->length == 4);

	assert(dynamic_arr_remove(arr, (void*)2) == (void*)2);
	assert(arr->capacity == 8);
	assert(arr->length == 3);

	assert(dynamic_arr_remove(arr, (void*)5) == NULL);
	assert(arr->capacity == 8);
	assert(arr->length == 3);

	assert(dynamic_arr_remove_by_index(arr, 0) == (void*)34);
	assert(arr->capacity == 8);
	assert(arr->length == 2);

	printf("[");
	for (size_t i = 0; i < arr->length; i++) {
		printf("%d", (int)arr->arr[i]);	
		if (i < arr->length - 1) printf(", ");
	}
	printf("]\n");

	dynamic_arr_free(arr, NULL);

	return 0;
}
