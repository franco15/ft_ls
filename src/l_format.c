/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:19:55 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/07 19:19:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_size(t_ls *ls, t_data *file)
{
	(void)ls;
	(void)file;
}

static void	print_permisions(t_ls *ls, t_data *file)
{
	(void)ls;
	(void)file;
}

static void	print_blocks(t_ls *ls, t_data *file)
{
	(void)ls;
	(void)file;
}

void		l_format(t_ls *ls, t_data *file)
{
	struct passwd	*p;
	struct group	*g;

	p = getpwuid(file->st.st_uid);
	g = getgrgid(file->st.st_gid);
	print_blocks(ls, file);
	print_permisions(ls, file);
	ft_miniprintf(listxattr(file->path, 0, 0 /* , XATTR_NOFOLLOW */ ) > 0 ? "@ " : "  ");
	ft_miniprintf("%d ", file->st.st_nlink);
	if (!ls->opts.g)
		ft_miniprintf("%s ", p->pw_name);
	ft_miniprintf("%s ", g->gr_name);
	print_size(ls, file);
	//print time;
	ft_miniprintf("%s\n", file->file);
}
