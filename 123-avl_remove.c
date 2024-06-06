#include "binary_trees.h"
#include <stdlib.h>

/**
 * min_value_node - Finds the node with the smallest value greater than a given node
 * @node: The node to start from
 * 
 * Return: Pointer to the node with the smallest value
 */
avl_t *min_value_node(avl_t *node)
{
    avl_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 *
 * Return: Pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return (NULL);

    if (value < root->n)
    {
        root->left = avl_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = avl_remove(root->right, value);
    }
    else
    {
        if (!root->left)
        {
            avl_t *temp = root->right;
            free(root);
            return (temp);
        }
        else if (!root->right)
        {
            avl_t *temp = root->left;
            free(root);
            return (temp);
        }

        avl_t *temp = min_value_node(root->right);
        root->n = temp->n;
        root->right = avl_remove(root->right, temp->n);
    }

    if (!root)
        return (NULL);

    int balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return (binary_tree_rotate_right(root));

    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }

    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return (binary_tree_rotate_left(root));

    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
    }

    return (root);
}
