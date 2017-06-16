#include "compress.h"

void		read_tab_frequency(float tab_frequency[])
{
	int	i;

	i = -1;
	
	while (++i < 257)
		if (tab_frequency[i])
			printf("sym %c req %f\n", i, tab_frequency[i]);
}

void		read_prio_frequency(t_list **begin)
{
	t_list		*tmp;
	t_huffnode	*huff;

	tmp = *begin;
	printf("FREQUENCY\n");
	while (tmp)
	{
		huff = tmp->content; 
		printf("sym %c, freq %d\n", huff->sym, huff->frequency);
		tmp = tmp->next;
	}
	printf("\n");
}

void		read_tab_code(t_huffelem table[], int tab_frequency[])
{
	int	i;

	i = -1;
	printf("CODE\n");
	(void)tab_frequency;
	while (++i < 256)
		if (tab_frequency[i])
			ft_printf("sym %c size %hd code %016b\n", i,  table[i].size, table[i].code);
	printf("\n");
}
