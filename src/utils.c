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

int		count_files(char *name)
{
	int i;
	DIR *dir;
	struct dirent *sd;

	i = 0;
	dir = opendir(name);
	while ((sd = readdir(dir)) != NULL)
		i++;
	closedir(dir);
	return (i);
}

void	ft_pathjoint(char **p, char *name)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(*p, "/");
	tmp2 = ft_strjoin(tmp, name);
	ft_strdel(&*p);
	ft_strdel(&tmp);
	*p = tmp2;
}

int		is_there_a_dir_or_file_in_av(char **av)
{
	int	i;

	i = 1;
	while (av[i] && av[i] && (av[i][0] == '-'))
			i++;
	if (av[i] && av[i][0] != '-')
		return (i);
	return (0);
}

int		time_opts(t_ls *ls)
{
	if (!ls->opts.t && !ls->opts.u && !ls->opts.c && !ls->opts.U)
		return (0);
	return (1);
}
