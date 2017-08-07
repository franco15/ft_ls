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

static void		print_ls(t_ls *ls)
{
	int		i;

	i = 0;
	while (ls->ar[i])
		printf("%s ", ls->ar[i++]);
	printf("\n");
}

void	ft_ls(int ac, char **av, char *name)
{
	t_ls		*ls;
	static char	*path;

	!path ? (path = ft_newpath(name)) : ft_pathjoint(path, name, ft_strlen(name));
	ls = (t_ls*)ft_memalloc(sizeof(t_ls));
	ls->path = ft_strdup(path);
	parse_ls(ac, av, ls, name);
	sort_ls(ls);
	print_ls(ls);
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
	ft_ls(ac, av, name);
	return (0);
}
