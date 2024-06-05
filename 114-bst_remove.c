#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_min_value_node - Finds the node with the smallest value greater than
 * the given node.
 * @node: The node to find the minimum value node for.
 *
 * Return: The node with the smallest value.
 */
bst_t *bst_min_value_node(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            if (root->parent)
            {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
            }
            if (temp)
                temp->parent = root->parent;
            free(root);
            return (temp);
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            if (root->parent)
            {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
            }
            if (temp)
                temp->parent = root->parent;
            free(root);
            return (temp);
        }

        temp = bst_min_value_node(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return (root);
}
