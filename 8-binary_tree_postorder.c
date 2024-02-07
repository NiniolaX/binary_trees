#include "binary_trees.h"

void bt_postorder_helper(const binary_tree_t *tree, void (*func)(int));

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
	bt_postorder_helper(tree, func);
}

/**
 * bt_postorder_helper - Traverses a binary tree recursively using postorder
 * @subtree: Pointer to tree to traverse
 * @func: Function which performs an action on each node
 * Return: Nothing
 */
void bt_postorder_helper(const binary_tree_t *subtree, void (*func)(int))
{
	if (subtree->left)
		bt_postorder_helper(subtree->left, func);
	if (subtree->right)
		bt_postorder_helper(subtree->right, func);
	if (subtree)
		func(subtree->n);
}
