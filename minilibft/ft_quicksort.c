/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:33:21 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/02 20:33:26 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_swap(char **s1, char **s2)
{
	char	*s3;

	s3 = *s1;
	*s1 = *s2;
	*s2 = s3;
}

int		partition(char **s, int start, int end, int (*comp)(char *, char *))
{
	int		i;
	int		pi;
	char	*pivot;

	i = 0;
	pi = start;
	pivot = ar[end];
	while (i < (end - start))
	{
		if (comp(s[i], pivot))
			ft_swap(&s[i], &ar[pi++]);
	}
	ft_swap(&ar[pi], ar[end]);
	return (pi);
}

void	ft_quicksort(char **s, int start, int end, int (*comp)(char *, char *))
{
	int	pi;

	if (start >= end)
		return ;
	pi = partition(&s, start, end, comp);
}
