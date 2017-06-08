#include <unistd.h>

void	main(void)
{
	char	buffer[60];
		
	read(1, buffer, 100);
}
