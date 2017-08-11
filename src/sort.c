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

void	sort_ls(t_ls *ls, char **arr)
{
	int	i;

	i = ft_arrlen(arr);
	if (ls->opt && ls->opts.f)
		return ;
	if (ls->opt && (ls->opts.t || ls->opts.u))
	{
		// get_time(ls, arr);
		// ls->opts.t ? ft_quicksort(ls->ar, 0, i - 1, ft_timesort_t_) :
		// ft_quicksort(ls->ar, 0, i - 1, ft_timesort_u_);
	}
	ft_quicksort(arr, 0, i - 1, ft_strcmp);
	if (ls->opt && ls->opts.r)
		ft_arrrev(arr);
}
