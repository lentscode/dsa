#ifndef QUEUE_H
#define QUEUE_H

#include "dynamic_arr.h"

typedef dynamic_arr_t queue_t;

queue_t* queue_create(size_t e_size);
int queue_enqueue(queue_t* queue, void* element);
void* queue_dequeue(queue_t* queue);
void queue_free(queue_t* queue, void (*free_value)(void*));

#endif // QUEUE_H
