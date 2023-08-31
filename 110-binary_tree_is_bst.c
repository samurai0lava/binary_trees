#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst_helper - Check if a binary tree is a (BST)
 * @tree: Pointer to the root of the binary tree
 * @lower_bound: The lower bound for node values in the subtree
 * @upper_bound: The upper bound for node values in the subtree
 *
 * @return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree,
		int lower_bound, int upper_bound)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= lower_bound || tree->n >= upper_bound)
		return (0);

	return (binary_tree_is_bst_helper(tree->left, lower_bound, tree->n) &&
			binary_tree_is_bst_helper(tree->right, tree->n,
				upper_bound));
}

/**
 * binary_tree_is_bst - Checks if binary tree is a valid (BST).
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (binary_tree_is_bst_helper(tree, INT_MIN, INT_MAX));
}
