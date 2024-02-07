#include "binary_trees.h"

void bt_inorder_helper(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of tree to traverse
 * @func: Pointer to a function to perform a certain action on each node
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	bt_inorder_helper(tree, func);
}

/**
 * bt_inorder_helper - Goes through a binary tree recursively in preorder
 * @tree: Pointer to tree to traverse
 * @func: Pointer to function which performs an action on each node
 * Return: Nothing
 */
void bt_inorder_helper(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left)
		bt_inorder_helper(tree->left, func);
	if (tree)
		func(tree->n);
	if (tree->right)
		bt_inorder_helper(tree->right, func);
}
