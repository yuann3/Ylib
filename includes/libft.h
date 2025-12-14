/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/18 18:42:23 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 13:39:11 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/* Linked List */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Vector (Dynamic array)*/
typedef struct s_vec
{
	void			*data;
	size_t			len;
	size_t			cap;
	size_t			elem_size;
}					t_vec;

/* Vector functions */
t_vec   *ft_vec_new(size_t elem_size, size_t init_cap);
int     ft_vec_push(t_vec *vec, const void *elem);
int     ft_vec_pop(t_vec *vec, void *out);
void    *ft_vec_get(t_vec *vec, size_t index);
int     ft_vec_set(t_vec *vec, size_t index, const void *elem);
void    ft_vec_free(t_vec *vec);
void    ft_vec_clear(t_vec *vec);
int     ft_vec_reserve(t_vec *vec, size_t new_cap);


/* Character checking functions */
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/* String functions */
size_t				ft_strlen(const char *s);

/* Memory manipulation functions */
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

/* String copy/concatenate functions */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Character conversion functions */
int					ft_toupper(int c);
int					ft_tolower(int c);

/* String search functions */
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/* Conversion functions */
int					ft_atoi(const char *str);

/* Memory allocation functions */
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);

/* String manipulation functions */
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);

/* String iteration functions */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* File descriptor output functions */
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* Linked list functions */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* Printf functions */
int					ft_printf(const char *format, ...);
int					ft_print_char(int character);
int					ft_print_str(char *str);
int					ft_print_ptr(void *ptr);
int					ft_print_nbr(int number);
int					ft_print_unsigned(unsigned int number);
int					ft_print_hex(unsigned int n, int uppercase);

#endif
