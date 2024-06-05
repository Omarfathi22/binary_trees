#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree_level - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buffer: Buffer to store the tree representation
 *
 * Return: Length of printed tree after processing
 */
static int print_tree_level(const binary_tree_t *tree, int offset, int depth, char **buffer)
{
	char node_str[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);

	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(node_str, "(%03d)", tree->n);
	left = print_tree_level(tree->left, offset, depth + 1, buffer);
	right = print_tree_level(tree->right, offset + left + width, depth + 1, buffer);

	for (i = 0; i < width; i++)
		buffer[depth][offset + left + i] = node_str[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			buffer[depth - 1][offset + left + width / 2 + i] = '-';
		buffer[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			buffer[depth - 1][offset - width / 2 + i] = '-';
		buffer[depth - 1][offset + left + width / 2] = '.';
	}

	return (left + width + right);
}

/**
 * tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buffer;
	size_t height, i, j;

	if (!tree)
		return;

	height = tree_height(tree);
	buffer = malloc(sizeof(*buffer) * (height + 1));
	if (!buffer)
		return;

	for (i = 0; i < height + 1; i++)
	{
		buffer[i] = malloc(sizeof(**buffer) * 255);
		if (!buffer[i])
			return;
		memset(buffer[i], 32, 255);
	}

	print_tree_level(tree, 0, 0, buffer);

	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (buffer[i][j] != ' ')
				break;
			buffer[i][j] = '\0';
		}
		printf("%s\n", buffer[i]);
		free(buffer[i]);
	}
	free(buffer);
}
