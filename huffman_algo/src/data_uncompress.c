#include "compress.h"

void		parse_freq(unsigned char *data, int tab_frequency[])
{
	int		i;

	i = -1;
	while (++i < SIZE)
		tab_frequency[i] = data[sizeof(int) + i];
}

void		parse_tree(t_huffnode *tree, unsigned char *uncompressed, unsigned char *data, int size)
{
	int		i;
	int		j;
	t_huffnode	*node;
	int		state;

	i = 0;
	j = 0;
	while (i <= size)
	{
		node = tree;
		while (node->right && node->left)
		{	
			state = bit_get(data, j);
			if (!state && node->left)
				node = node->left;
			if (state && node->right)
				node = node->right;
			j++;
		}
		ft_memcpy(&uncompressed[i], &node->sym, sizeof(char));
		i++;
	}
}
