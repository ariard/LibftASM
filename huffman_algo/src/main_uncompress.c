#include "compress.h"

int		uncompress(unsigned char *data, unsigned char **uncompressed)
{
	t_list		*begin;
	int			tab_frequency[(int)SIZE + 1];
	int			size;
	t_huffnode	*node;

	ft_memcpy(&size, data, sizeof(int));
	DG("size is %d", size);
	begin = NULL;
	parse_freq(data, tab_frequency);
	DG("gen lst freq");
	gen_lst_freq(&begin, tab_frequency);
	read_prio_frequency(&begin);
	return (0);
	data = data + 4 + SIZE;
	build_tree(&begin);
	node = begin->content;
	*uncompressed = (unsigned char *)malloc(sizeof(unsigned char *) * size + 1);
	parse_tree(node, uncompressed, &data);
	return (size);
}

int		main(int argc, char **argv)
{
	unsigned char			*data;
	unsigned char			*begin;
	unsigned char			*uncompressed;
	char					*name;
	int						fd;
	int						size;
	struct stat				buf;

	(void)argc;
	if (!argv[1])
		return (0);
	fd = open(argv[1], O_RDONLY);
	fstat(fd, &buf);
	data = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	begin = data;
	size = uncompress(data, &uncompressed);
	return (0);
	close(fd);
	free(begin);
	name = malloc(sizeof(19));
	strcpy(name, "file_uncompressed");
	fd = open(name, O_CREAT | O_WRONLY, 0644);
	while (size-- && fd >= 0)
		write(fd, uncompressed++, 1);
	close(fd);
	return (0);
}
