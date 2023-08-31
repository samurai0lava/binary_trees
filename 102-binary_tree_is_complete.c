#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_complete_recursive - Helper function for recursive traversal
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @num_nodes: Total number of nodes in the tree
 * @is_complete: Pointer to a flag indicating if the tree is complete
 * Return: void
 */
void binary_tree_is_complete_recursive(const binary_tree_t *tree,
		int index, int num_nodes, int *is_complete)
{

	if (*is_complete == 0 || tree == NULL)
		return;

	if (index >= num_nodes)
	{
		*is_complete = 0;
		return;
	}

	if (tree->left)
		binary_tree_is_complete_recursive(tree->left,
				2 * index + 1, num_nodes, is_complete);

	if (tree->right)
		binary_tree_is_complete_recursive(tree->right,
				2 * index + 2, num_nodes, is_complete);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int num_nodes = binary_tree_size(tree);
	int is_complete = 1;

	binary_tree_is_complete_recursive(tree, 0, num_nodes, &is_complete);

	return (is_complete);
}
