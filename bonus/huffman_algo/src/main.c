#include "compress.h"

int	main(int argc, char **argv)
{
	char		*data;
	char		buffer[1000 + 1];
	unsigned char	*compressed;
	int		fd;
	int		size;
	int		len;

	(void)argc;
	bzero(buffer, 1000);
	if (!argv[1])
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!(data = (char *)malloc(1000)))
		return (1);
	while ((len = read(fd, buffer, 1000)))
	{
		buffer[len] = 0;
		data = realloc(data, strlen(data) + len);
		strcat(data, buffer);
	}
	size = compress(data, &compressed);
	close(fd);
	free(data);
	fd = open("file_compressed", O_CREAT | O_WRONLY, 0644);
	while (size-- && fd >= 0)
		write(fd, compressed++, 1);
	close(fd);
	return (0);
}
