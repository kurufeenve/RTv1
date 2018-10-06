/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:26:37 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 19:10:59 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	double			length;

}					t_vector;

char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memmove(void *dest, void const *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
size_t				ft_strlen(char const *s);
char				*ft_strdup(char const *s);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2,
	size_t n);
size_t				ft_strlcat(char *dst, char const *src,
	size_t size);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strstr(char const *haystack, char const *needle);
char				*ft_strnstr(char const *haystack, char const *needle,
	size_t len);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t len);
int					ft_atoi(char const *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					**ft_arrtozero(int **arr, size_t j);
int					**ft_newarrtozero(size_t i, size_t j);
void				ft_printarr(int **arr, size_t j);
char				*ft_realloc(char *str, size_t size);
void				ft_memkill(char **res, int i);
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_isnumber(char *str);
int					ft_chararrdel(char **arr, char ***adr);
char				*ft_itoa_base(int n, int base);
long long			ft_qpow(int n, int p);
void				ft_vector_length(t_vector *v);
void				ft_vec_add(t_vector v1, t_vector v2, t_vector *res);
void				ft_vec_sub(t_vector v1, t_vector v2, t_vector *res);
void				ft_int_arr(int ***arr, int x, int y);
size_t				**ft_size_t_arr(int x, int y);
char				*ft_strrev(char *str);
char				*ft_strjoin2(char *s1, char *s2);
void				ft_delwhitesp(char **str);
int					ft_strfind(char *haystack, char needle);
int					ft_strnfind(char *haystack, char needle, size_t n);
int					ft_indexof(char const *h, char const *n, size_t start,
	int f);
char				*ft_strnsub(char const *s, size_t start, size_t end);
int					ft_atoi_base(char const *str, int base);

#endif
