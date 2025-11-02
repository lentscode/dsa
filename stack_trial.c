#include <stdio.h>
#include "stack.h"
#include <assert.h>

int main(void) {
	stack_tt* stack = stack_create(sizeof(int));
	assert(stack);

	assert(stack_push(stack, (void*)37) == 0);
	assert(stack->length == 1);

	assert(stack_push(stack, (void*)42) == 0);
	assert(stack->length == 2);

	assert(stack_pop(stack) == (void*)42);
	assert(stack->length == 1);

	printf("[");
	for (size_t i = 0; i < stack->length; i++) {
		printf("%d", (int)stack->arr[i]);	
		if (i < stack->length - 1) printf(", ");
	}
	printf("]\n");

	return 0;
}
