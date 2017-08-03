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

void		print_ls(char *s)
{
	(void)s;
}

int	get_dir_info(char *name, t_ls *ls)
{
	(void)ls;
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(name)))
		return (printf("ded @ tryin to open\n"));
	i = count_files(dir, name);
	printf("i = %d\n", i);
	while ((sd = readdir(dir)) != NULL)
		printf("%s\n", sd->d_name);
	return (0);
}

void	preparse(t_ls *ls, int ac, char **av)
{
	if (ac == 1)
		get_dir_info(".", ls);
	else if (ac == 2)
		get_dir_info(av[1], ls);
	else
	{
		set_opts(ls, av[1]);
		ls_parse(av);
	}
}

int		main(int ac, char **av)
{
	t_ls	*ls;

	ls = (t_ls*)ft_memalloc(sizeof(t_ls));
	preparse(ls, ac, av);
	return (0);
}
