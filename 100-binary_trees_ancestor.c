#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (node->parent == NULL);
}

/**
 * is_ancestor_path - Checks if a node is in the ancestor path of another node
 * @ancestor: Pointer to a potential ancestor node
 * @node: Pointer to the node whose ancestor path is checked
 * Return: 1 if ancestor is in the path, 0 otherwise
 */
int is_ancestor_path(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	while (node != NULL)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}
	return (0);
}

/**
 * binary_tree_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *current = first;

	if (first == NULL || second == NULL)
		return (NULL);

	if (binary_tree_is_root(first))
		return ((binary_tree_t *)first);
	if (binary_tree_is_root(second))
		return ((binary_tree_t *)second);

	while (current != NULL)
	{
		if (is_ancestor_path(current, second))
			return ((binary_tree_t *)current);
		current = current->parent;
	}

	return (NULL);
}
