#define	INIT_BCK(x)	bck = init_file(x);
#define	INIT(x)		fd = init_file(x);
#define	FUNC(x)		print_and_wait(x);		
#define DO_TEST(x, y)	do_test(x, fd, bck, y);	
#define SHOW_TEST	show_test(fd);	

#include <unistd.h> 
#include <fcntl.h> 
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#include "test/test_bzero.c"

int	child_death;

void		child_is_death(int sig)
{
	child_death = 1;
}

int		init_file(char *file)
{
	int	fd;

	unlink(file);
	if ((fd = open(file, O_CREAT | O_RDWR, 0644)) < 0)
		return (-1);
	return (fd);
}

void		print_and_wait(char *current)
{	
	printf("ft_bzero under test...\n");
	sleep(1);
}

void		do_test(void (f)(), int fd, int bck, char *name)
{
	int	pid;
	int	timeout;

	child_death = 0;
	signal(SIGCHLD, &child_is_death);
	timeout = time(NULL);
	pid = fork();
	if (pid == 0)
	{
		f(fd, bck);
		exit(0);
	}
	if (pid > 0)
		while (1)
		{		
			if (timeout < time(NULL) - 5)
			{
				write(1, "timeout", 7);
				write(fd, "TIMEOUT : ", 10);
				write(fd, name, strlen(name));
				write(fd, "\n", 1);
				write(bck, "TIMEOUT : ", 10);
				write(bck, name, strlen(name));
				write(bck, "\n", 1);
				kill(pid, 9);
				break;
			}
			if (child_death)
				break;
		}
}

void		show_test(int fd)
{
	char	buffer[100];

	while (read(fd, buffer, 100))
		write(1, buffer, 100);
}

int		main(void)
{
	int	bck;
	int	fd;

	INIT_BCK(".bck")

	FUNC("ft_bzero");
	INIT(".tmp")
	DO_TEST(&bzero_hello, "bzero_hello");
	SHOW_TEST
	return (0);
}
