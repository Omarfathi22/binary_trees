#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * 
 * Return: The maximum value
 */
int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * 
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + max(binary_tree_height(tree->left), binary_tree_height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for the current node
 * @max: Maximum value for the current node
 * 
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);
    if (tree->n <= min || tree->n >= max)
        return (0);
    return (is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Helper function to check if a tree is AVL
 * @tree: Pointer to the root node of the tree to check
 * 
 * Return: 1 if the tree is AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
    int lh, rh;

    if (tree == NULL)
        return (1);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    lh = binary_tree_height(tree->left);
    rh = binary_tree_height(tree->right);

    if (abs(lh - rh) > 1)
        return (0);

    return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * 
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (is_avl(tree));
}
