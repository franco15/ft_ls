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
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include "minilibft.h"

typedef struct		s_options
{
	int				l;
	int				rr;
	int				r;
	int				aa;
	int				a;
	int				t;
	int				f;
	int				u;
	int				g;
	int				d;
	int				c;
	int				uu;
}					t_options;

typedef struct		s_data
{
	struct timespec t;
	struct timespec t2;
	char			*file;
	char			*path;
	struct stat		st;
}					t_data;

typedef struct		s_ls
{
	int				o;
	long long		blocks;
	char			*ptmp;
	t_options		opts;
}					t_ls;

/*
** ft_ls.c
*/
int					main(int ac, char **av);
void				ft_ls(char **av, char *name);
void				print_link(char *path);

/*
** utils.c
*/
int					time_opts(t_ls *ls);
int					count_files(char *name);
int					is_there_a_dir_or_file_in_av(char **av);
void				print_blocks(long long blocks);
void				ft_pathjoint(char **p, char *name);

/*
** options.c
*/
void				get_opts(t_ls *ls, char **s);

/*
** parse.c
*/
void				get_times(t_ls *ls, void **file);
void				get_stat(t_ls *ls, void **file, char **arr, char *path);
char				**get_dir_info(char **arr, char *name, t_ls *ls);
void				time_get(t_ls *ls, t_data *file);

/*
** sort.c
*/
void				sort_ls(t_ls *ls, void **file);

/*
** print.c
*/
void				print_ls(t_ls *ls, char *name, int i);

/*
** l_format.c
*/
void				l_format(t_ls *ls, t_data *file);

#endif
