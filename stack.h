#ifndef STACK_H
#define STACK_H

#include "dynamic_arr.h"

typedef dynamic_arr_t stack_tt;

stack_tt* stack_create(size_t e_size);
int stack_push(stack_tt* stack, void* element);
void* stack_pop(stack_tt* stack);
void stack_free(stack_tt* stack, void (*free_value)(void*));

#endif // QUEUE_H
