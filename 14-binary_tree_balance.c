#include "binary_trees.h"
#include <stdio.h>

size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to root node of the tree to measure
 * Return: Balance factor of tree or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_subtree_height = 0, right_subtree_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_subtree_height = 1 + (int)binary_tree_height(tree->left);
	if (tree->right)
		right_subtree_height = 1 + (int)binary_tree_height(tree->right);

	return (left_subtree_height - right_subtree_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to root node of tree
 * Return: Height of tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (0);

	left_height = 1 + binary_tree_height(tree->left);
	right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
