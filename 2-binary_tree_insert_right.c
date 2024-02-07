#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to node to insert right-child into
 * @value: Value to be stored in new node
 * Return: Pointer to created node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);

	/* Create right-child node */
	right_child = binary_tree_node(parent, value);

	/* Insert created node as right-child of parent */
	if (parent->left == NULL)
		parent->right = right_child;
	else
	{
		temp = parent->right;
		parent->right = right_child;
		right_child->right = temp;
		temp->parent = right_child;
	}

	return (right_child);
}
