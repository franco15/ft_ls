/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:31:32 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/03 23:31:33 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_dir_info(char *name, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return ((void)ft_miniprintf("ls: %s: No such file or directory\n", name));
	i = count_files(name);
	ls->ar = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	ls->ar[i] = 0;
	i = 0;
	while ((sd = readdir(dir)) != NULL)
	{
		if ((ls->opt && (!ls->opts.a && !ls->opts.A) && sd->d_name[0] == '.') ||
			(!ls->opt && sd->d_name[0] == '.'))
			continue ;
		if (ls->opt && ls->opts.A && !ls->opts.a && (!ft_strcmp(sd->d_name, ".")
			|| !ft_strcmp(sd->d_name, "..")))
			continue ;
		ls->ar[i++] = ft_strdup(sd->d_name);
	}
	ls->size_of_arr = ft_arrlen(ls->ar);
	closedir(dir);
}

void		parse_ls(int ac, char **av, t_ls *ls, char *name)
{
	(void)ls;
	static t_options	*options;

	if (ac > 1)
	{
		if (!options)
		{
			set_opts(ls, av);
			options = &ls->opts;
		}
		else
			ls->opts = *options;
	}
	get_dir_info(name, ls);
}
