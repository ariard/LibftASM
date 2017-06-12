#include "compress.h"

int	cmp_tree(void *content1, void *content2)
{
	if (((t_huffnode *)content1)->frequency <=
		((t_huffnode *)content2)->frequency)
		return (1);
	return (-1);
}	

t_huffnode	*init_huffnode(char sym, float frequency) 
{
	t_huffnode	*node;

	if (!(node = (t_huffnode *)malloc(sizeof(*node))))
		return (NULL);
	node->sym = sym;
	node->frequency = frequency;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	build_tree(float tab_frequency[], t_huffnode *root)
{	
	int	i;

	i = -1;
	(void)tab_frequency;
	(void)root;
}
