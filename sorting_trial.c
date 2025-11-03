#include <stdio.h>
#include <time.h>
#include "sorting.h"

#define LENGTH 13

int compare_int(const void* a, const void* b) {
	int* a_int = (int*)a;
	int* b_int = (int*)b;

	return *b_int - *a_int;
}

int main(void) {
	srand(time(NULL));
	int arr[LENGTH] = {5, 2, 7, 1, 8, 24, 3, -2, 4, 22, 12, 9, -5}; 
	printf("[");
	for (int i = 0; i < LENGTH; i++) {
		printf("%d", arr[i]);
		if (i < LENGTH - 1) printf(", ");
	}
	printf("]\n");

	quick_sort(arr, LENGTH, sizeof(int), compare_int);

	printf("[");
	for (int i = 0; i < LENGTH; i++) {
		printf("%d", arr[i]);
		if (i < LENGTH - 1) printf(", ");
	}
	printf("]\n");
	return 0;
}
