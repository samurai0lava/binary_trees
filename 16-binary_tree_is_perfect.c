#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);

	l = tree->left;
	r = tree->right;
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		return (binary_tree_is_perfect(l)
				&& binary_tree_is_perfect(r));
	}

	return (0);
}
