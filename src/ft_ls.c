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

void	ft_error(void)
{
	ft_miniprintf("ded");
}

void	current(void)
{

}

int main(int ac, char **av)
{
	DIR *dir;
	struct dirent *sd;

	dir = 0;
	if (ac == 1)
	{
		if (!(dir = opendir(".")))
		{
			ft_miniprintf("didnt open directory\n");
			exit(1);
		}
		ft_miniprintf("si lo abrio\n");
	}
	else if (ac == 2)
	{
		if (!(dir = opendir(av[1])))
		{
			ft_miniprintf("didnt open directory\n");
			exit(1);
		}
		ft_miniprintf("si lo abrio\n");
	}
	while ((sd = readdir(dir)) != NULL)
	{
		ft_miniprintf("%s\t", sd->d_name);
	}
	ft_miniprintf("\n");
	closedir(dir);
	return (0);
}
