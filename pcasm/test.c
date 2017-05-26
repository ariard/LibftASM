#include <unistd.h>

void		foo(int a, int b)
{
	if (a < b)
	{
		write(1, "Hello World", 12);
		foo(a + 1, b);
	}
}


void		main(void)
{
	foo(0, 100);
}
