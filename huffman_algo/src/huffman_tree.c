#include "compress.h"

void	pop_elem(t_list **begin)
{
	t_list *top;
	
	top = *begin;
	*begin = (*begin)->next;
	free(top);
	top = NULL;
}

int	cmp_tree(void *content1, void *content2)
{
	if (((t_huffnode *)content1)->frequency >=
		((t_huffnode *)content2)->frequency)
		return (1);
	return (-1);
}	

int	cmp_frequency(void *content1, void *content2)
{
	if (((t_huffnode *)content1)->frequency >=
		((t_huffnode *)content2)->frequency)
		return (0);
	return (1);
}

void		init_huffnode(t_huffnode *node, char sym, int frequency)
{
	node->sym = sym;
	node->frequency = frequency;
	node->left = NULL;
	node->right = NULL;
}

void	build_tree(t_list **begin)
{	
	t_huffnode	*node;
	t_huffnode	father;
	
	while (begin && *begin && (*begin)->next)
	{
		node = (*begin)->content;
		init_huffnode(&father, 'F', node->frequency);
		father.right = node;
		pop_elem(begin);
		node = (*begin)->content;
		father.frequency += node->frequency;
		father.left = node;
		pop_elem(begin);
		ft_lst_sorted_insert(begin,
			ft_lstnew(&father, sizeof(t_huffnode)), &cmp_tree);
	}
}
