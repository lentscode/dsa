#include "tree.h"

#include "queue.h"
#include <stdio.h>

node_t* tree_create(size_t e_size, void* value) {
	node_t* root = (node_t*)malloc(sizeof(node_t));
	if (!root) return NULL;

	root->e_size  = e_size;
	root->value   = value;
	root->child   = NULL;
	root->sibling = NULL;

	return root;
}

node_t* node_add_child(node_t* node, void* value) {
	node_t* new = tree_create(node->e_size, value);
	if (!new) return NULL;

	if (!node->child) {
		node->child = new;
		return new;
	}
	
	node_t* child = node->child;
	while (child->sibling) {
		child = child->sibling;
	}

	child->sibling = new;
	return new;
}

node_t* tree_find(node_t* root, void* value) {
	queue_t* queue = queue_create(sizeof(node_t));
	if (!queue) return NULL;

	node_t* result = NULL;

	queue_enqueue(queue, root);
	while (queue->length > 0) {
		node_t* node = queue_dequeue(queue);
		if (!node) {
			queue_free(queue, NULL);
			return NULL;
		}

		if (node->value == value) {
			result = node;
			break;
		}

		node_t* child = node->child;
		while (child && queue_enqueue(queue, child) == 0) {
			child = child->sibling;
		}
	}

	queue_free(queue, NULL);
	return result;
}

void tree_free(node_t* root, void (*free_value)(void*)) {
	if (root == NULL) return;

	tree_free(root->child, free_value);
	tree_free(root->sibling, free_value);

	if (free_value && root->value) free_value(root->value);

	free(root);
}
