/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 22:30:18 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/28 22:30:19 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

static int	ft_digitnum(long long int n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char		*ft_itoa_base(long long int n, int b)
{
	char			*num;
	size_t			size;
	int				neg;
	long long int	mod;

	neg = 0;
	size = ft_digitnum(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}
