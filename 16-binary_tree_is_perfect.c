#include "binary_trees.h"

int bt_is_perfect_helper(const binary_tree_t *tree, size_t tree_height);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node of binary tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height = binary_tree_height(tree);

	if (tree == NULL)
		return (0);

	return (bt_is_perfect_helper(tree, tree_height));
}

/**
 * bt_is_perfect_helper - Helper function to check if binary tree is perfect
 *
 * This function checks that:
 * (i) all leaves of the tree are on the same level
 * (ii) all subtrees have either 0 or 2 children.
 *
 * @tree: Pointer to root node of tree to check
 * @tree_height: Height of tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int bt_is_perfect_helper(const binary_tree_t *tree, size_t tree_height)
{
	int left_is_perfect, right_is_perfect;
	size_t node_level;

	/* Check that all leaves are on the same level */
	if (tree->left == NULL && tree->right == NULL)
	{
		node_level = binary_tree_depth(tree);
		if (node_level == tree_height)
			return (1);
	}

	/* Check that subtrees with 2 children have both children perfect */
	if (tree->left && tree->right)
	{
		left_is_perfect = bt_is_perfect_helper(tree->left, tree_height);
		right_is_perfect = bt_is_perfect_helper(tree->right, tree_height);
		return (left_is_perfect && right_is_perfect);
	}

	/* Return 0 if none of the above conditions are true */
	return (0);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to node to measure depth
 * Return: Depth of the node or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);

	depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
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
