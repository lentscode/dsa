#include <time.h>
#include <string.h>
#include "heap.h"
#include "util.h"

void selection_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (!arr || !n || !cmp) return;

	for (size_t i = 0; i < n - 1; i++) {
		size_t smallest_index = i;

		for (size_t j = i + 1; j < n; j++) {
			if (cmp(arr + smallest_index * e_size, arr + j * e_size) > 0) continue;
			smallest_index = j;
		}

		swap(arr + i * e_size, arr + smallest_index * e_size, e_size);
	}
}

void insertion_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (!arr || !n || !cmp) return;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = i; j > 0; j--) {
			if (cmp(arr + (j - 1) * e_size, arr + j * e_size) > 0) break;

			swap(arr + (j - 1) * e_size, arr + j * e_size, e_size);
		}
	}
}

void bubble_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	 if (!arr || !n || !cmp) return;

	for (size_t i = 0; i < n - 1; i++) {
		size_t switched = 0;
		for (size_t j = 0; j < n - 1; j++) {
			if (cmp(arr + (j + 1) * e_size, arr + j * e_size) < 0) continue;

			switched = 1;

			swap(arr + (j + 1) * e_size, arr + j * e_size, e_size);
		}

		if (!switched) return;
	}
}

void heap_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (!arr || !n || !cmp) return;

	void* heap = malloc(n*e_size);
	memcpy(heap, arr, n * e_size);

	heap_build(heap, n, e_size, cmp);

	for (size_t i = 0; i < n; i++) {
		memcpy(arr + (n - 1 - i) * e_size, heap, e_size);

		memcpy(heap, heap + (n - 1 - i) * e_size, e_size);
		heapify(heap, n - 1 - i, 0, e_size, cmp);
	}
}

void _merge(void* src, size_t start, size_t middle, size_t end, void* dest, size_t e_size, int (*cmp)(const void*, const void*)) {
	size_t i = start;
	size_t j = middle;

	for (size_t k = start; k < end; k++) {
		if (i < middle && (j >= end || cmp(src + i * e_size, src + j * e_size) >= 0)) {
			memcpy(dest + k * e_size, src + i * e_size, e_size);
			// dest[k] = src[i];
			i++;
		} else {
			memcpy(dest + k * e_size, src + j * e_size, e_size);
			/* dest[k] = src[j]; */
			j++;
		}
	}
}

void _merge_sort(void* src, size_t start, size_t end, void* dest, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (end - start <= 1) return;
	
	size_t middle = (start + end) / 2;
	_merge_sort(dest, start, middle, src, e_size, cmp);
	_merge_sort(dest, middle, end, src, e_size, cmp);

	_merge(src, start, middle, end, dest, e_size, cmp);
}

void merge_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (!arr || !n || !cmp) return;

	void* copy = malloc(n*e_size);
	/* int copy[n]; */
	/* for (int i = 0; i < n; i++) { */
	/* 	copy[i] = arr[i]; */
	/* } */
	memcpy(copy, arr, n * e_size);

	_merge_sort(copy, 0, n, arr, e_size, cmp);
}

int _partition(void* arr, int low, int high, size_t e_size, int (*cmp)(const void*, const void*)) {
	int pivot_index = rand() % (high - low + 1) + low;
	swap(arr + pivot_index * e_size, arr + low * e_size, e_size);

	int i = low - 1;
	int j = high + 1;

	while (1) {
		do i++; while (cmp(arr + i * e_size, arr + low * e_size) > 0);
		do j--; while (cmp(arr + j * e_size, arr + low * e_size) < 0);

		if (i >= j) return j;

		swap(arr + i * e_size, arr + j * e_size, e_size);
	}
}

void _quick_sort(void* arr, int low, int high, size_t e_size, int (*cmp)(const void*, const void*)) {
	if (low >= high) return;

	int pivot = _partition(arr, low, high, e_size, cmp);
	_quick_sort(arr, low, pivot, e_size, cmp);
	_quick_sort(arr, pivot + 1, high, e_size, cmp);
}

void quick_sort(void* arr, size_t n, size_t e_size, int (*cmp)(const void*, const void*)) {
	_quick_sort(arr, 0, n - 1, e_size, cmp);
}

