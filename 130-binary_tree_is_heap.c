#include "binary_trees.h"

/* Forward declarations */
int is_complete_util(const binary_tree_t *tree, int index, int number_nodes);
int is_heap_util(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    int index = 0;
    int nodes = binary_tree_size(tree);

    return (is_complete_util(tree, index, nodes));
}

/**
 * is_complete_util - Helper function to check completeness
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index in the complete tree
 * @number_nodes: Number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_util(const binary_tree_t *tree, int index, int number_nodes)
{
    if (!tree)
        return (1);

    if (index >= number_nodes)
        return (0);

    return (is_complete_util(tree->left, 2 * index + 1, number_nodes) &&
            is_complete_util(tree->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!binary_tree_is_complete(tree))
        return (0);

    return (is_heap_util(tree));
}

/**
 * is_heap_util - Helper function to check heap property
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree maintains the heap property, 0 otherwise
 */
int is_heap_util(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    if (tree->left && tree->n < tree->left->n)
        return (0);

    if (tree->right && tree->n < tree->right->n)
        return (0);

    return (is_heap_util(tree->left) && is_heap_util(tree->right));
}
