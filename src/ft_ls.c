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

void	ft_ls(char **av, char *name)
{
	t_ls				*ls;
	ls = (t_ls*)ft_memalloc(sizeof(t_ls));
	get_opts(ls, av);
	print_ls(ls, name, -1);
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
	ft_ls(av, name);
	return (0);
}
