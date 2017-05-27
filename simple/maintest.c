
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>


extern void 	ft_bzero(void *s, size_t n);

extern size_t	ft_strlen(char *s);

int		main(void)
{

/* 	BZERO - simple test
	char	a[16];

	strcpy(a, "[Hello World!]\n");
	write(1, &a[0], 15);
	ft_bzero(&a[1], 12);
	write(1, &a[0], 15);
	return (0);

	BZERO - more test	

	char	a[100000];
	int		i = -1;
	int		c = 10;

	while (++i < 100000)
		a[i] = 'A';
	write(1, &a[0], 100000);
	ft_bzero(&a[0], 100000);
	write (1, &c, 1);
	c = 68;
	write (1, &c, 1);
	write(1, &a[0], 100000);

*/

	char	*a;
	int		b;

	a = "Hello Bonjour";

		
	printf("%zu\n", strlen(a));
	printf("%zu\n", ft_strlen(a));

	return (0);
}
