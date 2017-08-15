/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 21:36:19 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 21:36:20 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void		print_link()

static void	ls_del_opts(t_ls *ls)
{
	ls->opts.l = 0;
	ls->opts.rr = 0;
	ls->opts.r = 0;
	ls->opts.aa = 0;
	ls->opts.a = 0;
	ls->opts.t = 0;
	ls->opts.f = 0;
	ls->opts.u = 0;
	ls->opts.g = 0;
	ls->opts.d = 0;
	ls->opts.c = 0;
	ls->opts.uu = 0;
}

static void	ls_del(t_ls **ls)
{
	t_ls *tmp;

	tmp = *ls;
	tmp->o = 0;
	tmp->blocks = 0;
	ft_memdel((void**)&tmp->ptmp);
	ls_del_opts(tmp);
	ft_memdel((void**)&tmp);
}

void		ft_ls(char **av, char *name)
{
	t_ls	*ls;

	ls = (t_ls*)ft_memalloc(sizeof(t_ls));
	get_opts(ls, av);
	print_ls(ls, name, -1);
	ls_del(&ls);
}

int			main(int ac, char **av)
{
	char	*name;
	int		i;

	name = 0;
	if (ac == 1)
		name = ft_strdup(".");
	else if (ac > 1)
	{
		i = is_there_a_dir_or_file_in_av(av);
		name = i == 0 ? ft_strdup(".") : ft_strdup(av[i]);
	}
	ft_ls(av, name);
	ft_memdel((void**)&name);
	return (0);
}
