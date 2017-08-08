/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 22:34:22 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 22:34:23 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((p = malloc(size)))
	{
		while (i < size)
			p[i++] = '\0';
		return (p);
	}
	return (0);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len-- > 0)
		*s++ = c;
	return (b);
}

void	*ft_realloc(void **ptr, size_t size, size_t newsize)
{
	void	*new;

	if (*ptr && newsize && size)
	{
		new = ft_memalloc(newsize);
		new = ft_memcpy(new, *ptr, size);
		free(*ptr);
	}
	else
		new = ft_memalloc(newsize);
	return (new);
}
