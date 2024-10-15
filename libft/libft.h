/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:19 by nino              #+#    #+#             */
/*   Updated: 2024/10/15 14:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define SIZE_MAX (18446744073709551615UL)

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define RST "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define WHITE "\033[0;37m"

// ? Garbage DBL flags for single or double pointers
# define SINGLE 0
# define DOUBLE 1

typedef struct s_garbage
{
	int					*garbage_freed;
	int					dbl;
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_list
{
	char				*key_env;
	void				*content;
	int					exp;
	int					interro;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

// check
int						ft_isalnum(int c);
int						ft_isalnum_string(char *s);
int						ft_isalpha(int c);
int						ft_isalpha_string(char *s);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(char c);
int						ft_iterate_double(char **s, int (*f)(char **, int,
								int));
int						ft_iterate(char *s, int (*f)(char *, int));

// gnl
# define BUFFER_SIZE 42

char					*return_gnl(int fd);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strchr(const char *s, int i);
char					*ft_strdup(const char *s);
int						ft_strlength(const char *str);
char					*ft_strjoin_gnl(char const *s1, char const *s2);
char					*get_next_line(int fd, int flag);

// list
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list					*ft_lstnew(void *content);
int						ft_lstsize(t_list *lst);

// memory
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_free(char **s);
void					ft_free_tab(void **s);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);

// miscellaneous
int						ft_tolower(int c);
int						ft_toupper(int c);

// print
int						ft_printf(const char *txt, ...);
int						ft_printchar(char c);
int						ft_printstr(char *str);
int						ft_printnbr(int n);
int						ft_printptr(unsigned long long n);
int						ft_print_unsigned_nb(unsigned int n);
int						ft_printhex(unsigned int n, char format);

// put
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_double(char **s);
void					ft_putstr_fd(char *s, int fd);
void					ft_putstr(char *s);

// string
int						ft_atoi(const char *nptr);
long					ft_atol(char *nptr);
char					*ft_char_trim(char *s, char quote);
int						ft_count_chars(char *s, char *chars);
char					*ft_cut_chars(char *s, char *cut);
char					*ft_itoa(long n);
int						ft_linelen(char **s);
char					**ft_split(char const *s, char c);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(char *s1, char *s2);
char					**ft_strdup_double(char **s);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
int						ft_strlen_double(char **s);
int						ft_strlen(const char *s);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_stRSTr(char *s1, char *s2);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strrchr(const char *s, int c);
char					*ft_strtrim(char const *s, char const *set);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char *s1, char *s2, int f);
char					*ft_strndup(const char *s, int n);

#endif
