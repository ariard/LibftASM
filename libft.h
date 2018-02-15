#ifndef LIBFT_H
# define LIBFT_H

# define GREEN	"\x1b[32m"
# define RESET	"\x1b[0"
# define RED	"\x1b[31m"

void 	ft_bzero(void *s, size_t n);

size_t	ft_strlen(char *s);

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_toupper(int c);

int	ft_tolower(int c);

int	ft_isprint(int c);

int	ft_isascii(int c);


void	*ft_memcpy(void *dst, void *src, size_t n);

int 	ft_memset(void *b, int c, size_t len);

int		ft_puts(const char *s);	

char	*ft_strdup(char *a);

//int		ft_strdup(char *a, char *b, size_t size);

void	ft_fuck(int fd);

void	ft_cat(int fd);


char	*ft_strcat(char *s1, char *s2); 

#endif
