#include <unistd.h>
#include <fcntl.h>

void	cat(int fd)
{
	char	buffer[100];

	while ((read(fd, buffer, 100)));
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	cat(fd);
	return (0);
}
