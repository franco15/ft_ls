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

void		time_get(t_ls *ls, t_data *file)
{
	if (ls->opts.u)
		file->t2 = file->st.st_atimespec;
	else if (!ls->opts.t && ls->opts.c)
		file->t2 = file->st.st_ctimespec;
	else if (ls->opts.uu)
		file->t2 = file->st.st_birthtimespec;
	else
		file->t2 = file->st.st_mtimespec;
}


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
		if ((ls->o && ((!ls->opts.a && !ls->opts.d && !ls->opts.f) &&
	!ls->opts.aa) && sd->d_name[0] == '.') || (!ls->o && sd->d_name[0] == '.'))
			continue ;
		if (ls->o && ls->opts.aa && !ls->opts.a &&
			(!ft_strcmp(sd->d_name, ".") || !ft_strcmp(sd->d_name, "..")))
			continue ;
		arr[i++] = ft_strdup(sd->d_name);
	}
	closedir(dir);
	return (arr);
}

void		get_times(t_ls *ls, void **file)
{
	int		i;

	i = -1;
	while (file[++i])
	{
		if (ls->opts.t && !ls->opts.u && !ls->opts.c && !ls->opts.uu)
			((t_data*)file[i])->t = ((t_data*)file[i])->st.st_mtimespec;
		else if (ls->opts.t && ls->opts.u)
			((t_data*)file[i])->t = ((t_data*)file[i])->st.st_atimespec;
		else if (ls->opts.t && ls->opts.c)
			((t_data*)file[i])->t = ((t_data*)file[i])->st.st_ctimespec;
		else if (ls->opts.t && ls->opts.uu)
			((t_data*)file[i])->t = ((t_data*)file[i])->st.st_birthtimespec;
	}
}

void		get_stat(t_ls *ls, void **file, char **arr, char *path)
{
	int		i;
	char	*p;
	t_data	*st;

	st = 0;
	i = -1;
	ls->blocks = 0;
	while (arr[++i])
	{
		st = (t_data*)ft_memalloc(sizeof(t_data));
		file[i] = st;
		p = ft_strdup(path);
		ft_pathjoint(&p, arr[i]);
		((t_data*)file[i])->path = ft_strdup(p);
		lstat(p, &((t_data*)file[i])->st);
		((t_data*)file[i])->file = ft_strdup(arr[i]);
		ls->blocks += ((t_data*)file[i])->st.st_blocks;
		ft_memdel((void**)&p);
	}
	file[i] = 0;
}
