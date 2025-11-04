#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node {
	size_t       e_size;
	void*        value;
	struct node* next;
} list_node_t;

list_node_t* list_create(void* value, size_t e_size);
int list_add_node(list_node_t* start, void* value);
int list_remove_node(list_node_t* start, void* value, int (*cmp)(const void*, const void*));
int list_get_length(list_node_t* start);
list_node_t* list_get_nth_node(list_node_t* start, size_t n);
list_node_t* list_get_by_value(list_node_t* start, void* value, int (*cmp)(const void*, const void*));
void list_free(list_node_t* start, void (*free_value)(void*));

#endif // LIST_H
