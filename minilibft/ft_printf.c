/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:46:09 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 19:46:10 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

static void		set_color(int c)
{
	ft_putstr("\033[");
	ft_putnbr(c);
	ft_putchar('m');
}

static void		putcstr(char const *s, size_t col)
{
	set_color(col);
	ft_putstr(s);
	set_color(0);
}

/*
** ft_printfcolor("%s", "qp", 97); 97 = whito
*/

void			ft_printfcolor(const char *format, ...)
{
	va_list p;
	char	*tmp;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				putcstr(va_arg(p, char*), va_arg(p, size_t));
			else if ((*(format + 1)) == 'd')
			{
				putcstr(tmp = ft_itoa_base(va_arg(p, int), 10),
				va_arg(p, size_t));
				ft_memdel((void**)&tmp);
			}
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
}

void			ft_printf(const char *format, ...)
{
	va_list p;
	char	*str;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putstr(va_arg(p, char*));
			else if ((*(format + 1)) == 'd')
			{
				str = ft_itoa_base(va_arg(p, int), 10);
				ft_putstr(str);
				ft_memdel((void**)&str);
			}
			else if ((*(format + 1)) == 'c')
				ft_putchar(va_arg(p, int));
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
}
