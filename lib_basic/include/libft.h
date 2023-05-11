/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:40:55 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:24:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

# include "color.h"
# include "typedef.h"
# include "fmt.h"

// ctype
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// string
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strrchr(const char *str, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// lib
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int i);
void	ft_bzero(void *s, size_t n);

// I/O
void	ft_putstr_fd(char *str, int filedes);
void	ft_putnbr_fd(int nb, int filedes);
void	ft_putendl_fd(char *str, int filedes);
void	ft_putchar_fd(char c, int fildes);
char	*gnl(int fd, char sep);
size_t  ft_wc_lines(char *path);
size_t  ft_wc_words(char *path);
size_t  ft_wc_bytes(char *path);
char    *ft_getfile(char *path);
//char  *get_file
//char  *get_next_line
// printf
int     ft_printf(const char *str_f, ...);
int     ft_vaprintf(const char *str_f, va_list va);
int     ft_switch_conversion(const char **str_f, va_list va, t_format *fmt);
int     ft_uint_conversion(t_format *fmt, va_list va);
int     ft_sint_conversion(t_format *fmt, va_list va);
int     ft_char_conversion(t_format *fmt, char a);
int     ft_str_conversion(t_format *fmt, const char *str);
int     ft_double_conversion(void );
int     ft_lluitoa(unsigned long long int num, t_format *fmt);

// list
t_list	*ft_lstnew(void *data); //  creator
t_list	*ft_lstgetb(t_list *lst); //  getters
int		ft_lstsize(t_list *lst);
void	ft_lstaddf(t_list **lst, t_list *new); //  method: add
void	ft_lstaddb(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));//  method: cleaners
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *)); //  method: iterators
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// dlist
t_dlist	*ft_dlstnew(void *data); //  creator
t_dlist	*ft_dlstgeth(t_dlist *lst); //  getters
t_dlist	*ft_dlstgetb(t_dlist *lst);
void    ft_dlstaddb(t_dlist **lst, t_dlist *new); //  method: add
void    ft_dlstaddf(t_dlist **lst, t_dlist *new);
void    ft_dlstaddib(t_dlist *lst, t_dlist *new);
void    ft_dlstaddia(t_dlist *lst, t_dlist *new);
//void  ft_dlstclear //  method: cleners
//void  ft_dlstdelone
//void	ft_dlstiter//  method: iterators
//void	ft_dlstmap

// queue
// t_queue *ft_queuenew(void *data); // creator
// ft_queueen
// ft__queuede

// stack

//tree

#endif
