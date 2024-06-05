#include "binary_trees.h"

/* Function prototypes */
int is_complete(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size;

    if (tree == NULL)
        return (0);

    size = binary_tree_size(tree);

    return (is_complete(tree, 0, size));
}

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @size: The number of nodes in the binary tree.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, size) &&
            is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
