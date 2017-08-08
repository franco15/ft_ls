/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 22:03:10 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/06 22:03:12 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"
#include "stdio.h"

size_t		ft_arrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_arrrev(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = ft_arrlen(s) - 1;
	ft_putarr(s);
	while (i < j)
		ft_swap(&s[i++], &s[j--]);
}

void	ft_putarr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_miniprintf("%s ", s[i++]);
	ft_miniprintf("\n");
}
