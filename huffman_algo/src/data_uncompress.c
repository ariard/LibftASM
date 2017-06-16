#include "compress.h"

void		parse_freq(unsigned char *data, int tab_frequency[])
{
	int		i;

	i = -1;
	while (++i < SIZE)
		tab_frequency[i] = data[sizeof(int) + i];
}

void		parse_tree(t_huffnode *tree, unsigned char **uncompressed, unsigned char **data)
{
	if (tree)						
	{			
		if (tree->left && !bit_get((unsigned char *)*data, 0))
		{
			*data = *(data + 1);
			parse_tree(tree->left, uncompressed, data);
		}
		if (tree->right && bit_get((unsigned char *)*data, 0))
		{
			*data = *(data + 1);
			parse_tree(tree->right, uncompressed, data);
		}
		if (!tree->left && !tree->right)
			ft_strcat((char *)*uncompressed, (char *)&tree->sym);
	} 
}
