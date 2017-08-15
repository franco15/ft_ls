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

static void	print_time_2(t_ls *ls, t_data *file)
{
	char			*t;
	time_t			epoch;
	int				dif;

	epoch = time(0);
	time_get(ls, file);
	dif = epoch - file->t2.tv_sec;
	t = ctime(&file->t2.tv_sec);
	if (dif > 15780000)
		ft_miniprintf("%c%c%c %c%c  %c%c%c%c ", t[4], t[5], t[6], t[8], t[9],
		t[20], t[21], t[22], t[23]);
	else
		ft_miniprintf("%c%c%c %c%c %c%c%c%c%c ", t[4], t[5], t[6], t[8], t[9],
		t[11], t[12], t[13], t[14], t[15]);
}

static void	print_time(t_ls *ls, t_data *file, int i)
{
	char	*t;
	time_t	epoch;
	int		dif;

	epoch = time(0);
	if (!i)
	{
		dif = epoch - file->st.st_mtime;
		t = ctime(&file->st.st_mtime);
		if (dif > 15780000)
			ft_miniprintf("%c%c%c %c%c  %c%c%c%c ", t[4], t[5], t[6], t[8],
			t[9], t[20], t[21], t[22], t[23]);
		else
			ft_miniprintf("%c%c%c %c%c %c%c%c%c%c ", t[4], t[5], t[6], t[8],
			t[9], t[11], t[12], t[13], t[14], t[15]);
	}
	else
		print_time_2(ls, file);
	//del t o no?
}

static void	print_size(t_data *file)
{
	int		i;
	int		j;
	char	*tmp;
	char	*size;

	tmp = ft_strnew(8);
	tmp[7] = '\0';
	size = ft_itoa_base(file->st.st_size, 10);
	i = ft_strlen(size);
	j = 6 - i;
	i = -1;
	while (j >= ++i)
		tmp[i] = ' ';
	ft_strcat(&tmp[i], size);
	ft_miniprintf("%s ", tmp);
	// ft_memdel((void*)&tmp);
	// ft_memdel((void*)&size);
}

static void	print_permisions(t_data *file)
{
	if (S_ISLNK(file->st.st_mode))
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

void		l_format(t_ls *ls, t_data *file)
{
	struct passwd	*p;
	struct group	*g;

	p = getpwuid(file->st.st_uid);
	g = getgrgid(file->st.st_gid);
	print_permisions(file);
	ft_miniprintf(listxattr(file->path, 0, 0, XATTR_NOFOLLOW) > 0 ? "@ " :
							"  ");
	ft_miniprintf("%d ", file->st.st_nlink);
	if (!ls->opts.g)
		ft_miniprintf("%s ", p->pw_name);
	ft_miniprintf("%s ", g->gr_name);
	print_size(file);
	time_opts(ls) == 0 ? print_time(ls, file, 0) : print_time(ls, file, 1);
	ft_miniprintf("%s", file->file);
	// if (islink)
	// 	print_link();
	ft_miniprintf("\n");
}
