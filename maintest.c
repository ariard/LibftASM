#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"

// -set test
// - do it
// - verify
// - print

void	test_bzero(void)
{
	char	a[16 + 1];
	char	wit[16];
	int	i;

	ft_bzero(NULL, 100);	
	printf(GREEN"bzero - NULL ptr\n"RESET);


	ft_bzero(a, 0);
	printf(GREEN"bzero - 0 size\n"RESET);
	

	ft_bzero(a, -10);			
	printf(GREEN"bzero - negative size\n"RESET); 


	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	ft_bzero(a, 16);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
			printf(RED"bzero - simple test\n"RESET);
	if (i == 16)
		printf(GREEN"bzero - simple test\n"RESET);


	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	strcpy(wit, "hello world");
	bzero(wit[4], 5);
	ft_bzero(a[4], 5);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
			printf(RED"bzero - simple test 2\n"RESET);
	if (i == 16)
		printf(GREEN"bzero - simple test 2\n"RESET);


	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	strcpy(wit, "hello world");
	bzero(wit[6], 20);
	ft_bzero(a[6], 20);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
			printf(RED"bzero - simple test 3\n"RESET);
	if (i == 16)
		printf(GREEN"bzero - simple test 3\n"RESET);
}

void	test_strcat(void)
{
	char	*test[16] = "hello ";
	char	*wit[16] = "hello ";
	char	*test2[8] = "hello ";
	char	*wit2[8] = "hello ";
	char	*test3[1000 + 1];
	char	*wit2[1000 + 1] = "hello ";
	char	*b = "world!";
	char	c[1000 + 1];
	int	i;

	ft_strcat(NULL, NULL);	
	printf(GREEN"strcat - NULL str\n"RESET);


	strcat(wit, b);
	ft_strcat(test, b);
	i = -1;
	while (++i < 16)
		if (test[i] != wit[i])
			printf(RED"strcat - simple test\n"RESET);
	if (i == 16)
		printf(GREEN"strcat - simple test\n"RESET);


	strcat(wi2t, b);
	ft_strcat(test2, b);
	i = -1;
	while (++i < 16)
		if (test2[i] != wit2[i])
			printf(RED"strcat - too short s1\n"RESET);
	if (i == 16)
		printf(GREEN"strcat - too short s1\n"RESET);


	memset(c, 'A', 1000);
	strcat(wi3t, c);
	ft_strcat(wit3, c);
	i = -1;
	while (++i < 1000)
		if (test3[i] != wit3[i])
			printf(RED"strcat - fat s2\n"RESET);
	if (i == 1000)
		printf(GREEN"strcat - fat s2\n"RESET);
}
	
void	test_isalpha(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isalpha(i) == isalpha(i))
			printf(GREEN"isalpha - %c\n"RESET, i);
		else
			printf(RED"isalpha - %c\n"RESET, i);
	}
}


void	test_isdigit(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isdigit(i) == isdigit(i))
			printf(GREEN"isdigit - %c\n"RESET, i);
		else
			printf(RED"isdigit - %c\n"RESET, i);
	}
}

void	test_isalnum(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isalnum(i) == isalnum(i))
			printf(GREEN"isalnum - %c\n"RESET, i);
		else
			printf(RED"isalnum - %c\n"RESET, i);
	}
}

void	test_isprint(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isprint(i) == isprint(i))
			printf(GREEN"isprint - %c\n"RESET, i);
		else
			printf(RED"isprint - %c\n"RESET, i);
	}
}

void	test_toupper(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_toupper(i) == toupper(i))
			printf(GREEN"toupper - %c\n"RESET, i);
		else
			printf(RED"toupper - %c\n"RESET, i);
	}
}


void	test_tolower(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_tolower(i) == tolower(i))
			printf(GREEN"tolower - %c\n"RESET, i);
		else
			printf(RED"tolower - %c\n"RESET, i);
	}
}

void	test_puts(void)
{
	ft_puts(NULL);
	printf(GREEN"puts - NULL ptr\n"RESET);


	ft_puts(GREEN"puts - my own printer\n"RESET);
}
	
void	test_strlen(void)
{
	char	a[1000 + 1];

	ft_strlen(NULL);
	printf(GREEN"strlen - NULL ptr\n"RESET);


	if (ft_strlen("") != strlen(""))
		printf(RED"strlen - nothing string\n"RESET);
	else
		printf(GREEN"strlen - nothing string\n"RESET);


	if (ft_strlen("little string") != strlen("little string"))
		printf(RED"strlen - little  string\n"RESET);
	else
		printf(GREEN"strlen - little string\n"RESET);


	if (ft_strlen("st\nrin\tg") != strlen("st\nrin\tg"))
		printf(RED"strlen - special char string\n"RESET);
	else
		printf(GREEN"strlen - special char string\n"RESET);


	memset(a, 'A', 1000);	
	if (ft_strlen(a) != strlen(a))
		printf(RED"strlen - fat string\n"RESET);
	else
		printf(GREEN"strlen - fat string\n"RESET);
}

void	test_memset(void)
{
	
			

int	main(int argc, char **argv)
{
	test_bzero();
	test_strcat();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_tolower();
	test_toupper();
	test_puts();
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();
	return (0);
}
