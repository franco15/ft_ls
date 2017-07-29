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

#endif
