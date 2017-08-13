 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:18:14 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 20:18:15 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minilibft.h"

typedef struct	s_options
{
	int			l;
	int			R;
	int			r;
	int			A;
	int			a;
	int			t;
	int			f;
	int			u;
	int			g;
	int			d;
	int			c;
	int			U;
}				t_options;

struct			statdata
{
	char		*file;
	long		t;
	struct stat	st;
};

typedef struct	s_ls
{
	int			opt;
	char		*ptmp;
	t_options	opts;
}				t_ls;

/*
** ft_ls.c
*/
int		main(int ac, char **av);
void	ft_ls(char **av, char *name);

/*
** utils.c
*/
int		count_files(char *name);
void	ft_pathjoint(char **p, char *name);
int		is_there_a_dir_or_file_in_av(char **av);

/*
** options.c
*/
void	get_opts(t_ls *ls, char **s);
// int		skipopts(char **av);

/*
** parse.c
*/
void	get_times(t_ls *ls, struct statdata *st, char **arr);
void	get_stat(t_ls *ls,struct statdata *st, char **arr, char *path);
char	**get_dir_info(char **arr, char *name, t_ls *ls);

/*
** sort.c
*/
void	sort_ls(t_ls *ls, struct statdata *st, char **arr);

/*
** print.c
*/
void	print_ls(t_ls *ls, char *name, int i);

/*
** l_format.c
*/
void	l_format(t_ls *ls, struct statdata *st, char **ar);

#endif
