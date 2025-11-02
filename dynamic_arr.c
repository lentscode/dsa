#include "dynamic_arr.h"

int _dynamic_arr_increase_size(dynamic_arr_t* arr);
int _dynamic_arr_decrease_size(dynamic_arr_t* arr);

dynamic_arr_t* dynamic_arr_create(
	size_t e_size,
	size_t initial_capacity
) {
	if (!e_size) return NULL;

	dynamic_arr_t* dyn_arr = (dynamic_arr_t*)malloc(sizeof(dynamic_arr_t));
	if (!dyn_arr) return NULL;
	if (!initial_capacity) initial_capacity = 1;

	dyn_arr->e_size   = e_size;
	dyn_arr->capacity = initial_capacity;
	dyn_arr->length   = 0;
	dyn_arr->arr      = (void**)malloc(e_size*initial_capacity);
	if (!dyn_arr->arr) return NULL;

	return dyn_arr;
}

void dynamic_arr_free(dynamic_arr_t* arr, void (*free_value)(void*)) {
	if (free_value)
		for (size_t i = 0; i < arr->length; i++) 
			free_value(arr->arr[i]);

	free(arr->arr);
	free(arr);
}

int dynamic_arr_add(
	dynamic_arr_t* arr,
	void*          element
) {
	if (++(arr->length) > arr->capacity / 2 && _dynamic_arr_increase_size(arr) != 0) return -1;
		
	arr->arr[arr->length - 1] = element;
	return 0;
}

void* dynamic_arr_remove(
	dynamic_arr_t* arr,
	void*          element
) {
	void* removed_e = NULL;
	for (size_t i = 0; i < arr->length; i++) {
		if (arr->arr[i]	!= element) continue;
		removed_e = arr->arr[i];
		
		for (size_t j = i; j < arr->length - 1; j++) {
			arr->arr[j] = arr->arr[j + 1];
		}
		break;
	}
	if (!removed_e) return NULL;

	if (--(arr->length) < arr->capacity / 4 && _dynamic_arr_decrease_size(arr) != 0) return NULL;
		
	return removed_e;
}

void* dynamic_arr_remove_by_index(
	dynamic_arr_t* arr,
	size_t         index
) {
	if (index < 0 || index >= arr->length) return NULL;

	void* removed_e = arr->arr[index];
		
	for (size_t j = index; j < arr->length - 1; j++) {
		arr->arr[j] = arr->arr[j + 1];
	}

	if (--(arr->length) < arr->capacity / 4 && _dynamic_arr_decrease_size(arr) != 0) return NULL;
		
	return removed_e;
}

int _dynamic_arr_increase_size(dynamic_arr_t* arr) {
	arr->capacity *= 2;
	void** new = (void**)malloc(arr->e_size*arr->capacity);
	if (!new) return -1;
	
	for (size_t i = 0; i < arr->length; i++) {
		new[i] = arr->arr[i];
	}

	free(arr->arr);
	arr->arr = new;

	return 0;
}

int _dynamic_arr_decrease_size(dynamic_arr_t* arr) {
	arr->capacity /= 2;
	void** new = (void**)malloc(arr->e_size*arr->capacity);
	if (!new) return -1;
	
	for (size_t i = 0; i < arr->length; i++) {
		new[i] = arr->arr[i];
	}

	free(arr->arr);
	arr->arr = new;

	return 0;
}
