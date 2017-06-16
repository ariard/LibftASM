#include "compress.h"

void		gen_lst_freq(t_list **begin, int tab_frequency[])
{
	int			i;
	t_huffnode	root;

	i = -1;
	while (++i < 256)
		if (tab_frequency[i] > 0)
		{
			init_huffnode(&root, i, tab_frequency[i]);
			if (!begin)
				*begin = ft_lstnew(&root, sizeof(t_huffnode));
			else
				ft_lst_sorted_insert(begin, ft_lstnew(&root,
					sizeof(t_huffnode)), &cmp_tree);
		}
}

int		compress(char *original, unsigned char **compressed)
{
	int			tab_frequency[(int)SIZE + 1];
	char			*ptr;
	int			i;
	int			max;
	int			scale;
	t_huffnode		*node;
	t_list			*begin;
	t_huffelem		table[256 + 1];

	begin = NULL;
	i = -1;
	while (++i < SIZE)
		tab_frequency[i] = 0;
	ptr = original;
	while (ptr && *ptr)
		tab_frequency[(int)*ptr++]++;
	i = -1;
	max = SIZE;	
	while (++i < SIZE)
		if (tab_frequency[i] > max)
			max = tab_frequency[i];
	i = -1;
	while (++i < SIZE)
	{
		scale = (int)(tab_frequency[i] / ((double)max / (double)max));
		if (scale == 0 && tab_frequency[i])
			tab_frequency[i] = 1;
		else
			tab_frequency[i] = scale;
	}
	gen_lst_freq(&begin, tab_frequency);
	read_prio_frequency(&begin);
	build_tree(&begin);
	node = begin->content;
	i = -1;
	while (++i < 256)
		table[i].code = 0;
	build_table(node, table, 0x0000, 0);
	return(do_compress(compressed, table, original, tab_frequency));
}
