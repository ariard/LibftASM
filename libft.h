#ifndef LIBFT_H
# define LIBFT_H

# define GREEN	"\x1b[32m"
# define RED	"\x1b[0m"
# define RESET	"\x1b[31m"

void 	ft_bzero(void *s, size_t n);

size_t	ft_strlen(char *s);

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_toupper(int c);

int	ft_tolower(int c);

int 	ft_test(int c);

int	ft_memcpy(void *dst, void *src, size_t n);

int 	ft_memset(void *b, int c, size_t len);

char	*ft_strdup2(char *a);

void	ft_cat(int fd);

char	*ft_strcat(char *s1, char *s2); 

#endif
