#include "bst.h"

#include <string.h>

bst_node_t* bst_create(void* value, size_t e_size) {
	if (!value || !e_size) return NULL;

	bst_node_t* root = (bst_node_t*)malloc(sizeof(bst_node_t));
	if (!root) return NULL;

	root->value = malloc(e_size);
	if (!root->value) {
		free(root);
		return NULL;
	}
	memcpy(root->value, value, e_size);
	root->e_size = e_size;
	root->father = NULL;
	root->left   = NULL;
	root->right  = NULL;

	return root;
}

bst_node_t* bst_add(bst_node_t* tree, void* value, int (*cmp)(const void*, const void*)) {
	if (!tree || !value) return NULL;

	bst_node_t* new = bst_create(value, tree->e_size);
	if (!new) return NULL;

	bst_node_t* current = tree;

	while (current) {
		if (cmp(current->value, value) > 0) {
			if (!current->right) {
				current->right = new;
				new->father = current;
				break;
			} else {
				current = current->right;
			}
		} else {
			if (!current->left) {
				current->left = new;
				new->father = current;
				break;
			} else {
				current = current->left;
			}
		}
	}

	return new;
}

/* bst_node_t* bst_remove(bst_node_t* root, void* value, int (*cmp)(const void*, const void*)) { */
/* 	bst_node_t* node = bst_search(root, value, cmp); */
/* 	if (!node) return NULL; */

/* 	if (!node->right && !node->left) { */
/* 		bst_node_t* father = node->father; */
/* 		if (father->left == node) father->left = NULL; */
/* 		else if (father->right == node) father->right = NULL; */

/* 		return node; */
/* 	} */

/* 	if (node->right && !node->left) { */
/* 		bst_node_t* father = node->father; */
/* 		if (father->left == node) father->left = node->right; */
/* 		else if (father->right == node) father->right = node->right; */

/* 		return node; */
/* 	} */

/* 	if (!node->right && node->left) { */
/* 		bst_node_t* father = node->father; */
/* 		if (father->left == node) father->left = node->left; */
/* 		else if (father->right == node) father->right = node->left; */

/* 		return node; */
/* 	} */

/* 	bst_node_t* pred = bst_pred(node); */
/* 	if (!pred) return NULL; */

/* 	bst_node_t* father = node->father; */
/* 	if (father->left == node) father->left = node->left; */
/* 	else if (father->right == node) father->right = node->left; */
/* } */

bst_node_t* bst_search(bst_node_t* root, void* value, int (*cmp)(const void*, const void*)) {
	while (root) {
		if (cmp(root->value, value) == 0) return root;

		if (cmp(root->value, value) > 0)
			root = root->right;

		if (cmp(root->value, value) < 0)
			root = root->left;
	}

	return NULL;
}

bst_node_t* bst_max(bst_node_t* root) {
	if (!root) return NULL;
	while (root->right) {
		root = root->right;
	}

	return root;
}

bst_node_t* bst_pred(bst_node_t* node) {
	if (!node) return NULL;

	if (node->left) return bst_max(node);

	bst_node_t* current = node;
	while (current->father && current->father->left == current)
		current = current->father;

	return current->father;
}

