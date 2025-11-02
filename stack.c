#include "stack.h"

stack_tt* stack_create(size_t e_size) {
	return dynamic_arr_create(e_size, 1);
}

int stack_push(stack_tt* stack, void* element) {
	return dynamic_arr_add(stack, element);
}

void* stack_pop(stack_tt* stack) {
	return dynamic_arr_remove_by_index(stack, stack->length - 1);
}

void stack_free(stack_tt* stack, void (*free_value)(void*)) {
	dynamic_arr_free(stack, free_value);
}
