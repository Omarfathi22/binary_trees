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

    /* Allocate memory for new node */
    new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize new node */
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    /* If tree is empty, make new node the root */
    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }

    /* Traverse the tree to find the appropriate position to insert */
    current = *tree;
    while (current != NULL)
    {
        parent = current;
        if (value == current->n)
        {
            free(new_node);
            return (NULL); /* Value already exists, ignore and return NULL */
        }
        else if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    /* Insert new node according to BST property */
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}
