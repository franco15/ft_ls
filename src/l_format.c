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

static void	print_size(t_data *file)
{
	int		i;
	int		j;
	char	*tmp;
	char	*size;

	tmp = ft_strnew(9);
	tmp[8] = '\0';
	size = ft_itoa_base(file->st.st_size, 10);
	i = ft_strlen(size);
	j = 7 - i;
	i = -1;
	while (j >= ++i)
		tmp[i] = ' ';
	ft_strcat(&tmp[i], size);
	ft_miniprintf("%s ", tmp);
	ft_memdel((void*)&tmp);
	ft_memdel((void*)&size);
}

static void	print_permisions(t_data *file)
{
	if  (S_ISLNK(file->st.st_mode))
		ft_miniprintf("l");
	else
		ft_miniprintf((S_ISDIR(file->st.st_mode)) ? "d" : "-");
	ft_miniprintf((file->st.st_mode & S_IRUSR) ? "r" : "-");
	ft_miniprintf((file->st.st_mode & S_IWUSR) ? "w" : "-");
	ft_miniprintf((file->st.st_mode & S_IXUSR) ? "x" : "-");
	ft_miniprintf((file->st.st_mode & S_IRGRP) ? "r" : "-");
	ft_miniprintf((file->st.st_mode & S_IWGRP) ? "w" : "-");
	ft_miniprintf((file->st.st_mode & S_IXGRP) ? "x" : "-");
	ft_miniprintf((file->st.st_mode & S_IROTH) ? "r" : "-");
	ft_miniprintf((file->st.st_mode & S_IWOTH) ? "w" : "-");
	ft_miniprintf((file->st.st_mode & S_IXOTH) ? "x" : "-");
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
	print_permisions(file);
	ft_miniprintf(listxattr(file->path, 0, 0 /* , XATTR_NOFOLLOW */ ) > 0 ? "@ " : "  ");
	ft_miniprintf("%d ", file->st.st_nlink);
	if (!ls->opts.g)
		ft_miniprintf("%s ", p->pw_name);
	ft_miniprintf("%s ", g->gr_name);
	print_size(file);
	//print time;
	ft_miniprintf("%s\n", file->file);
	// print_size(file);
	// printf("\n");
}
