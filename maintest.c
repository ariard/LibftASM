#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "libft.h"

int		good = 0;
int		total = 0;

#define T(x)  total++; if (x == 1) { good++; }

char	*strrev(char *str)
{
	int		len;
	char	tmp;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		tmp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

char	*strjoin(const char *s1, const char *s2)
{
	char	*join;

	if (!(join = (char *)malloc(strlen(s1) + strlen(s2) + 1)))
		return (NULL);
	if (s1)
		strcpy(join, s1);
	if (s2)
		strcat(join, s2);
	return (join);
}

void	test_bzero(void)
{
	char	a[16 + 1];
	char	wit[16];
	int	i;

	ft_bzero(NULL, 100);
	printf(GREEN"bzero - NULL ptr\n"RESET);
	T(1)

	ft_bzero(a, 0);
	printf(GREEN"bzero - 0 size\n"RESET);
	T(1)
	
	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	ft_bzero(a, 16);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
		{
			printf(RED"bzero - simple test\n"RESET);
			T(0)
			break;
		}
	if (i == 16)
	{
		printf(GREEN"bzero - simple test\n"RESET);
		T(1)
	}


	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	strcpy(wit, "hello world");
	bzero(&wit[4], 5);
	ft_bzero(&a[4], 5);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
		{
			printf(RED"bzero - simple test 2\n"RESET);
			T(0)
			break;
		}
	if (i == 16)
	{
		printf(GREEN"bzero - simple test 2\n"RESET);
		T(1)
	}

	memset(wit, 'A', 16);
	memset(a, 'A', 16);
	bzero(wit, 1);
	ft_bzero(a, 1);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
		{
			printf(RED"bzero - simple test 3\n"RESET);
			T(0)
			break;
		}
	if (i == 16)
	{
		printf(GREEN"bzero - simple test 3\n"RESET);
		T(1)
	}
}

#define SIZE2	1000

void	test_strcat(void)
{
	char	test[16] = "hello ";
	char	wit[16] = "hello ";
	char	test3[SIZE2 + 1];
	char	wit3[SIZE2 + 1];
	char	*b = "world!";
	char	c[SIZE2 -1];
	char	*s1;
	char	*s2;
	int	i;

	ft_strcat(NULL, NULL);	
	printf(GREEN"strcat - NULL str\n"RESET);
	T(1)

	ft_strcat("", "");
	printf(GREEN"strcat - 0 char\n"RESET);
	T(1)

	s1 = strcat(wit, b);
	s2 = ft_strcat(test, b);
	i = -1;
	while (++i < 16)
		if (s1[i] != s2[i])
		{
			printf(RED"strcat - simple test\n"RESET);
			T(0)
			break;
		}
	if (i == 16)
	{
		printf(GREEN"strcat - simple test\n"RESET);
		T(1)
	}


	memset(wit3, 0, SIZE2 + 1);
	bzero(c, SIZE2);
	memset(c, 'A', SIZE2 - 1);
	s1 = strcat(wit3, c);
	memset(test3, 0, SIZE2 + 1);
	bzero(c, SIZE2);
	memset(c, 'A', SIZE2 - 1);
	s2 = ft_strcat(test3, c);
	i = -1;
	while (++i < SIZE2)
		if (s1[i] != s2[i])
		{
			printf(RED"strcat - fat s2\n"RESET);
			T(0)
			break;
		}
	if (i == SIZE2)
	{
		printf(GREEN"strcat - fat s2\n"RESET);
		T(1)
	}
}

void	test_isalpha(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isalpha(i) == isalpha(i))
		{
			printf(GREEN"isalpha - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"isalpha - %c\n"RESET, i);
			T(0)
		}
	}
}

void	test_isascii(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isascii(i) == isascii(i))
		{
			printf(GREEN"isascii - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"isascii - %c\n"RESET, i);
			T(0)
		}
	}
}


void	test_isdigit(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isdigit(i) == isdigit(i))
		{
			printf(GREEN"isdigit - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"isdigit - %c\n"RESET, i);
			T(0)
		}
	}
}

void	test_isalnum(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isalnum(i) == isalnum(i))
		{
			printf(GREEN"isalnum - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"isalnum - %c\n"RESET, i);
			T(0)
		}
	}
}

void	test_isprint(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isprint(i) == isprint(i))
		{
			printf(GREEN"isprint - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"isprint - %c\n"RESET, i);
			T(0)
		}
	}
}

void	test_toupper(void)
{
	char	i;
	char	b;
	char	c;

	i = -1;
	while (++i < 127)
	{
		if ((b = ft_toupper(i)) == (c = toupper(i)))
		{
			printf(GREEN"toupper - %c vs %c\n"RESET, b, c);
			T(1)
		}
		else
		{
			printf(RED"toupper - %c vs %c\n"RESET, b, c);
			T(0)
		}
	}
}


void	test_tolower(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_tolower(i) == tolower(i))
		{
			printf(GREEN"tolower - %c\n"RESET, i);
			T(1)
		}
		else
		{
			printf(RED"tolower - %c\n"RESET, i);
			T(0)
		}
	}
}

void	test_puts(void)
{
	char	buf[10000];

	ft_puts(NULL);
	printf(GREEN"puts - NULL ptr\n"RESET);
	T(1)

	if (ft_puts("") < 0)
	{
		printf(RED"puts - 0 char *\n"RESET);
		T(0)
	}
	else
	{
		printf(GREEN"puts - 0 char *\n"RESET);
		T(1)
	}

	ft_puts(GREEN"puts - my own printer"RESET);
	T(1)

	bzero(buf, 10000);
	strcpy(buf, "puts");
	memset(&buf[4], 'C', 9995 - 1);
	ft_puts(buf);
	write(1, "\n", 1);
	T(1)
}

void	test_strlen(void)
{
	char	a[1000 + 1];

	ft_strlen(NULL);
	printf(GREEN"strlen - NULL ptr\n"RESET);
	T(1)

	if (ft_strlen("") != strlen(""))
	{
		printf(RED"strlen - nothing string\n"RESET);
		T(0)
	}	
	else
	{
		printf(GREEN"strlen - nothing string\n"RESET);
		T(1)
	}

	if (ft_strlen("little string") != strlen("little string"))
	{
		printf(RED"strlen - little  string\n"RESET);
		T(0)
	}
	else
	{
		printf(GREEN"strlen - little string\n"RESET);
		T(1)
	}

	if (ft_strlen("st\nrin\tg") != strlen("st\nrin\tg"))
	{
		printf(RED"strlen - special char string\n"RESET);
		T(0)
	}
	else
	{
		printf(GREEN"strlen - special char string\n"RESET);
		T(1)
	}

	memset(a, 'A', 1000);	
	if (ft_strlen(a) != strlen(a))
	{
		printf(RED"strlen - fat string\n"RESET);
		T(0)
	}
	else
	{
		printf(GREEN"strlen - fat string\n"RESET);
		T(1)
	}
}

# define COND(w, x, y, z)		if (!strcmp(argv[1], x) || !strcmp(argv[1], y) || !strcmp(argv[1], z)) { w; }

void	test_memcpy(void)
{
	char	test[1000 + 1];
	char	wit[1000 + 1];
	char	buf[1000 + 1];
	char	*d;
	int	i;

	ft_memcpy(NULL, "str", 10);	
	printf(GREEN"memcpy - NULL str\n"RESET);
	T(1)

	ft_memcpy(test, NULL, 10);	
	printf(GREEN"memcpy - NULL s2\n"RESET);
	T(1)
	
	ft_memcpy("hello", "world", 0);	
	printf(GREEN"memcpy - 0 size\n"RESET);
	T(1)

	memset(test, 'A', 1000);
	memcpy(wit, test, 1000);
	memset(test, 'A', 1000);
	memcpy(wit, test, 1000);
	ft_memcpy(buf, test, 1000);
	i = -1;
	while (++i < 1000)
		if (buf[i] != wit[i])
		{
			printf(RED"memcpy - simple test\n"RESET);
			T(0)
			break;
		}
	if (i == 1000)
	{
		printf(GREEN"memcpy - simple test\n"RESET);
		T(1)
	}

	bzero(test, 1000);
	memset(test, 'B', 500);
	memcpy(wit, test, 1000);
	bzero(test, 1000);
	memset(test, 'B', 500);
	ft_memcpy(buf, test, 1000);
	i = -1;
	while (++i < 1000)
		if (buf[i] != wit[i])
		{
			printf(RED"memcpy - simple test 2\n"RESET);
			T(0)
			break;
		}
	if (i == 1000)
	{
		printf(GREEN"memcpy - simple test 2\n"RESET);
		T(1)
	}

	bzero(test, 1000);
	memset(&test[500], 'A', 500);
	memcpy(wit, test, 1000);
	bzero(test, 1000);
	memset(&test[500], 'A', 500);
	ft_memcpy(buf, test, 1000);
	i = -1;
	while (++i < 1000)
		if (buf[i] != wit[i])
		{
			printf(RED"memcpy - simple test 3\n"RESET);
			T(0)
			break; 
		}
	if (i == 1000)
	{
		printf(GREEN"memcpy - simple test 3\n"RESET);
		T(1)
	}

	bzero(test, 1000);
	memset(&test[500], 'A', 500);
	memcpy(wit, test, 1000);
	bzero(test, 1000);
	memset(&test[500], 'A', 500);
	d = ft_memcpy(buf, test, 1000);
	i = -1;
	while (++i < 1000)
		if (d[i] != wit[i])
		{
			printf(RED"memcpy - simple test 4\n"RESET);
			T(0)
			break; 
		}
	if (i == 1000)
	{
		printf(GREEN"memcpy - simple test 4\n"RESET);
		T(1)
	}
}

# define SIZE	100000

void	test_strdup(void)
{
	char	*little = "hello world";
	char	fat[SIZE];
	char	*wit;
	char	*test;
	int	i;

	ft_strdup(NULL);
	printf(GREEN"strdup - NULL ptr\n"RESET);
	T(1)

	wit = strdup("");
	test = strdup("");
	i = -1;
	while (++i < 1)
		if (wit[i] != test[i])
		{
			printf(RED"strdup - 0 char\n"RESET);
			T(0)
			break;
		}
	free(test);
	if (i == 1)
	{
		printf(GREEN"strdup - 0 char\n"RESET);
		T(1)
	}

	wit = strdup(little);
	test = strdup(little);
	i = -1;	
	while (++i < 12)
		if (wit[i] != test[i])
		{
			printf(RED"strdup - simple test\n"RESET);
			T(0)
			break;
		}
	free(test);
	if (i == 12)
	{
		printf(GREEN"strdup - simple test\n"RESET);
		T(1)
	}

	bzero(fat, SIZE);	
	memset(fat, 'A', SIZE - 1);
	wit = strdup(fat);
	bzero(fat, SIZE);	
	memset(fat, 'A', SIZE - 1);
	test = strdup(fat);
	i = -1;	
	while (++i < SIZE)
		if (wit[i] != test[i])
		{
			printf(RED"strdup - fat test\n"RESET);
			T(0)
			break;
		}
	free(test);
	if (i == SIZE)
	{
		printf(GREEN"strdup - fat test\n"RESET);
		T(1)
	}

	bzero(fat, SIZE);	
	memset(fat, 'A', SIZE - 1);
	fat[50000] = 0;
	wit = strdup(fat);
	bzero(fat, SIZE);	
	memset(fat, 'A', SIZE - 1);
	fat[50000] = 0;
	test = strdup(fat);
	i = -1;	
	while (++i < 50000)
		if (wit[i] != test[i])
		{
			printf(RED"strdup - cut-buffer test\n"RESET);
			T(0)
			break;
		}
	free(test);
	if (i == 50000)
	{
		printf(GREEN"strdup - cut-buffer test\n"RESET);
		T(1)
	}
}

void	test_memset(void)
{
	char	test[20];
	char	wit[20];
	char	*a;
	char	*b;
	int		i;
	int		j;

	ft_memset(NULL, 0, 0);
	printf(GREEN"memset - NULL str\n"RESET);
	T(1)

	bzero(test, 20);
	bzero(wit, 20);
	memset(wit, 'B', 0);
	ft_memset(test, 'B', 0);
	i = -1;
	while (++i < 20)
		if (test[i] != wit[i])
		{
			printf(RED"memset - 0 size : %s\n"RESET, test);
			T(0)
			break;
		}
	if (i == 20)
	{
		printf(GREEN"memset - 0 size : %s\n"RESET, test);
		T(1)
	}

	a = memset(wit, 'A', 20);
	b = ft_memset(test, 'A', 20);
	i = -1;
	while (++i < 20)
		if (a[i] != b[i])
		{
			printf(RED"memset - simple test\n"RESET);
			T(0)
			break;
		}
	if (i == 20)
	{
		printf(GREEN"memset - simple test\n"RESET);
		T(1)
	}

	i = 0;
	while (++i < 127)
	{
		bzero(test, 20);
		bzero(wit, 20);
		memset(wit, i, 20);
		ft_memset(test, i, 20);
		j = -1;
		while (++j < 20)
			{ 
				if (test[j] != wit[j])
				{
					printf(RED"memset - all test\n"RESET);
					T(0)
					break;
				}
			}
		if (j == 20)
		{
			printf(GREEN"memset - all test\n"RESET);			 
			T(1)
		}
	}
	return ;
}

/*
 * BONUS
*/

void	test_strcmp(void)
{
	ft_strcmp(NULL, "a");
	printf(GREEN"strcmp - NULL s1\n");
	T(1)

	ft_strcmp("b", NULL);
	printf(GREEN"strcmp - NULL s2\n");
	T(1)

	if (ft_strcmp("hello", "world") == strcmp("hello", "world"))	
	{
		printf(GREEN"strcmp - simple test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strcmp - simple test\n"RESET);
		T(0)
	}

	if (ft_strcmp("world", "hello") == strcmp("world", "hello"))	
	{
		printf(GREEN"strcmp - simple test 2\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strcmp - simple test 2\n"RESET);
		T(0)
	}

	if (ft_strcmp("hello", "hello") == strcmp("hello", "hello"))	
	{
		printf(GREEN"strcmp - equal test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strcmp - equal test\n"RESET);
		T(0)
	}

	if (ft_strcmp("", "") == strcmp("", ""))	
	{
		printf(GREEN"strcmp - equal test 2\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strcmp - equal test 2\n"RESET);
		T(0)
	}
}

void	test_strrev(void)
{
	char	s1[20];
	char	s2[20];

	ft_strrev(NULL);
	printf(GREEN"strrev - NULL s1\n");
	T(1)

	ft_strrev("");
	printf(GREEN"strrev - 0 s1\n");
	T(1)

	bzero(s1, 20);
	strcpy(s1, "hello world");
	bzero(s2, 20);
	strcpy(s2, "hello world");
	if (!strcmp(ft_strrev(s1), strrev(s2)))
	{
		printf(GREEN"strrev - simple test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strrev - simple test\n"RESET);
		T(0)
	}

	bzero(s1, 20);
	strcpy(s1, "kayak");
	bzero(s2, 20);
	strcpy(s2, "kayak");
	if (!strcmp(ft_strrev(s1), strrev(s2)))
	{
		printf(GREEN"strrev - simple test 2\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strrev - simple test 2\n"RESET);
		T(1)
	}
	
	memset(s1, 'A', 20);
	s1[19] = 0;
	memset(s2, 'A', 20);
	s2[19] = 0;
	if (!strcmp(ft_strrev(s1), strrev(s2)))
	{
		printf(GREEN"strrev - simple test 3\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strrev - simple test 3\n"RESET);
		T(0)
	}
}

void	test_strstr(void)
{
	char	*a;
	char	*b;

	ft_strstr(NULL, "needle");
	printf(GREEN"strstr - NULL ptr\n");
	T(1)

	ft_strstr("haystack", NULL);
	printf(GREEN"strstr - NULL ptr2\n");
	T(1)
	
	ft_strstr("", "needle");
	printf(GREEN"strstr - 0 ptr\n");
	T(1)

	ft_strstr("haystack", "");
	printf(GREEN"strstr - 0 ptr\n");
	T(1)

	a = ft_strstr("", "");
	b = strstr("", "");
	if (a && b)
	{
		if (!(strcmp(a, b)))
		{
			printf(GREEN"strstr - simple test\n"RESET);
			T(1)
		}
		else
		{
			printf(RED"strstr - simple test\n"RESET);
			T(0) 
		}
	}
	else if (a == b)
	{
		printf(GREEN"strstr - simple test\n"RESET);
		T(1)
	}

	if (!strcmp(ft_strstr("abcdef", "ef"), strstr("abcdef", "ef")))
	{
		T(1)
		printf(GREEN"strstr - simple test 2\n"RESET);
	}
	else
	{
		printf(RED"strstr - simple test 2\n"RESET);
		T(0)
	}

	if (!strcmp(ft_strstr("abcdefabcdefg", "efg"), strstr("abcdefabcdefg", "efg")))
	{
		printf(GREEN"strstr - simple test 3\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strstr - simple test 3\n"RESET);
		T(0)
	}

	a = ft_strstr("abcdefabcdefg", "xyz");
	b = ft_strstr("abcdefabcdefg", "xyz");
	if (a && b)
	{
		if (!strcmp(a, b))
		{
			printf(GREEN"strstr - simple test 4\n"RESET);
			T(1)
		}
		else
		{
			printf(RED"strstr - simple test 4\n"RESET);
			T(0)
		}
	}
	else if (a == b)
	{
		printf(GREEN"strstr - simple test 4\n"RESET);
		T(1)
	}

	if (!strcmp(ft_strstr("abcdefabcdefg", "e"), strstr("abcdefabcdefg", "e")))
	{
		printf(GREEN"strstr - simple test 5\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strstr - simple test 5\n"RESET);
		T(0)
	}

	if (!strcmp(ft_strstr("abcdefabcdefefgabcd", "efg"), strstr("abcdefabcdefefgabcd", "efg")))
	{
		printf(GREEN"strstr - simple test 6\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strstr - simple test 6\n"RESET);
		T(0)
	}
}

void	test_strchr(void)
{
	char	*a;
	char	*b;

	ft_strchr(NULL, 20);
	printf(GREEN"strchr - NULL ptr\n");
	T(1)

	ft_strchr("", 20);
	printf(GREEN"strchr - 0 s1\n");
	T(1)

	if (!strcmp(ft_strchr("abc", 0), strchr("abc", 0)))
	{
		printf(GREEN"strchr - simple test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strchr - simple test\n"RESET);
		T(0)
	}

	if (!strcmp(ft_strchr("abcdefghijlmno", 109), strchr("abcdefghijlmno", 109)))
	{
		printf(GREEN"strchr - simple test 2\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strchr - simple test 2\n"RESET);
		T(0)
	}

	a = strchr("abcdefghijlmno", 120);
	b  = ft_strchr("abcdefghijlmno", 120);
	if (a && b)
	{
		if (!strcmp(ft_strchr("abcdefghijlmno", 120), strchr("abcdefghijlmno", 120)))
		{
			printf(GREEN"strchr - simple test 3\n"RESET);
			T(1)
		}
		else
		{
			printf(RED"strchr - simple test 3\n"RESET);
			T(0)
		}
	}
	else if (a == b)
	{
		printf(GREEN"strchr - simple test 3\n"RESET);
		T(1)
	}

	if (!strcmp(ft_strchr("a", 97), strchr("a", 97)))
	{
		printf(GREEN"strchr - simple test 4\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strchr - simple test 4\n"RESET);
		T(0)
	}
}

#define SIZE3	1000
#define SIZE4	10000

void	test_strjoin(void)
{
	char	*s1;
	char	*s2;
	char	buf[SIZE3];
	char	buf2[SIZE4];

	ft_strjoin(NULL, NULL);
	printf(GREEN"strjoin - NULL ptr\n"RESET);
	T(1)
	
	s1 = ft_strjoin("hello", "world");
	if (!strcmp(s1, "helloworld"))
	{
		printf(GREEN"strjoin - simple test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strjoin - simple test\n"RESET);
		T(0)
	}
	
	bzero(buf, SIZE3);
	memset(buf, 'A', SIZE3 -1);

	bzero(buf2, SIZE4);
	memset(buf2, 'A', SIZE4 -1);
	s1 = ft_strjoin(buf, buf2);	
	s2 = strjoin(buf, buf2);
	if (!strcmp(s1, s2))
	{
		printf(GREEN"strjoin - fat test\n"RESET);
		T(1)
	}
	else
	{
		printf(RED"strjoin - fat test\n"RESET);
		T(0)
	}
}
	
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);

	COND(test_bzero(), "bzero", "part1", "all")
	COND(test_strcat(), "strcat", "part1", "all")
	COND(test_isalpha(), "isalpha", "part1", "all")
	COND(test_isdigit(), "isdigit", "part1", "all")
	COND(test_isalnum(), "isalnum", "part1", "all")
	COND(test_isascii(), "isascii", "part1", "all")
	COND(test_isprint(), "isprint", "part1", "all")
	COND(test_tolower(), "tolower", "part1", "all")
	COND(test_toupper(), "toupper", "part1", "all")
	COND(test_puts(), "puts", "part1", "all")
	COND(test_strlen(), "strlen", "part2", "all")
	COND(test_memset(), "memset", "part2", "all")
	COND(test_memcpy(), "memcpy", "part2", "all")
	COND(test_strdup(), "strdup", "part2", "all")
	COND(test_strcmp(), "strcmp", "bonus", "all")
	COND(test_strrev(), "strrev", "bonus", "all")
	COND(test_strstr(), "strstr", "bonus", "all")
	COND(test_strchr(), "strchr", "bonus", "all")
	COND(test_strjoin(), "strjoin", "bonus", "all")
	dprintf(1, "\n ------------------\n [RESULTAT] %d/%d\n", good, total);
	return (0);
}
