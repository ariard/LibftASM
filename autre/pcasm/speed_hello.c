#include <unistd.h>

int		main(void)
{
	int	a;
	int	b;

	a = 0;
	b = 100000;
	while (a++ < b)
		write(1, "Hello World\n", 13);
	return (0);
}
