#ifndef LIBFT_H
# define LIBFT_H

# define GREEN	"\x1b[32m"
# define RESET	"\x1b[0"
# define RED	"\x1b[31m"


void		ft_bzero(void *s, size_t n);

size_t		ft_strlen(const char *s);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_isprint(int c);

int		ft_isascii(int c);

void		*ft_memcpy(void *restrict dst, const void *src, size_t n);

void	 	*ft_memset(void *b, int c, size_t len);

int		ft_puts(const char *s);	

char		*ft_strdup(const char *a);

void		ft_cat(int fd);

char		*ft_strcat(char *restrict s1, const char *restrict s2); 

int		ft_strcmp(const char *s1, const char *s2);

char		*ft_strjoin(const char *s1, const char *s2);
 
char		*ft_strstr(const char *s1, const char *s2);

char		*ft_strchr(const char *s1, int c);

char 		*ft_strrev(char *s1);

#endif
