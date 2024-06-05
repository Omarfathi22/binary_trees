#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    if (tree == NULL)
        return (NULL);

    new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }
    current = *tree;
    while (current != NULL)
    {
        parent = current;
        if (value == current->n)
        {
            free(new_node);
            return (NULL);
        }
        else if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}
