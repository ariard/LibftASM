#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	other(int argc, char **argv)
{
	char	*data;
	char	buffer[1000 + 1];
	int	fd;
	int	len;

	(void)argc;
	bzero(buffer, 1000);
	if (!argv[1])
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!(data = malloc(1000)))
		return (0);
	while ((len = read(fd, buffer, 1000)))
	{
		buffer[len] = 0;
		data = reallocf(data, 1000);
		strcat(data, buffer);
	}
	free(data);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (1)
	{
		other(argc, argv);
		printf("%d\n", i++);
	}
	return (1);
}
