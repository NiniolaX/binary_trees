#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to node to insert left-child into
 * @value: Value to store in left node
 * Return: Pointer to created node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);

	/* Create left-child node and store value in it */
	left_node = binary_tree_node(parent, value);

	/* Insert new node as left-child of parent */
	if (parent->left == NULL)
		parent->left = left_node;
	else
	{
		temp = parent->left;
		parent->left = left_node;
		left_node->left = temp;
		temp->parent = left_node;
	}

	return (left_node);
}
