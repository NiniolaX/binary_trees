#include "binary_trees.h"

binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to node whose uncle is to be found
 * Return: Pointer to uncle of ndoe
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Return sibling of parent */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to node whose sibling is to be found
 * Return: Pointer to sibling of node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Move to parent and examine left and right children of parent */
	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}
