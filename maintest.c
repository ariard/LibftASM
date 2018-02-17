#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "libft.h"

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

void	test_bzero(void)
{
	char	a[16 + 1];
	char	wit[16];
	int	i;

	dprintf(2, "test_bzero 1\n");
	ft_bzero(NULL, 100);
	printf(GREEN"bzero - NULL ptr\n"RESET);

	dprintf(2, "test_bzero 2\n");

	ft_bzero(a, 0);
	printf(GREEN"bzero - 0 size\n"RESET);
	
	bzero(a, 16);
	bzero(wit, 16);
	strcpy(a, "hello world");
	ft_bzero(a, 16);
	i = -1;
	while (++i < 16)
		if (a[i] != wit[i])
		{
			printf(RED"bzero - simple test\n"RESET);
			break;
		}
	if (i == 16)
		printf(GREEN"bzero - simple test\n"RESET);


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
			break;
		}
	if (i == 16)
		printf(GREEN"bzero - simple test 2\n"RESET);
}

void	test_strcat(void)
{
	char	test[16] = "hello ";
	char	wit[16] = "hello ";
	char	test2[8] = "hello ";
	char	wit2[8] = "hello ";
	char	test3[1000 + 1];
	char	wit3[1000 + 1];
	char	*b = "world!";
	char	c[1000];
	int	i;

	ft_strcat(NULL, NULL);	
	printf(GREEN"strcat - NULL str\n"RESET);


	strcat(wit, b);
	ft_strcat(test, b);
	i = -1;
	while (++i < 16)
		if (test[i] != wit[i])
		{
			printf(RED"strcat - simple test\n"RESET);
			break;
		}
	if (i == 16)
		printf(GREEN"strcat - simple test\n"RESET);

//	strcat(wit2, b);
//	ft_strcat(test2, b);
//	i = -1;
//	while (++i < 16)
//		if (test2[i] != wit2[i])
//		{
//			printf(RED"strcat - too short s1\n"RESET);
//			break;
//		}
//	if (i == 16)
//		printf(GREEN"strcat - too short s1\n"RESET);

	memset(wit3, 0, 1000);
	memset(c, 'A', 1000);
	strcat(wit3, c);
	memset(c, 'A', 1000);
	ft_strcat(test3, c);
	i = -1;
	while (++i < 1000)
		if (test3[i] != wit3[i])
		{
			printf(RED"strcat - fat s2\n"RESET);
			break;
		}
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

void	test_isascii(void)
{
	char	i;

	i = -1;
	while (++i < 127)
	{
		if (ft_isascii(i) == isascii(i))
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

# define COND(w, x, y, z)		if (!strcmp(argv[1], x) || !strcmp(argv[1], y) || !strcmp(argv[1], z)) { w; }

void	test_memcpy(void)
{
	char	test[1000 + 1];
	char	wit[1000 + 1];
	char	buf[1000 + 1];
	char	test2[8] = "hello ";
	char	wit2[8] = "hello ";
	char	test3[1000 + 1];
	char	wit3[1000 + 1] = "hello ";
	char	*b = "world!";
	char	c[1000 + 1];
	char	*d;
	int	i;

	ft_memcpy(NULL, NULL, 10);	
	printf(GREEN"memcpy - NULL str\n"RESET);
	
	ft_memcpy("hello", "world", 0);	
	printf(GREEN"memcpy - 0 size\n"RESET);

//	memset(test3, 'A', 1000);
// 	ft_memcpy("hello", 'A' 
//	printf(GREEN"memcpy - overflow memcpy\n"RESET);
//	bus error 

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
			break;
		}
	if (i == 1000)
		printf(GREEN"memcpy - simple test\n"RESET);

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
			break;
		}
	if (i == 1000)
		printf(GREEN"memcpy - simple test 2\n"RESET);

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
			break; 
		}
	if (i == 1000)
		printf(GREEN"memcpy - simple test 3\n"RESET);

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
			break; 
		}
	if (i == 1000)
		printf(GREEN"memcpy - simple test 4\n"RESET);
}

void	test_strdup(void)
{
	char	*b = "hello world";
	char	*d;
	char	c[20];
	int	i;

	ft_test("hello");
	return;
	ft_strdup(NULL);

//	d = strdup(b);
//	i = -1;
//	while (++i < 11)
//		if (d[i] != b[i])
//		{
//			printf(RED"strdup - simple test\n"RESET);
//			break;
//		}
//	if (i == 11)
//		printf(GREEN"strdup - simple test\n"RESET);

	ft_strdup("hello");
//	printf(GREEN"strdup - simple test 2\n"RESET);
}

void	test_memset(void)
{
	char	test[20];
	char	wit[20];
	int	i;

	ft_memset(NULL, 0, 0);
	printf(GREEN"memset - NULL str\n"RESET);

	memset(wit, 'A', 20);
	ft_memset(test, 'A', 20);
	i = -1;
	while (++i < 20)
		if (test[i] != wit[i])
		{
			printf(RED"memset - simple test\n"RESET);
			break;
		}
	if (i == 20)
		printf(GREEN"memset - simple test\n"RESET);

	memset(wit, 'B', 0);
	ft_memset(test, 'B', 0);
	i = -1;
	while (++i < 20)
		if (test[i] != wit[i])
		{
			printf(RED"memset - 0 size\n"RESET);
			break;
		}
	if (i == 20)
		printf(GREEN"memset - 0 size\n"RESET);
}

void	test_strcmp(void)
{
	ft_strcmp(NULL, "a");
	printf(GREEN"strcmp - NULL s1\n");

	ft_strcmp("b", NULL);
	printf(GREEN"strcmp - NULL s2\n");

	if (ft_strcmp("hello", "world") == strcmp("hello", "world"))	
		printf(GREEN"strcmp - simple test\n"RESET);
	else
		printf(RED"strcmp - simple test\n"RESET);

	if (ft_strcmp("world", "hello") == strcmp("world", "hello"))	
		printf(GREEN"strcmp - simple test 2\n"RESET);
	else
		printf(RED"strcmp - simple test 2\n"RESET);

	if (ft_strcmp("hello", "hello") == strcmp("hello", "hello"))	
		printf(GREEN"strcmp - equal test\n"RESET);
	else
		printf(RED"strcmp - equal test\n"RESET);

	if (ft_strcmp("", "") == strcmp("", ""))	
		printf(GREEN"strcmp - equal test 2\n"RESET);
	else
		printf(RED"strcmp - equal test 2\n"RESET);
}

void	test_strrev(void)
{
	char	*a;
	char	s1[20];
	char	s2[20];

	ft_strrev(NULL);
	printf(GREEN"strrev - NULL s1\n");

	ft_strrev("");
	printf(GREEN"strrev - 0 s1\n");

	bzero(s1, 20);
	strcpy(s1, "hello world");
	bzero(s2, 20);
	strcpy(s2, "hello world");
	if (!strcmp(ft_strrev(s1), strrev(s2)))
		printf(GREEN"strrev - simple test\n"RESET);
	else
		printf(RED"strrev - simple test\n"RESET);

	bzero(s1, 20);
	strcpy(s1, "kayak");
	bzero(s2, 20);
	strcpy(s2, "kayak");
	if (!strcmp(ft_strrev(s1), strrev(s2)))
		printf(GREEN"strrev - simple test 2\n"RESET);
	else
		printf(RED"strrev - simple test 2\n"RESET);
	
	memset(s1, 'A', 20);
	s1[19] = 0;
	memset(s2, 'A', 20);
	s2[19] = 0;
	if (!strcmp(ft_strrev(s1), strrev(s2)))
		printf(GREEN"strrev - simple test 3\n"RESET);
	else
		printf(RED"strrev - simple test 3\n"RESET);
}

void	test_strstr(void)
{
	char	*a;
	char	*b;
	int		c;

	ft_strstr(NULL, "needle");
	printf(GREEN"strstr - NULL ptr\n");

	ft_strstr("haystack", NULL);
	printf(GREEN"strstr - NULL ptr2\n");
	
	ft_strstr("", "needle");
	printf(GREEN"strstr - 0 ptr\n");

	ft_strstr("haystack", "");
	printf(GREEN"strstr - 0 ptr\n");

	a = ft_strstr("", "");
	b = strstr("", "");
	if (a && b)
	{
		if (!(strcmp(a, b)))
			printf(GREEN"strstr - simple test\n"RESET);
		else
			printf(RED"strstr - simple test\n"RESET);
	}
	else if (a == b)
		printf(GREEN"strstr - simple test\n"RESET);

	if (!strcmp(ft_strstr("abcdef", "ef"), strstr("abcdef", "ef")))
		printf(GREEN"strstr - simple test 2\n"RESET);
	else
		printf(RED"strstr - simple test 2\n"RESET);

	if (!strcmp(ft_strstr("abcdefabcdefg", "efg"), strstr("abcdefabcdefg", "efg")))
		printf(GREEN"strstr - simple test 3\n"RESET);
	else
		printf(RED"strstr - simple test 3\n"RESET);

	a = ft_strstr("abcdefabcdefg", "xyz");
	b = ft_strstr("abcdefabcdefg", "xyz");
	if (a && b)
	{
		if (!strcmp(a, b))
			printf(GREEN"strstr - simple test 4\n"RESET);
		else
			printf(RED"strstr - simple test 4\n"RESET);
	}
	else if (a == b)
		printf(GREEN"strstr - simple test 4\n"RESET);

	if (!strcmp(ft_strstr("abcdefabcdefg", "e"), strstr("abcdefabcdefg", "e")))
		printf(GREEN"strstr - simple test 5\n"RESET);
	else
		printf(RED"strstr - simple test 5\n"RESET);
}

void	test_strchr(void)
{
	char	*a;
	char	*b;

	ft_strchr(NULL, 20);
	printf(GREEN"strchr - NULL ptr\n");

	ft_strchr("", 20);
	printf(GREEN"strchr - 0 s1\n");

	if (!strcmp(ft_strchr("abc", 0), strchr("abc", 0)))
		printf(GREEN"strchr - simple test\n"RESET);
	else
		printf(RED"strchr - simple test\n"RESET);

	if (!strcmp(ft_strchr("abcdefghijlmno", 109), strchr("abcdefghijlmno", 109)))
		printf(GREEN"strchr - simple test 2\n"RESET);
	else
		printf(RED"strchr - simple test 2\n"RESET);

	a = strchr("abcdefghijlmno", 120);
	b  = ft_strchr("abcdefghijlmno", 120);
	if (a && b)
	{
		if (!strcmp(ft_strchr("abcdefghijlmno", 120), strchr("abcdefghijlmno", 120)))
			printf(GREEN"strchr - simple test 3\n"RESET);
		else
			printf(RED"strchr - simple test 3\n"RESET);
	}
	else if (a == b)
		printf(GREEN"strchr - simple test 3\n"RESET);


	if (!strcmp(ft_strchr("a", 97), strchr("a", 97)))
		printf(GREEN"strchr - simple test 4\n"RESET);
	else
		printf(RED"strchr - simple test 4\n"RESET);
	
}

void	test_strjoin(void)
{
	printf("%s\n", ft_strjoin("hello", "world"));
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
	return (0);
}
