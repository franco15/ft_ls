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

static void	returning_back(t_ls *ls)
{
	(void)ls;
	// int	i;
	//
	// i = 0;
	// while (files)
	// {
	// 	if (isdir(file))
	// 	{
	// 		printf("filename");
	// 		ft_ls(ac,av, filename);
	// 	}
	// }
}

void		print_ls(t_ls *ls)
{
	if (ls->opt && ls->opts.l)
		l_format(ls);
	else
		ft_putarr(ls->ar);
	if (ls->opt && ls->opts.R)
		returning_back(ls);
}
