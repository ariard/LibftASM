#include "compress.h"

void		read_tab_frequency(float tab_frequency[])
{
	int	i;

	i = -1;
	
	while (++i < 257)
		printf("sym %c req %f\n", i, tab_frequency[i]);
}

void		read_prio_frequency(t_list **begin)
{
	t_list		*tmp;
	t_huffnode	*huff;

	tmp = *begin;
	while (tmp)
	{
		huff = tmp->content;
		printf("sym %c, freq %f\n", huff->sym, huff->frequency);
		tmp = tmp->next;
	}
}
