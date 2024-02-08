#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to root node of tree to check
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_is_full, right_is_full;

	if (tree == NULL)
		return (0);

	/* Trees with 0 children (i.e. leaves) are full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* Check if both left and right subtrees are full */
	left_is_full = binary_tree_is_full(tree->left);
	right_is_full = binary_tree_is_full(tree->right);

	/* Bool: If expr is true, 1 is returned, if false, 0 is returned */
	return (left_is_full && right_is_full);
}
