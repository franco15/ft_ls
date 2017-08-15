/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:24:50 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/05 19:24:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	timesort(void *p1, void *p2)
{
	long	i;
	long	j;

	i = ((t_data*)p1)->t.tv_sec - ((t_data*)p2)->t.tv_sec;
	if (!i)
	{
		j = ((t_data*)p1)->t.tv_nsec - ((t_data*)p2)->t.tv_nsec;
		if (!j)
			return (ft_strcmp(((t_data*)p2)->file, ((t_data*)p1)->file));
		return (j);
	}
	return (i);
}

static int	normal_sort(void *p1, void *p2)
{
	return (ft_strcmp(((t_data*)p1)->file, ((t_data*)p2)->file));
}

void		sort_ls(t_ls *ls, void **file)
{
	int	i;

	i = ft_arrlen(file);
	if (ls->o && ls->opts.f)
		return ;
	if (ls->o && (ls->opts.t || ls->opts.u || ls->opts.uu || ls->opts.c))
	{
		get_times(ls, file);
		ft_quicksort(file, 0, i - 1, timesort);
		ft_arrrev(file);
	}
	else
		ft_quicksort(file, 0, i - 1, normal_sort);
	if (ls->o && ls->opts.r)
		ft_arrrev(file);
}
