#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the tree, or -1 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);


	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ?
			left_height + 1 : right_height + 1);
}

/**
 * binary_tree_level_traversal -
 * Recursively traverses a binary tree level by level
 * @tree: Pointer to the root node of the tree
 * @level: Current level being traversed
 * @func: Pointer to a function to call for each node
 */
void binary_tree_level_traversal(const binary_tree_t *tree,
		size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		binary_tree_level_traversal(tree->left, level - 1, func);
		binary_tree_level_traversal(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0;
	size_t level = 0;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 1; level <= height + 1; level++)
	{
		binary_tree_level_traversal(tree, level, func);
	}
}
