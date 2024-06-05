#include "binary_trees.h"

/**
 * avl_rebalance - Rebalances an AVL tree
 * @tree: Pointer to the root node of the tree to rebalance
 *
 * Return: Pointer to the new root node of the tree once rebalanced
 */
avl_t *avl_rebalance(avl_t *tree)
{
    int balance;

    balance = binary_tree_balance(tree);
    if (balance > 1)
    {
        if (binary_tree_balance(tree->left) < 0)
            tree->left = binary_tree_rotate_left(tree->left);
        return (binary_tree_rotate_right(tree));
    }
    if (balance < -1)
    {
        if (binary_tree_balance(tree->right) > 0)
            tree->right = binary_tree_rotate_right(tree->right);
        return (binary_tree_rotate_left(tree));
    }
    return (tree);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node, *parent, *new_node;

    if (!tree)
        return (NULL);
    parent = NULL;
    node = *tree;
    while (node)
    {
        parent = node;
        if (value < node->n)
            node = node->left;
        else if (value > node->n)
            node = node->right;
        else
            return (NULL);
    }
    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);
    if (!parent)
        *tree = new_node;
    else if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;
    return (new_node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree to insert the value
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node, *root;

    if (!tree)
        return (NULL);
    node = bst_insert(tree, value);
    root = node;
    while (root->parent)
        root = root->parent;
    while (root)
    {
        root = avl_rebalance(root);
        root = root->parent;
    }
    while (node && node->parent)
        node = node->parent;
    return (node);
}
