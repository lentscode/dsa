#include "list.h"
#include <string.h>

list_node_t* list_create(void* value, size_t e_size) {
	list_node_t* start = (list_node_t*)malloc(sizeof(list_node_t));
	if (!start) return NULL;

	start->e_size = e_size;
	start->next   = NULL;
	start->value  = malloc(e_size);
	if (!start->value) {
		free(start);
		return NULL;
	}

	memcpy(start->value, value, e_size);
	return start;
}

int list_add_node(list_node_t* start, void* value) {
	if (!start) return 1;

	list_node_t* current = start;
	while (current->next) {
		current = current->next;
	}

	current->next = list_create(value, start->e_size);
	if (!current->next) return 1;

	return 0;
}

int list_remove_node(list_node_t* start, void* value, int (*cmp)(const void*, const void*)) {
	if (!start || !cmp) return 1;

	list_node_t* current = start;
	while (current->next && cmp(current->next->value, value) != 0) {
		current = current->next;
	}

	if (!current->next) return 1;

	list_node_t* replacement = current->next->next;
	free(current->next);

	if (replacement) current->next = replacement;
	else             current->next = NULL;

	return 0;
}

int list_get_length(list_node_t* start) {
	if (!start) return 1;

	int size = 0;
	list_node_t* current = start;
	while (current) {
		size++;
		current = current->next;
	}

	return size;
}

list_node_t* list_get_nth_node(list_node_t* start, size_t n) {
	if (!start) return NULL;

	list_node_t* current = start;
	size_t i = 0;
	while (current && i < n) {
		current = current->next;
		i++;
	}

	return current;
}

list_node_t* list_get_by_value(list_node_t* start, void* value, int (*cmp)(const void*, const void*)) {
	if (!start || !cmp) return NULL;

	list_node_t* current = start;
	while (current && cmp(current->value, value) != 0) {
		current = current->next;
	}

	return current;
}

void list_free(list_node_t* start, void (*free_value)(void*)) {
	if (!start) return;

	list_node_t* current = start;
	while (current) {
		list_node_t* to_free = current;
		current = current->next;

		if (free_value) free_value(to_free->value);
		free(to_free);
	}
}
