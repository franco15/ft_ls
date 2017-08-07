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

static void	remove_dot_files(t_ls *ls)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ls->ar[i])
		if (ls->ar[i++][0] == '.')
			j++;
	ls->p = (char**)ft_memalloc(sizeof(char*) * (i - j) + 1);
	ls->p[i - j] = 0;
	i = 0;
	j = 0;
	while (ls->ar[j])
	{
		if (ls->ar[j][0] != '.')
			ls->p[i++] = ft_strdup(ls->ar[j]);
		j++;
	}
}

// static void	opt_R(t_ls *ls)
// {
// 	int	i;
//
// 	i = 0;
// 	ls->opt && ls->opts.a ? ft_putarr(ls->ar) : ft_putarr(ls->p);
// 	while(ls->)
// }

void		print_ls(t_ls *ls)
{
	int		i;

	i = 0;
	remove_dot_files(ls);
	if (ls->opt && ls->opts.a)
		ft_putarr(ls->ar);
	else
		ft_putarr(ls->p);
	printf("\n");
}
