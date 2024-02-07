#include "binary_trees.h"

void bt_preorder_helper(const binary_tree_t *subtree, void (*func)(int));

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to root node of tree to traverse
 * @func: Pointer to a function to perform a certain action on each node
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	bt_preorder_helper(tree, func);
}

/**
 * bt_preorder_helper - Goes through a binary tree recursively in preorder
 * @subtree: Pointer to subtree to traverse
 * @func: Pointer to a function to perform a certain action on each node
 * Return: Nothing
 */
void bt_preorder_helper(const binary_tree_t *subtree, void (*func)(int))
{
	if (subtree)
		func(subtree->n);
	if (subtree->left)
		bt_preorder_helper(subtree->left, func);
	if (subtree->right)
		bt_preorder_helper(subtree->right, func);
}
