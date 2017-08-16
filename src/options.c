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

static void	ft_usage(char option)
{
	ft_printf("ls: illegal option -- %c\n", option);
	ft_printf("usage: ls [-ARUacdfglrtu] [file ...]\n");
	exit(1);
}

static int	valid_opt(char *s)
{
	int		i;
	char	*options;

	i = 0;
	options = "lRartfugdAUc";
	while (options[i])
		if (*s == options[i++])
			return (1);
	ft_usage(*s);
	return (0);
}

static void	more_opts(t_ls *ls, char **s, int i, int j)
{
	while (s[i][j] && valid_opt(&s[i][j]))
	{
		if (s[i][j] == 'd')
			ls->opts.d = 1;
		else if (s[i][j] == 'A')
			ls->opts.aa = 1;
		else if (s[i][j] == 'U' || s[i][j] == 'c')
			ls->opts.uu = 1;
		else if (s[i][j] == 'c')
			ls->opts.c = 1;
		else if (s[i][j] == 'f')
			ls->opts.f = 1;
		else if (s[i][j] == 'u')
			ls->opts.u = 1;
		else if (s[i][j] == 't')
			ls->opts.t = 1;
		else if (s[i][j] == 'g')
		{
			ls->opts.l = 1;
			ls->opts.g = 1;
		}
		j++;
	}
}

void		get_opts(t_ls *ls, char **s)
{
	int		i;
	int		j;

	i = 0;
	while (s[++i] && s[i][0] == '-')
	{
		if (!ft_strcmp("-", s[i]))
			ft_printf("ls: -: No such file or directory\n");
		j = 0;
		ls->o = 1;
		while (s[i][++j] && valid_opt(&s[i][j]))
		{
			if (s[i][j] == 'l')
				ls->opts.l = 1;
			else if (s[i][j] == 'a')
				ls->opts.a = 1;
			else if (s[i][j] == 'R')
				ls->opts.rr = 1;
			else if (s[i][j] == 'r')
				ls->opts.r = 1;
			else
				more_opts(ls, s, i, j);
		}
	}
}
