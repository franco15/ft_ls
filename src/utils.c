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
	// char	*tmp2;

	tmp = ft_strjoin(*p, name);
	// tmp2 = ft_strjoin(tmp, name);
	// free(tmp);
	free(*p);
	*p = tmp;
}

char	*ft_newpath(char *n)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strdup(n);
	if (!ft_strcmp(".", n))
		ret = ft_strjoin(tmp, "/");
	else
		ret = ft_strjoin("./", tmp);
	free(tmp);
	return (ret);
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
