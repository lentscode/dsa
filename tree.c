#include "tree.h"

#include <string.h>
#include "queue.h"
#include "stack.h"

node_t* tree_create(size_t e_size, void* value) {
	node_t* root = (node_t*)malloc(sizeof(node_t));
	if (!root) return NULL;

	root->e_size  = e_size;
	root->value   = value;
	root->child   = NULL;
	root->sibling = NULL;

	root->value = malloc(e_size);
	if (!root->value) {
		free(root);
		return NULL;
	}
	memcpy(root->value, value, e_size);

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

node_t* tree_find(node_t* root, void* value, int (*cmp)(const void*, const void*)) {
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

		if (cmp(node->value, value) == 0) {
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

void tree_bfs(node_t* root, void (*operate)(const void*)) {
	if (!operate) return;
	queue_t* queue = queue_create(sizeof(node_t));
	if (!queue) return;

	queue_enqueue(queue, root);
	while (queue->length > 0) {
		node_t* node = queue_dequeue(queue);
		if (!node) {
			queue_free(queue, NULL);
			return;
		}

		operate(node->value);

		node_t* child = node->child;
		while (child && queue_enqueue(queue, child) == 0) {
			child = child->sibling;
		}
	}

	queue_free(queue, NULL);
}

void tree_dfs(node_t* root, void (*operate)(const void*)) {
	if (!operate) return;
	stack_tt* stack = stack_create(sizeof(node_t));
	if (!stack) return;

	stack_push(stack, root);
	while (stack->length > 0) {
		node_t* node = stack_pop(stack);
		if (!node) {
			stack_free(stack, NULL);
			return;
		}

		operate(node->value);

		node_t* child = node->child;
		while (child && stack_push(stack, child) == 0) {
			child = child->sibling;
		}
	}

	stack_free(stack, NULL);
}

void tree_recursive(node_t* root, void (*operate)(const void*)) {
	if (!root || !operate) return;

	node_t* child = root->child;
	while (child) {
		tree_recursive(child, operate);
		child = child->sibling;
	}

	operate(root->value);
}

void tree_free(node_t* root, void (*free_value)(void*)) {
	if (root == NULL) return;

	tree_free(root->child, free_value);
	tree_free(root->sibling, free_value);

	if (free_value && root->value) free_value(root->value);

	free(root);
}
