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
	int	i;
	t_list	*stat;
	mode_t	mode;

	i = 0;
	stat = ls->stat;
	while (ls->ar[i++])
	{
		// printf("stat address: %p\n", &stat->content);
		mode = (unsigned short)stat->content;
		if (S_ISDIR(mode))
		{
			printf("./%s\n", ls->ar[i++]);
			// ft_ls(1, , filename);
		}
		stat = stat->next;
	}
}

void		print_ls(t_ls *ls)
{
	get_stat(ls);
	if (ls->opt && ls->opts.l)
		l_format(ls);
	else
		ft_putarr(ls->ar);
	if (ls->opt && ls->opts.R)
		returning_back(ls);
}
