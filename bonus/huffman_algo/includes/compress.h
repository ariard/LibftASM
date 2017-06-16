#ifndef COMPRESS_H
# define COMPRESS_H

# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/ioctl.h>

# include "../libft/includes/libft.h"

# define SIZE		256.0
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))

struct s_huffnode
{
	int 			frequency;
	unsigned char 		sym;
	struct s_huffnode 	*left;
	struct s_huffnode 	*right;
};

struct s_huffelem
{
	unsigned short 	code;
	unsigned short	size;
};

typedef struct s_huffnode	t_huffnode;

typedef struct s_huffelem	t_huffelem;

int		compress(char *original, unsigned char **compressed);

int		cmp_tree(void *content1, void *content2);

void		init_huffnode(t_huffnode *huffnode, char sym, int frequency);

void		build_tree(t_list **begin);

void		build_table(t_huffnode *root, t_huffelem table[], unsigned short code, unsigned short size);

int		do_compress(unsigned char **compressed, t_huffelem table[], char *ori, int tab_frequency[]);

/* Debug */

void		read_tab_frequency(float tab_frequency[]);

void		read_prio_frequency(t_list **begin);	

void		read_tab_code(t_huffelem table[], int tab_frequency[]);

void		hufftree_print(t_huffnode *root);

void		bit_set(unsigned char *bits, int pos, int state);

int		bit_get(const unsigned char  *bits, int pos);

#endif
