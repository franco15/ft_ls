/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 22:30:50 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 22:30:50 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(size + 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if ((dup = ft_strnew(ft_strlen(s1))))
		return (ft_strcpy(dup, s1));
	return (0);
}

char	*ft_strcpy(char *dst, const	char *src)
{
	char *p;

	p = dst;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dst);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
