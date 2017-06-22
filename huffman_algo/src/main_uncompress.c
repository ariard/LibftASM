#include "compress.h"

int		uncompress(unsigned char *data, unsigned char **uncompressed)
{
	t_list		*begin;
	int			tab_frequency[(int)SIZE + 1];
	int			size;
	t_huffnode	*node;

	ft_memcpy(&size, data, sizeof(int));
	begin = NULL;
	parse_freq(data, tab_frequency);
	gen_lst_freq(&begin, tab_frequency);
	data = data + 4 + SIZE + 1;
	build_tree(&begin);
	node = begin->content;
// 	hufftree_print(node);
	*uncompressed = (unsigned char *)malloc(sizeof(unsigned char *) * size + 1);
	parse_tree(node, *uncompressed, data, size);
	return (size);
}

int		main(int argc, char **argv)
{
	unsigned char			*data;
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
	size = uncompress(data, &uncompressed);
	close(fd);
	munmap(data, buf.st_size);
	name = malloc(sizeof(19));
	ft_strcpy(name, "file_uncompressed");
	fd = open(name, O_CREAT | O_WRONLY, 0644);
	while (size-- >= 0 && fd >= 0)
		write(fd, uncompressed++, 1);
	close(fd);
	return (0);
}
