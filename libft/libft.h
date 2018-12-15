/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:37:22 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/09 20:09:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <wchar.h>
# include <stdarg.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);

char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
																	size_t len);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_atoi(const char *str);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
**	string functions
*/

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);

char			**ft_strsplit(char const *s, char c);

char			*ft_strtrim(char const *s);

char			*ft_itoa(int n);

/*
**	write functions
*/

void			ft_putchar(char c);
void			ft_putnchar(char c, int times);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);
void			ft_putnchar_fd(char c, int times, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	list functions
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstcat(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstiteri(t_list *lst,
									void (*f)(unsigned int i, t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstmapi(t_list *lst,
									t_list *(*f)(unsigned int i, t_list *elem));

size_t			ft_lstlen(t_list *lst);

t_list			*ft_strsplit_lst(char const *s, char c);

/*
**	get_next_line
*/

# define GNL_BUF_SIZE	32

typedef struct	s_flist
{
	int				fd;
	char			buf[GNL_BUF_SIZE];
	int				start;
	int				end;
	struct s_flist	*next;
}				t_flist;

int				get_next_line(const int fd, char **line);

/*
**	math functions
*/

int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				ft_abs(int a);

/*
**	floating point functions
*/

typedef union	u_long_double
{
	long double	f;
	struct		s_i
	{
		uintmax_t		m;
		unsigned short	e;
	}			i;
}				t_long_double;

long double		ft_floor_l(long double num);

/*
**	unicode functions
*/

int				ft_utf8_len(wchar_t wc);

/*
**	parsing functions
*/

int				ft_parse_number(const char **a_str);

/*
**	ft_printf
*/

# define PF_FLAGS		"#0- +\'"
# define PF_MODIFIERS	"hljzL"
# define PF_CONVERSIONS	"cspdibBouxXf%"

typedef enum	e_modifier
{
	MOD_NONE = 0,
	MOD_HH,
	MOD_H,
	MOD_L,
	MOD_LL,
	MOD_J,
	MOD_Z,
	MOD_L_CAPITAL
}				t_modifier;

typedef struct	s_fmt
{
	int			width;
	int			prec;
	unsigned	alt: 1;
	unsigned	zero: 1;
	unsigned	left: 1;
	unsigned	blank: 1;
	unsigned	plus: 1;
	unsigned	group: 1;
	t_modifier	mod;
	char		conv;
}				t_fmt;

# define PF_PREC_NONE 	(-1)

# define PF_RESET		"\e[0m"
# define PF_RED			"\e[31m"
# define PF_GREEN		"\e[32m"
# define PF_YELLOW		"\e[33m"
# define PF_BLUE		"\e[34m"
# define PF_MAGENTA		"\e[35m"
# define PF_CYAN		"\e[36m"

# define PF_BUF_SIZE 	1024

char			g_pf_buf[PF_BUF_SIZE + 1];

# define PF_BUF_START	g_pf_buf
# define PF_BUF_END		(g_pf_buf + PF_BUF_SIZE)

char			*pf_itoa(const t_fmt *f, uintmax_t num);
char			*pf_wctomb(wchar_t wc);
char			*pf_entier_to_string(long double ent);
char			*pf_frac_to_string(long double frac, int prec);

int				pf_count_zeroes(const t_fmt *f, int n_prefix, int n_digits);

int				pf_print_alpha(const t_fmt *f, va_list ap);
int				pf_print_signed(const t_fmt *f, intmax_t num);
int				pf_print_unsigned(const t_fmt *f, uintmax_t num);
int				pf_print_pointer(const t_fmt *f, void *ptr);
int				pf_print_float(const t_fmt *f, long double num);

void			pf_parse_format(t_fmt *a_fmt, const char **a_str, va_list ap);
int				ft_printf(const char *format, ...);

#endif
