#include <unistd.h>
#include <fcntl.h>

void	cat(int fd)
{
	char	buffer[100];
	int	nb;

	while ((nb =read(fd, buffer, 100)))
		write(1, buffer, nb);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	cat(fd);
	return (0);
}
