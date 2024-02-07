#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree by post-order traversal
 * @tree: Pointer to root node of tree to traverse
 * @func: Function which performs an action on each node
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
