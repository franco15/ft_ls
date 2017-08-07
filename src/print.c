/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 22:34:49 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/06 22:34:51 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_l_fmt(t_ls *ls)
{
	(void)ls;
}

static void	returning_back(t_ls *ls)
{
	int		i;
	(void)	ls;

	i = 0;
	ft_miniprintf("--------RETURNING BACK 998 PUTOS AND ONE PUTOTE--------\n");
	while (i++ < 998)
		ft_miniprintf("PUTO\n");
	ft_miniprintf("PUTOTE");
}

void		print_ls(t_ls *ls)
{
	if (ls->opt && ls->opts.l)
		print_l_fmt(ls);
	else
		ft_putarr(ls->ar);
	if (ls->opt && ls->opts.R)
		returning_back(ls);
}
