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
