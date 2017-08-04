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

void		ft_miniprintf(const char *format, ...);
void		ft_printfcolor(const char *format, ...);
size_t		ft_putstr(char const *s);
void		ft_putnbr(int nb);
size_t		ft_putchar(char c);
char		*ft_strnew(size_t size);
char		*ft_itoa_base(long long int n, int b);
size_t		ft_strlen(const char *s);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_quicksort(char **s, int start, int end);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const	char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcat(char *s1, const char *s2);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t size, size_t newsize);

#endif
