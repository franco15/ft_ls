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
		// printf("path in recursion [%s]\n", ls->ptmp);
		lstat(ls->ptmp, &st);
		if (S_ISDIR(st.st_mode) && !(ft_strcmp(((t_data*)file[i])->file, ".") == 0 ||
			ft_strcmp(((t_data*)file[i])->file, "..") == 0))
		{
			tmp = ft_strdup(ls->ptmp);
			ft_strdel(&((t_data*)file[i])->file);
			((t_data*)file[i])->file = tmp;
			ft_miniprintf("\n%s\n", ls->ptmp);
			print_ls(ls, ((t_data*)file[i])->file, -1);
		}
		// else
		// 	printf("error: %s\n", strerror(errno));
	}
}

void		print_ls(t_ls *ls, char *path, int i)
{
	char	**arr;
	void	**file;
	int		j;

	j = -1;
	arr = 0;
	arr = get_dir_info(arr, path, ls);
	file = ft_memalloc(sizeof(t_data*) * 4096);
	get_stat(ls, file, arr, path);
	ft_memdel((void**)arr);
	// for (int i = 0; i < 9; i++)
	// {
	// 	printf("file %s\n", st[i].file);
	// 	printf("time %ld\n", st[i].t);
	// }
	sort_ls(ls, file);
	// while (++j < (int)ft_arrlen((void**)arr))
	// {
	// 	printf("file: %s\n", ((t_data*)file[j])->file);
	// 	printf("file: %ld\n", ((t_data*)file[j])->t);
	// }
	if (ls->opt && ls->opts.l)
		while (file[++j])
			l_format(ls, (t_data*)file[j]);
	else
		while (file[++j])
			ft_miniprintf("%s\n", ((t_data*)file[j])->file);
	if (ls->opt && ls->opts.R)
		returning_back(ls, file, path, i);
	// file_del();
}
