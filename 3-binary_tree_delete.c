#include "binary_trees.h"

void binary_tree_delete_helper(binary_tree_t *subtree);

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to root node of tree to delete
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete_helper(tree);
		free(tree);
	}
}

/**
 * binary_tree_delete_helper - Deletes a subtree of a binary tree
 * @subtree: Pointer to subtree to be deleted
 * Return: Nothing
 */
void binary_tree_delete_helper(binary_tree_t *subtree)
{
	if (subtree->left)
	{
		binary_tree_delete_helper(subtree->left);
		free(subtree->left);
	}
	if (subtree->right)
	{
		binary_tree_delete_helper(subtree->right);
		free(subtree->right);
	}
}
