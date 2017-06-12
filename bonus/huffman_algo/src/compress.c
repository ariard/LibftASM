#include "compress.h"

int	compress(char *original, char **compressed)
{
	float		tab_frequency[(int)SIZE + 1];
	char		*ptr;
	int		i;
	float		scale;
	t_huffnode	hufftree;
	t_list		*begin;
	
	(void)compressed;
	i = -1;
	while (++i < SIZE)
		tab_frequency[i] = 0.0;
	ptr = original;
	while (*ptr)
		tab_frequency[(int)*ptr++]++;

	i = -1;
	while (++i < SIZE)
	{
		scale = tab_frequency[i] / SIZE;
		if (scale > 1 || scale < 0)
			scale = 0;
		tab_frequency[i] = scale;
	}

	i = -1;
	while (tab_frequency[++i] == 0.0);
	begin = ft_lstnew(init_huffnode(i, tab_frequency[i]), sizeof(t_huffnode *));
	while (++i < SIZE)
		if (tab_frequency[i] > 0.0)
			ft_lst_sorted_insert(&begin, ft_lstnew(init_huffnode(i, tab_frequency[i]),
			sizeof(t_huffnode *)), &cmp_tree);
	read_prio_frequency(&begin);
	build_tree(tab_frequency, &hufftree);
	return (0);
}
