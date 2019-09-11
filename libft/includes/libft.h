/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:30:24 by jrameau           #+#    #+#             */
/*   Updated: 2019/04/15 19:10:18 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# define BUFF_SIZE 1
# define MALLCHECK(x) if (!x) return (-1);
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(long long int n);
int					ft_atoi(const char *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src,
						int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

# ifndef IS_SPACE
#  define IS_SPACE(x) (x==' '||x=='\n'||x=='\t')
# endif

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Bonus functions
*/

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Extra functions
*/

void				ft_swap(int *a, int *b);
int					ft_sqrt(int nb);
int					ft_numlen(int n);
void				ft_free_arr(char ***array);
void				ft_foreach(int *tab, int length, void (*f)(int));
long long int		ft_power(long long int nb, int pow);
void				ft_del(void *content, size_t content_size);
char				*floatoa(long double num, unsigned int precision);
char				*ft_strrew(char *src);
char				*ft_u_itoa(unsigned long long int n);
char				*itoa_base(long long int num, int base);
char				*u_itoa_base(unsigned short num, int base);
int					is_whitespace(char c);
char				*ft_strcdup(const char *s, char c);
char				*ft_strwhile(const char *s, int c);
void				ft_lstdelast(t_list **alst);
void				ft_lstpush(t_list **alst, t_list *new);
void				ft_lstfree(void *list, size_t a);

int					get_next_line(const int fd, char **line);

/*
** ft_printf
*/

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define B_RED "\x1b[31;1m"
# define B_GREEN "\x1b[32;1m"
# define B_YELLOW "\x1b[33;1m"
# define B_BLUE "\x1b[34;1m"
# define B_MAGENTA "\x1b[35;1m"
# define B_CYAN "\x1b[36;1m"
# define B_WHITE "\x1b[37;1m"
# define EOC "\x1b[0m"

typedef struct		s_orgi
{
	int				len;
	char			h;
	char			hh;
	char			l;
	char			ll;
	char			bigl;
	char			dot;
	unsigned int	precision;
	unsigned int	width;
	char			sharp;
	char			minus;
	char			zero;
	char			plus;
	char			space;
	char			type;
}					t_orgi;

int					ft_printf(const char *format, ...);
int					parse_this(va_list var, t_orgi *params);
char				*s_type(char *str, t_orgi *params);
char				*c_type(char c, t_orgi *params);
char				*d_type(va_list var, t_orgi *params);
char				*o_type(va_list var, t_orgi *params);
char				*u_type(t_orgi *params, va_list var);
char				*x_type(va_list var, t_orgi *params);
char				*p_type(va_list var, t_orgi *params);
char				*f_type(va_list var, t_orgi *params);
char				*paste_start(char *str, char c);
void				get_modifier(const char *format, int nargs, t_orgi *params);
void				get_width(const char *format, int nargs, t_orgi *params);
void				null_all(t_orgi *params);
char				*percent_manages(t_orgi *params);
char				*implement_width(char *str, int width, t_orgi *params);
char				*implement_precision(char *str, t_orgi *params);
char				*implement_sign(char *str,
					long long int nb, t_orgi *params);
char				*check_on_plus(long long int nb, t_orgi *params);

#endif
