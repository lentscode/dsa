#ifndef DYNAMICARR_H
#define DYNAMICARR_H

#include <stdlib.h>

typedef struct {
	void** arr;
	size_t e_size;
	size_t capacity;
	size_t length;
} dynamic_arr_t;

dynamic_arr_t* dynamic_arr_create(
	size_t e_size,
	size_t initial_capacity
);
int dynamic_arr_add(
	dynamic_arr_t* arr,
	void*          element
);
void* dynamic_arr_find(
	dynamic_arr_t* arr,
	void*          element
);
void* dynamic_arr_remove(
	dynamic_arr_t* arr,
	void*          element
);
void* dynamic_arr_remove_by_index(
	dynamic_arr_t* arr,
	size_t         index
);
void dynamic_arr_free(dynamic_arr_t* arr, void (*free_value)(void*));

#endif
