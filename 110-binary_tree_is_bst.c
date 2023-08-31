#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst_helper - checks if binary tree is a valid (BST).
 * @tree: A pointer to the root node of the tree to check.
 * @prev_value: A pointer to int variable that keeps track of previous value.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree, int *prev_value)
{
	if (tree == NULL)
		return (1);

	if (!binary_tree_is_bst_helper(tree->left, prev_value))
		return (0);

	if (tree->n <= *prev_value)
		return (0);

	*prev_value = tree->n;

	if (!binary_tree_is_bst_helper(tree->right, prev_value))
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - Checks if binary tree is a valid (BST).
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value = INT_MIN;

	return (binary_tree_is_bst_helper(tree, &prev_value));
}
