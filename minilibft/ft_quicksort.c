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
#include <stdio.h>

void	ft_swap(void **s, int i, int j)
{
	void	*s3;

	s3 = s[i];
	s[i] = s[j];
	s[j] = s3;
}

void	ft_quicksort(void **s, int start, int end,
		int (comp)(void *, void *))
{
	int		i;
	int		j;
	void	*pivot;

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
			ft_swap(s, i++, j--);
	}
	ft_quicksort(s, start, j, comp);
	ft_quicksort(s, i, end, comp);
}
