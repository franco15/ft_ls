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

int		print_ls(char *s)
{

}

void	get_dir_info(char *name)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return (printf("ded @ tryin to open\n"));
	i = count_files(dir, name);
}

void	preparse(int ac, char **av)
{
	if (ac == 1)
		get_dir_info(".");
	else if (ac == 2)
		get_dir_info(av[1]);
	else
	{
		get_opts(av[1]);
		ls_parse(av);
	}
}

int		main(int ac, char **av)
{
	preparse(ac, av);
	return (0);
}
