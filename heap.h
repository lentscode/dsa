#ifndef HEAP_C
#define HEAP_C

#include <stdlib.h>

void heapify(void* heap, size_t n, size_t i, size_t e_size, int (*cmp)(const void*, const void*));
void heap_build(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

#endif // HEAP_C
