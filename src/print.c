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
		// printf("%s\n", ls->ar[i]);
		// printf("path: %s\n", ls->path);
		ls->ptmp = ft_strdup(path);
		// printf("%s\n", t_path);
		// printf("pathjoint in recursion\n");
		// ft_miniprintf("ls->ptmp: [%s] && ls->ar[i]: [%s]\n", ls->ptmp, arr[i]);
		ft_pathjoint(&ls->ptmp, arr[i]);
		// printf("smn\n");
		// printf("t_path: [%s]\n", t_path);
		lstat(ls->ptmp, &st);
		if (S_ISDIR(st.st_mode) && !(ft_strcmp(arr[i], ".") == 0 ||
			ft_strcmp(arr[i], "..") == 0))
		{
			// printf("ssad\n");
			tmp = ft_strdup(ls->ptmp);
			free(arr[i]);
			arr[i] = tmp;
			ft_miniprintf("\n%s\n", ls->ptmp);
			print_ls(ls, arr[i], -1);
		}
		// else
		// 	printf("error: %s\n", strerror(errno));
		// free(ls->ptmp);
	}
}

void		print_ls(t_ls *ls, char *path, int i)
{
	char	**arr;

	arr = 0;
	arr = get_dir_info(arr, path, ls);
	// printf("smn\n");
	sort_ls(ls, arr);
	// get_stat(ls);
	if (ls->opt && ls->opts.l)
		l_format(ls);
	else
		ft_putarr(arr);
	if (ls->opt && ls->opts.R)
		returning_back(ls, arr, path, i);
	// free(arr);
}
