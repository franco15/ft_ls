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
	free(*p);
	free(tmp);
	*p = tmp2;
	// int		i;
	// int		j;
	// int		k;
	// char	*tmp;
	//
	// i = ft_strlen(name);
	// j = ft_strlen(*p);
	// k = j;
	// printf("%d\n", j);
	// printf("[%c]\n", *p[j - 1]);
	// *p[j - 1] == '/' ? --j : 0;
	// tmp = (char*)ft_memalloc(sizeof(char) * (i + j) + 2);
	// ft_strcat(tmp, *p);
	// if (k == j)
	// 	ft_strcat(tmp, "/");
	// ft_strcat(tmp, name);
	// // free(p);
	// *p = tmp;
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
