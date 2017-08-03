/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 21:19:04 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/02 21:19:05 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parse(char **av)
{
	(void)av;
}

void	set_opts(t_ls *ls, char *s)
{
	(void)ls;
	(void)s;
}

int		count_files(DIR *dir, char *name)
{
	int i;
	struct dirent *sd;

	while ((sd = readdir(dir)) != NULL)
		i++;
	closedir(dir);
	dir = opendir(name);
	return (i);
}
