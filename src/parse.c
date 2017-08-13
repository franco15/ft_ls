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

char		**get_dir_info(char **arr, char *path, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

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
	closedir(dir);
	return (arr);
}

// static char	*get_time(time_t t)
// {
// 	return (ctime(&t));
// }
/*
** c = st_ctime | u = st_atime | t = st_mtime
*/

void		make_time_arr(t_ls *ls, struct statdata *st, char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (ls->opts.t || ls->opts.u)
			st[i].t = ls->opts.t ? ft_strdup(ft_itoa_base(st[i].st.st_mtime, 10)) :
			ft_strdup(ft_itoa_base(st[i].st.st_atime, 10));
		else if (ls->opts.c || ls->opts.U)
			st[i].t = ls->opts.c ? ft_strdup(ft_itoa_base(st[i].st.st_ctime, 10)) :
			ft_strdup(ft_itoa_base(st[i].st.st_birthtime, 10));
		// ft_miniprintf("[%s] time t[i] : %s\n", arr[i], t[i]);
	}
	for (i = 0; i < 9; i++)
	{
		printf("%s\n", st[i].file);
		printf("%s\n", st[i].t);
	}
}

void		get_stat(struct statdata *st, char **arr, char *path)
{
	int			i;
	char		*p;
	// struct statdata	stat[l];

	i = -1;
	while (arr[++i])
	{
		p = ft_strdup(path);
		ft_pathjoint(&p, arr[i]);
		lstat(p, &st[i].st);
		st[i].file = ft_strdup(arr[i]);
	}
	// *st = stat;
	// i = -1;
	// while (++i < l)
	// {
	// 	// S_ISDIR(stat[i].st.st_mode) ? ft_miniprintf("%s is dir\n",
	// 	// arr[i]) : ft_miniprintf("%s is file\n", arr[i]);
	// }
}
