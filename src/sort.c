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

/*
** c f t u v S U X
*/

static void	sort_stat(t_st *st, char **arr)
{
	(void)st;
	(void)arr;
}

// int			timesort(const char *s1, const char *s2)
// {
//
// }

void		sort_ls(t_ls *ls, t_st *st, char **arr)
{
	int	i;
	char	**t;

	t = 0;
	i = ft_arrlen(arr);
	if (ls->opt && ls->opts.f)
		return ;
	if (ls->opt && (ls->opts.t || ls->opts.u || ls->opts.U || ls->opts.c))
	{
		make_time_arr(ls, st, t, arr);
		// ft_quicksort_t(ls->ar, 0, i - 1, timesort);
		sort_stat(st, arr);
	}
	else
		ft_quicksort(arr, 0, i - 1, ft_strcmp);
	if (ls->opt && ls->opts.r)
		ft_arrrev(arr);
}
