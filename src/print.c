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

static void	returning_back(t_ls *ls)
{
	(void)ls;
	int			i;
	char		*t_path;
	struct stat	st;

	i = -1;
	while (ls->ar[++i])
	{
		// printf("%s\n", ls->ar[i]);
		// printf("path: %s\n", ls->path);
		t_path = ft_strdup(ls->path);
		ft_pathjoint(&t_path, ls->ar[i]);
		// printf("t_path: %s\n", t_path);
		lstat(t_path, &st);
		if (S_ISDIR(st.st_mode) && !(ft_strcmp(ls->ar[i], ".") == 0 ||
			ft_strcmp(ls->ar[i], "..") == 0))
		{
			// printf("ssad\n");
			printf("%s\n", t_path);
			ft_ls(1, &ls->ar[i], ls->ar[i]);
			printf("\n");
		}
		else
			printf("error: %s\n", strerror(errno));
		free(t_path);
	}
}

void		print_ls(t_ls *ls)
{
	// get_stat(ls);
	if (ls->opt && ls->opts.l)
		l_format(ls);
	else
		ft_putarr(ls->ar);
	if (ls->opt && ls->opts.R)
		returning_back(ls);
}
