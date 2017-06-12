#ifndef COMPRESS_H
# define COMPRESS_H

# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/includes/libft.h"

# define SIZE		256.0

struct s_huffnode
{
	float 			frequency;
	char 			sym;
	struct s_huffnode 	*left;
	struct s_huffnode 	*right;
};

typedef struct s_huffnode	t_huffnode;

int		compress(char *original, char **compressed);

int		cmp_tree(void *content1, void *content2);

t_huffnode	*init_huffnode(char sym, float frequency);

void		build_tree(float tab_frequency[], t_huffnode *root);	

/* Debug */

void		read_tab_frequency(float tab_frequency[]);

void		read_prio_frequency(t_list **begin);	

#endif
