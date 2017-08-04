/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 21:36:19 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 21:36:20 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *s)
{
	ft_miniprintf("%s\n", s);
	exit(1);
}

void		print_ls(char *s)
{
	(void)s;
}

int	get_dir_info(char *name, t_ls *ls)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return (printf("ded @ tryin to open\n"));
	// printf("get_dir_info\n");
	i = count_files(name);
	ls->ar = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	ls->ar[i] = 0;
	i = 0;
	while ((sd = readdir(dir)) != NULL)
		ls->ar[i++] = ft_strdup(sd->d_name);
	closedir(dir);
	return (0);
}

void	ft_ls(int ac, char **av, char *name)
{
	t_ls		*ls;
	static char	*path;

	// printf("fT_ls\n");
	!path ? (path = ft_newpath(name)) : ft_pathjoint(path, name, ft_strlen(name));
	// printf("path: %s\n", path);
	ls = (t_ls*)ft_memalloc(sizeof(t_ls));
	if (ac == 1)
		get_dir_info(name, ls);
	else
	{
		set_opts(ls, av);
		// printf("opts kewl\n");
		parse(av, ls);
	}
}

int		main(int ac, char **av)
{
	char	*name;
	int		i;

	name = 0;
	if (ac == 1)
		name = ".";
	else if (ac > 1)
	{
		i = is_there_a_dir_or_file_in_av(av);
		i == 0 ? (name = ft_strdup(".")) : (name = ft_strdup(av[i]));
	}
	// printf("name: %s\n", name);
	ft_ls(ac, av, name);
	return (0);
}
