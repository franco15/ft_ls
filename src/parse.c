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

char	**get_dir_info(char **arr, char *path, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	// printf("path: %s\n", path);
	if (!(dir = opendir(path)))
	{
		ft_miniprintf("ls: %s: %s\n", path, strerror(errno));
		return (0);
	}
	i = count_files(path);
	arr = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	arr[i] = 0;
	i = 0;
	while ((sd = readdir(dir)) != NULL)
	{
		if ((ls->opt && (!ls->opts.a && !ls->opts.A) && sd->d_name[0] == '.') ||
			(!ls->opt && sd->d_name[0] == '.'))
			continue ;
		if (ls->opt && ls->opts.A && !ls->opts.a && (!ft_strcmp(sd->d_name, ".")
			|| !ft_strcmp(sd->d_name, "..")))
			continue ;
		arr[i++] = ft_strdup(sd->d_name);
	}
	// ls->size_of_arr = ft_arrlen(arr);
	closedir(dir);
	return (arr);
}

// void		parse_ls(char **av, t_ls *ls, char *name)
// {
// 	(void)av;
// 	// (void)ls;
// 	// static t_options	*options;
// 	//
// 	// if (ac > 1)
// 	// {
// 	// 	if (!options)
// 	// 	{
// 	// 		set_opts(ls, av);
// 	// 		options = &ls->opts;
// 	// 	}
// 	// 	else
// 	// 		ls->opts = *options;
// 	// }
// 	get_dir_info(name, ls);
// }
