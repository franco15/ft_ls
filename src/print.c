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

static void	returning_back(t_ls *ls, char **arr, char *path, int i)
{
	char		*tmp;
	struct stat	st;

	while (arr[++i])
	{
		ls->ptmp = ft_strdup(path);
		ft_pathjoint(&ls->ptmp, arr[i]);
		// printf("path in recursion [%s]\n", ls->ptmp);
		lstat(ls->ptmp, &st);
		if (S_ISDIR(st.st_mode) && !(ft_strcmp(arr[i], ".") == 0 ||
			ft_strcmp(arr[i], "..") == 0))
		{
			tmp = ft_strdup(ls->ptmp);
			free(arr[i]);
			arr[i] = tmp;
			ft_miniprintf("\n%s\n", ls->ptmp);
			print_ls(ls, arr[i], -1);
		}
		// else
		// 	printf("error: %s\n", strerror(errno));
	}
}

void		print_ls(t_ls *ls, char *path, int i)
{
	char		**arr;
	struct statdata	st[4096];

	// st = 0;
	arr = 0;
	arr = get_dir_info(arr, path, ls);
	get_stat(st, arr, path);
	sort_ls(ls, st, arr);
	if (ls->opt && ls->opts.l)
		l_format(ls, st, arr);
	else
		ft_putarr(arr);
	if (ls->opt && ls->opts.R)
		returning_back(ls, arr, path, i);
	free(arr);
	// st_del();
}
