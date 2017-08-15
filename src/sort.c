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

static int		timesort(void *p1, void *p2)
{
	long	i;
	long	j;

	// printf("p1: %s\np2: %s\n", ((t_data*)p1)->file, ((t_data*)p2)->file);
	// printf("p1: %s\np2: %s\n", ctime(&((t_data*)p1)->t), ctime(&((t_data*)p2)->t));
	i = ((t_data*)p1)->t.tv_sec - ((t_data*)p2)->t.tv_sec;
	// printf("p1: %ld\n", ((t_data*)p1)->t);
	// printf("p2: %ld\n", ((t_data*)p2)->t);
	// printf("i : [%ld]\n", i);
	if (!i)
	{
		j = ((t_data*)p1)->t.tv_nsec - ((t_data*)p2)->t.tv_nsec;
		// printf("j : [%ld]\n", j);
		if (!j)
			return (ft_strcmp(((t_data*)p2)->file, ((t_data*)p1)->file));
		return (j);
	}
	return (i);
}

static int		normal_sort(void *p1, void *p2)
{
	return (ft_strcmp(((t_data*)p1)->file, ((t_data*)p2)->file));
}

void		sort_ls(t_ls *ls, void **file)
{
	int	i;
	// char	**t;

	// t = 0;
	i = ft_arrlen(file);
	if (ls->opt && ls->opts.f)
		return ;
	if (ls->opt && (ls->opts.t || ls->opts.u || ls->opts.U || ls->opts.c))
	{
		get_times(ls, file);
		// printf("sort\n");
		// for (int i = 0; i < 9; i++)
		// {
		// 	printf("file %s\n", file[i]->st.file);
		// 	printf("time %ld\n", file[i]->st.t);
		// }
		// exit(1);
		ft_quicksort(file, 0, i - 1, timesort);
		// if (ls->opts.t)
		ft_arrrev(file);
	}
	else
		ft_quicksort(file, 0, i - 1, normal_sort);
	if (ls->opt && ls->opts.r)
		ft_arrrev(file);
	// int j = ft_arrlen(arr);
	//
	// i = -1;
	// while (++i < j)
	// {
	// 	printf("file: [%s] | time: [%s]\n", st[i].file, st[i].time);
	// }
}
