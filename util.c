#include "util.h"
#include <string.h>

void swap(void* a, void* b, size_t elem_size) {
	void* tmp = (void*)malloc(elem_size);
	if (!tmp) return;

	memcpy(tmp, a, elem_size);
	memmove(a, b, elem_size);
	memcpy(b, tmp, elem_size);

	free(tmp);
}
