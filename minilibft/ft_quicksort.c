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

void	ft_quicksort(char **s, int start, int end,
		int (comp)(const char *, const char *))
{
	int		i;
	int		j;
	char	*pivot;

	if (start >= end)
		return ;
	i = start;
	j = end;
	pivot = s[(start + end) / 2];
	while (i <= j)
	{
		while (comp(s[i], pivot) < 0)
			i++;
		while (comp(s[j], pivot) > 0)
			j--;
		if (i <= j)
			ft_swap(&s[i++], &s[j--]);
	}
	ft_quicksort(s, start, j, comp);
	ft_quicksort(s, i, end, comp);
}
