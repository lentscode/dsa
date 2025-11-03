#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>

void selection_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

void insertion_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

void bubble_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

void heap_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

void merge_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

void quick_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*));

#endif // SORTING_H
