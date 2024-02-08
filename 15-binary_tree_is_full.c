#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to root node of tree to check
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_is_full = 0, right_is_full = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (1);

	left_is_full = binary_tree_is_full(tree->left);
	right_is_full = binary_tree_is_full(tree->right);

	if (left_is_full == 1 && right_is_full == 1)
		return (1);
	else
		return (0);
}
