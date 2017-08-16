/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:27:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/03 23:27:44 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2 && (ret = (char*)ft_memalloc(sizeof(char) *
		((ft_strlen(s1) + ft_strlen(s2)) + 1))))
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			ret[i++] = s2[j++];
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

void	ft_strdel(char **as)
{
	if (as)
		ft_memdel((void**)as);
}
