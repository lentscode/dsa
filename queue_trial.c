#include <stdio.h>
#include "queue.h"
#include <assert.h>

int main(void) {
	queue_t* queue = queue_create(sizeof(int));
	assert(queue);

	assert(queue_enqueue(queue, (void*)37) == 0);
	assert(queue->length == 1);

	assert(queue_enqueue(queue, (void*)42) == 0);
	assert(queue->length == 2);

	assert(queue_dequeue(queue) == (void*)37);
	assert(queue->length == 1);

	printf("[");
	for (size_t i = 0; i < queue->length; i++) {
		printf("%d", (int)queue->arr[i]);	
		if (i < queue->length - 1) printf(", ");
	}
	printf("]\n");

	return 0;
}
