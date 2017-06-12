#include <stdio.h>

int	foo(void)
{
	return 2;
}

void	main(void)
{
	char	*array;

	array = "hello world";
	printf("%s\n", array + foo());
}
