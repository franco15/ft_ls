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

void		get_stat(t_ls *ls)
{
	int			i;
	char		*t_path;
	t_list		*tmp;
	struct stat	st;

	i = ls->size_of_arr;
	while (--i >= 0)
	{
		t_path = ft_strdup(ls->path);
		ft_pathjoint(&t_path, ls->ar[i], ft_strlen(ls->ar[i]));
		lstat(t_path, &st);
		// if (S_ISDIR(st.st_mode))
		// 	printf("smn es dir: %s\n", ls->ar[i]);
		tmp = ft_lstnew(&st.st_mode, sizeof(st));
		// tmp->content = (struct stat*)ft_memalloc(sizeof(struct stat));
		// tmp->content = stat;
		ft_lstadd(&ls->stat, tmp);
		// printf("ls->stat->content address = %p\n", &ls->stat->content);
	}
	ft_strdel(&t_path);
}

static void	get_dir_info(char *name, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return ((void)ft_miniprintf("ls: name: No such file or directory\n"));
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
