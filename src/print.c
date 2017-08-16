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

static void	returning_back(t_ls *ls, void **file, char *path, int i)
{
	char		*tmp;
	struct stat	st;

	while (file[++i])
	{
		ls->ptmp = ft_strdup(path);
		ft_pathjoint(&ls->ptmp, ((t_data*)file[i])->file);
		lstat(ls->ptmp, &st);
		if (S_ISDIR(st.st_mode) && !(ft_strcmp(((t_data*)file[i])->file, ".")
			== 0 || ft_strcmp(((t_data*)file[i])->file, "..") == 0))
		{
			tmp = ft_strdup(ls->ptmp);
			ft_memdel((void**)&((t_data*)file[i])->file);
			((t_data*)file[i])->file = tmp;
			ft_miniprintf("\n%s\n", ls->ptmp);
			print_ls(ls, ((t_data*)file[i])->file, -1);
			ft_memdel((void**)&tmp);
			ft_memdel((void**)&ls->ptmp);
		}
	}
}

void		print_print(t_ls *ls, t_data *file)
{
	int	j;

	j = -1;
	if (ls->o && ls->opts.d)
	{
		ft_printfcolor("%s\n", ".", 36);
		return ;
	}
	if (S_ISDIR(file->st.st_mode))
		ft_printfcolor("%s\n", file->file, 36);
	else if (S_ISREG(file->st.st_mode) && ((file->st.st_mode & S_IXUSR) ||
		(file->st.st_mode & S_IXGRP) || (file->st.st_mode & S_IXOTH)))
		ft_printfcolor("%s\n", file->file, 31);
	else if (S_ISLNK(file->st.st_mode))
		ft_printfcolor("%s", file->file, 35);
	else
		ft_miniprintf("%s\n", file->file);
}

static void	ls_print(t_ls *ls, void **file)
{
	int	j;

	j = -1;
	if (ls->o && ls->opts.l)
	{
		if (ls->o && ls->opts.d)
		{
			l_format(ls, (t_data*)file[0]);
			return ;
		}
		ls->blocks > 0 ? print_blocks(ls->blocks) : 0;
		while (file[++j])
			l_format(ls, (t_data*)file[j]);
	}
	else
	{
		while (file[++j])
			print_print(ls, (t_data*)file[j]);
	}
}

// static void	file_del(void **file)
// {
// 	int		i;
// 	// void	**tmp;
//
// 	i = -1;
// 	// tmp = file;
// 	while (file[++i])
// 	{
// 		// if (((t_data*)file[i])->file)
// 			// ft_memdel((void**)&((t_data*)file[i])->file);
// 		if (((t_data*)file[i])->path)
// 			ft_memdel((void**)&((t_data*)file[i])->path);
// 	}
// 	ft_memdel(file);
// }

void		print_ls(t_ls *ls, char *path, int i)
{
	int		j;
	char	**arr;
	void	**file;

	j = -1;
	arr = 0;
	arr = get_dir_info(arr, path, ls);
	if (!arr)
		return ;
	file = ft_memalloc(sizeof(void*) * 4096);
	get_stat(ls, file, arr, path);
	while (arr[++j])
		ft_memdel((void**)&arr[j]);
	ft_memdel((void**)&arr);
	sort_ls(ls, file);
	ls_print(ls, file);
	if (ls->o && ls->opts.rr && !ls->opts.d)
		returning_back(ls, file, path, i);
	// file_del(file);
}
