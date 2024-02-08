#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary_tree
 * @tree: Pointer to root node of binary tree
 * Return: Size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lt_size, rt_size;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lt_size = binary_tree_size(tree->left);
	rt_size = binary_tree_size(tree->right);

	/* tree size = left subree size + right subtree size + root */
	return (lt_size + rt_size + 1);
}
