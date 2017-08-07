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

void	sort_ls(t_ls *ls)
{
	int	i;

	i = ft_arrlen(ls->ar);
	if (ls->opt && ls->opts.f)
		return ;
	// if (ls->opt && ls->opts.t)
	// 	ft_quicksort(ls->ar, 0, i - 1, ft_timesort_t_);
	// else if (ls->opt && ls->opts.u)
		// ft_quicksort(ls->ar, 0, i - 1, ft_timesort_u_);
	ft_quicksort(ls->ar, 0, i - 1, ft_strcmp);
	if (ls->opt && ls->opts.r)
		ft_arrrev(ls->ar);
	// i = 0;
	// while (ls->ar[i])
	// 	printf("%s ", ls->ar[i++]);
	// printf("\n");
}
