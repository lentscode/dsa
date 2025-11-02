#include "queue.h"

queue_t* queue_create(size_t e_size) {
	return dynamic_arr_create(e_size, 1);
}

int queue_enqueue(queue_t* queue, void* element) {
	return dynamic_arr_add(queue, element);
}

void* queue_dequeue(queue_t* queue) {
	return dynamic_arr_remove_by_index(queue, 0);
}

void queue_free(queue_t* queue, void (*free_value)(void*)) {
	dynamic_arr_free(queue, free_value);
}
