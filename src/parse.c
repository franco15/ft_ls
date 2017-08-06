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

static int		get_dir_info(char *name, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return (printf("ded @ tryin to open\n"));
	// printf("get_dir_info\n");
	i = count_files(name);
	ls->ar = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	ls->ar[i] = 0;
	i = 0;
	while ((sd = readdir(dir)) != NULL)
		ls->ar[i++] = ft_strdup(sd->d_name);
	closedir(dir);
	return (0);
}

void		parse_ls(int ac, char **av, t_ls *ls, char *name)
{
	// int		i;
	(void)ls;

	printf("parse\n");
	// i = skipopts(av);
	if (ac > 1)
		set_opts(ls, av);
	get_dir_info(name, ls);
	// printf("path: %s\n", ls->path);
	// printf("opt: %d\n", ls->opt);
	// i = -1;
	// while (ls->ar[++i])
		// printf("ar[%d]: %s\n", i, ls->ar[i]);
}
