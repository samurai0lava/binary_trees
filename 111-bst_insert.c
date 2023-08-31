#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to be inserted into the BST
 *
 * Return: A pointer to the newly created node, or NULL on failure
 * or if value already exists.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL;
	bst_t *parent = NULL;
	bst_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}
	current = *tree;
	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else if (value == current->n)
			return (NULL);
	}
	new_node = binary_tree_node(NULL, value);
	if (parent == NULL)
		return (*tree = new_node);
	else if (value < parent->n)
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->right = new_node;
		new_node->parent = parent;
	}
	return (new_node);
}
