/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 21:36:19 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 21:36:20 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(void)
{
	ft_miniprintf("%s", "ded");
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_error();
	return (0);
}
