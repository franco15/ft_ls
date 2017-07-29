 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:18:14 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 20:18:15 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include "minilibft.h"

typedef struct		s_btree
{
	void			*data;
	struct s_btree		*lc;
	struct s_btree		*rc;
}					t_btree;

/*
** ft_ls.c
*/
void	ft_error(void);
int 	main(int ac, char **av);

#endif
