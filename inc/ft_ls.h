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
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minilibft.h"

typedef struct	s_options
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
	int			f;
	int			u;
	int			g;
	int			d;
}				t_options;

typedef struct	s_ls
{
	int			opt;
	char		*path;
	char		**ar;
	char		**p;
	struct stat	stat;
	t_options opts;
}				t_ls;

/*
** ft_ls.c
*/
int		main(int ac, char **av);
void	ft_ls(int ac, char **av, char *name);
void	ft_error(char *s);

/*
** utils.c
*/
int		count_files(char *name);
void	ft_pathjoint(char *p, char *n, int nlen);
char	*ft_newpath(char *n);
int		is_there_a_dir_or_file_in_av(char **av);

/*
** options.c
*/
void	set_opts(t_ls *ls, char **s);
int		skipopts(char **av);

/*
** parse.c
*/
void	parse_ls(int ac,char **av, t_ls *ls, char *name);
// int		get_dir_info(char *name, t_ls *ls);

/*
** sort.c
*/
void	sort_ls(t_ls *ls);

/*
** print.c
*/
void	print_ls(t_ls *ls);

#endif
