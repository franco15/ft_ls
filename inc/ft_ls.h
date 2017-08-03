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
	char		**ar;
	t_options opts;
}				t_ls;

/*
** ft_ls.c
*/
int 	main(int ac, char **av);
int	get_dir_info(char *name, t_ls *ls);
void	preparse(t_ls *ls, int ac, char **av);

/*
** utils.c
*/
int		count_files(DIR *dir, char *name);
void	ls_parse(char **av);
void	set_opts(t_ls *ls, char *s);

#endif
