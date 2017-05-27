#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>


extern void 	ft_bzero(void *s, size_t n);

extern size_t	ft_strlen(char *s);

extern int		ft_isalpha(int c);

extern int		ft_isdigit(int c);

extern int		ft_isalnum(int c);


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

	STRLEN - simple test

	char	*a;
	int		b;

	a = "Hello Bonjour";

		
	printf("%zu\n", strlen(a));
	printf("%zu\n", ft_strlen(a));

	STRLEN - big test

	char	a[100000];
	int		i = -1;

	while (++i < 100000)
		a[i] = 'A';
	printf("%zu\n", strlen(a));
	printf("%zu\n", ft_strlen(a));

	MEMCPY - simple test

	
	ISALPHA - test

	if (ft_isalpha('A'))
		printf("A is alpha\n");
	else
		printf("A isn t alpha\n");

	if (ft_isalpha('Y'))
		printf("Y is alpha\n");
	else
		printf("Y isn t alpha\n");

	if (ft_isalpha('_'))
		printf("_ is alpha\n");
	else
		printf("_ isn t alpha\n");

	if (ft_isalpha('a'))
		printf("a is alpha\n");
	else
		printf("a isn t alpha\n");

	if (ft_isalpha('z'))
		printf("z is alpha\n");
	else
		printf("z isn t alpha\n");


	ISDIGIT - test

	if (ft_isdigit('0'))
		printf("0 is alpha\n");
	else
		printf("0 isn t alpha\n");

	if (ft_isdigit('9'))
		printf("9 is alpha\n");
	else
		printf("9 isn t alpha\n");

	if (ft_isdigit('5'))
		printf("5 is alpha\n");
	else
		printf("5 isn t alpha\n");

	if (ft_isdigit('t'))
		printf("t is alpha\n");
	else
		printf("t isn t alpha\n");

	ISALNUM - test
*/

	if (ft_isalnum('9'))
		printf("9 is alpha\n");
	else
		printf("9 isn t alpha\n");


	if (ft_isalnum('5'))
		printf("5 is alpha\n");
	else
		printf("5 isn t alpha\n");

	if (ft_isalnum('t'))
		printf("t is alpha\n");
	else
		printf("t isn t alpha\n");

	if (ft_isalnum('B'))
		printf("B is alpha\n");
	else
		printf("B isn t alpha\n");

	if (ft_isalnum('-'))
		printf("- is alpha\n");
	else
		printf("- isn t alpha\n");
	
	
	return (0);
}
