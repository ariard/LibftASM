#include "compress.h"

int	do_compress(unsigned char **compressed, t_huffelem table[], char *ori,
	int tab_frequency[])
{
	int				i;
	int				ipos;
	int				opos;
	int				cpos;
	int				c;
	int				size;
	unsigned char	*comp;
	unsigned char	*temp;
	int				hsize;	

	size = ft_strlen(ori);
	comp = NULL;
	hsize = sizeof(int) + (SIZE + 1);
	if ((comp = (unsigned char *)malloc(hsize)) == NULL)
		return (-1);
	memcpy(comp, &size, sizeof(int));
	DG("size is %d", size);

	for (c = 0; c <= SIZE; c++)
		comp[sizeof(int) + c] = (unsigned char)tab_frequency[c];
	opos = hsize * 8;

	ipos = 0;
	while (ipos < size)
	{
		c = ori[ipos];	
		for (i = 0; i < table[c].size; i++)
		{
			if (opos % 8 == 0)
			{
				if ((temp = (unsigned char *)realloc(comp, (opos / 8) + 1)) == NULL)
				{
					free(comp);
					return (-1);
				}
				comp = temp;
			}
			cpos = (sizeof(short) * 8) - table[c].size + i;
			bit_set(comp, opos, bit_get((unsigned char *)&table[c].code, cpos));
			opos++;
		}
		ipos++;
	}
	*compressed = comp;
	return (((opos - 1) / 8) + 1);
}
