#include "compress.h"

int	main(int argc, char **argv)
{
	char	*data;
	char	buffer[1000];
	char	*compressed;
	int	fd;

	(void)argc;
	if (!argv[1])
		return (0);
	if (!(data = malloc(1000)))
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buffer, 1000))
	{
		data = realloc(data, 1000);
		strcat(data, buffer);		
	}
	compress(data, &compressed);
	return (0);
}
