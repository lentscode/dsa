#include <stdlib.h>
#include <string.h>
#include "util.h"
#include <stdio.h>

void heapify(void* heap, size_t n, size_t i, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (!cmp) return;

	size_t largest = i;
	size_t left_child_index = 2 * i + 1;
	size_t right_child_index = 2 * i + 2;

	if (left_child_index < n && cmp(heap + largest * e_size, heap + left_child_index * e_size) > 0)
		largest = left_child_index;

	if (right_child_index < n && cmp(heap + largest * e_size, heap + right_child_index * e_size) > 0)
		largest = right_child_index;

	if (largest == i) return;

	swap(heap + largest * e_size, heap + i * e_size, e_size);
	heapify(heap, n, largest, e_size, cmp);
}

void heap_build(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, e_size, cmp);
	}
}
