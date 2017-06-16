#include "compress.h"

int	hufftree_level_count(t_huffnode *root)
{
	return (root
		? 1 + FT_MAX(hufftree_level_count(root->left),
			hufftree_level_count(root->right))
		: 0);
}

void	print_node(t_huffnode *node, int ref, int col, int nbr)
{
	int marge_in;
	int marge_out;

	(void)ref;
	marge_in = (col/nbr)/2;
	if (ref == 4)
		marge_in = 4;
	marge_out = marge_in - 1;
	while (marge_in--)
		write(1, " ", 1);
	if (node->sym == 32)
		write(1, "sp", 2);
	else
		write(1, &node->sym, 1);
	while (marge_out--)
		write(1, " ", 1);

}

void	breath_first(t_huffnode *root, int depth, int ref, int col, int nbr, void (*print)(t_huffnode *, int, int, int))
{
	if (depth < ref && root->left)
		breath_first(root->left, depth + 1, ref, col, nbr, print_node);
	if (depth < ref && root->left)
		breath_first(root->right, depth + 1, ref, col, nbr, print_node);
	if (depth == ref)
		(*print)(root, ref, col, nbr);
}
	
void	hufftree_print(t_huffnode *root)
{
	int		width;
	int		i;
	int		j;
	int		column;
	struct winsize	ws;

	width = hufftree_level_count(root);
	width = 5;
	ioctl(0, TIOCGWINSZ, &ws);
	column = ws.ws_col;
	printf("row %d, column %d, width %d\n", ws.ws_row,  ws.ws_col, width);

	i = -1;
	j = 1;
	while (++i < width)
	{
		if (i == 4)
			write(1, "               ", 12);
		breath_first(root, 0, i, column, j, print_node);	
		printf("\n");
		j *= 2;
	}
}
