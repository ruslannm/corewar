/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:10:48 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 17:10:50 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	reverse_bits_64(uint64_t bit)
{
	int			i;
	uint64_t	x;
	uint64_t	res;

	x = 1;
	i = 63;
	res = 0;
	while (i > 0)
	{
		res = res | ((bit & x) << i);
		x = x << 1;
		i -= 2;
	}
	i = 1;
	while (i < 64)
	{
		res = res | ((bit & x) >> i);
		x = x << 1;
		i += 2;
	}
	return (res);
}
