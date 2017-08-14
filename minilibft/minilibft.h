/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:53:45 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 19:53:46 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

/*
** array.c
*/
void	ft_arrrev(void **s);
void	ft_putarr(char **s);
size_t	ft_arrlen(void **s);

/*
** conv.c
*/
char	*ft_itoa_base(long long int n, int b);

/*
** ft_printf.c
*/
void	ft_miniprintf(const char *format, ...);
void	ft_printfcolor(const char *format, ...);

/*
** ft_quicksort.c
*/
void	ft_quicksort(void **s, int start, int end,
		int (*comp)(void *, void *));
void	ft_swap(void **s, int i, int j);

/*
** lst.c
*/
void	ft_lstaddback(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*bzero)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lst_add_at_last(t_list **last, t_list *new);
t_list	*ft_lstnew(void const *content, size_t size);
void	ft_lstadd(t_list **alst, t_list *new);

/*
** mem.c
*/
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_realloc(void **ptr, size_t size, size_t newsize);

/*
** mem2.c
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** put.c
*/
void	ft_putnbr(int nb);
size_t	ft_putchar(char c);
size_t	ft_putstr(char const *s);

/*
** strings.c
*/
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const	char *src);
size_t	ft_strlen(const char *s);

/*
** string2.c
*/
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strdel(char **as);

#endif
