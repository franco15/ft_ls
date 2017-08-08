/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:32:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/03 23:32:43 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	skipopts(char **av)
{
	int	i;

	i = 1;
	while (av[i] && av[i][0] == '-')
		i++;
	return (i);
}

static void	ft_usage(char option)
{
	ft_miniprintf("ls: illegal option -- %c\n", option);
	ft_miniprintf("usage: ls [-ARadfglrtu] [file ...]\n");
	exit(1);
}

static int	valid_opt(char *s)
{
	int		i;
	char	*options;

	i = 0;
	options = "lRartfugdA";
	while (options[i])
		if (*s == options[i++])
			return (1);
	ft_usage(*s);
	return (0);
}

void		set_opts(t_ls *ls, char **s)
{
	int		i;
	int		j;

	i = 0;
	while (s[++i] && s[i][0] == '-')
	{
		if (!ft_strcmp("-", s[i]))
			ft_miniprintf("ls: -: No such file or directory");
		j = 0;
		ls->opt = 1;
		while (s[i][++j] && valid_opt(&s[i][j]))
		{
			if (s[i][j] == 'l' || s[i][j] == 'a')
				s[i][j] == 'l' ? (ls->opts.l = 1) : (ls->opts.a = 1);
			else if (s[i][j] == 'R' || s[i][j] == 'r')
				s[i][j] == 'R' ? (ls->opts.R = 1) : (ls->opts.r = 1);
			else if (s[i][j] == 't' || s[i][j] == 'f')
				s[i][j] == 't' ? (ls->opts.t = 1) : (ls->opts.f = 1);
			else if (s[i][j] == 'u' || s[i][j] == 'g')
				s[i][j] == 'u' ? (ls->opts.u = 1) : (ls->opts.g = 1);
			else if (s[i][j] == 'd' || s[i][j] == 'A')
				s[i][j] == 'd' ? (ls->opts.d = 1) : (ls->opts.A = 1);
		}
	}
}
