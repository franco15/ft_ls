/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:24:50 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/05 19:24:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** c f t u v S U X
*/

static void	sort_stat(struct statdata *st, char **arr)
{
	(void)st;
	(void)arr;
}

static int			timesort(void *p1, void *p2)
{
	int				i;
	int				j;
	struct statdata	*a;
	struct statdata	*b;

	a = (struct statdata*)p1;
	b = (struct statdata*)p2;
	printf("a.file: %s\n", a->file);
	printf("a.time: %ld\n", a->t);
	printf("b.file: %s\n", b->file);
	printf("b.time: %ld\n", b->t);
	i = a->t - b->t;
	printf("i : [%d]\n", i);
	if (!i)
	{
		j = ft_strcmp(a->file, b->file);
		printf("smn\n");
		if (j != 0)
			return (j);
	}
	return (i);
}

static int		normal_sort(void *p1, void *p2)
{
	return (ft_strcmp(p1, p2));
}

void		sort_ls(t_ls *ls, struct statdata *st, char **arr)
{
	int	i;
	char	**t;

	t = 0;
	i = ft_arrlen(arr);
	if (ls->opt && ls->opts.f)
		return ;
	if (ls->opt && (ls->opts.t || ls->opts.u || ls->opts.U || ls->opts.c))
	{
		get_times(ls, st, arr);
		printf("sort\n");
		for (int i = 0; i < 9; i++)
		{
			printf("file %s\n", st[i].file);
			printf("time %ld\n", st[i].t);
		}
		// exit(1);
		ft_quicksort((void**)&st, 0, i - 1, timesort);
		sort_stat(st, arr);
	}
	else
		ft_quicksort((void**)arr, 0, i - 1, normal_sort);
	if (ls->opt && ls->opts.r)
		ft_arrrev(arr);
	// int j = ft_arrlen(arr);
	//
	// i = -1;
	// while (++i < j)
	// {
	// 	printf("file: [%s] | time: [%s]\n", st[i].file, st[i].time);
	// }
}
