#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[100];
	int		tmp;

	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 100);
	tmp = htons((int)buf[0]);
	printf("%d", tmp);
	return (0);
}
