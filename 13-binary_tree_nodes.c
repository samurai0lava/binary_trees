#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The number of nodes with at least 1 child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
