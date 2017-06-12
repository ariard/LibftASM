#include "compress.h"

void		read_tab_frequency(float tab_frequency[])
{
	int	i;

	i = -1;
	while (++i < 257)
		printf("sym %c freq %f\n", i, tab_frequency[i]);
}
