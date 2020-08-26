/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:20:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:20:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*ft_memset(void *s, int c, size_t len)
{
	const unsigned char	value = c;
	unsigned char		*str;

	str = (unsigned char *)s;
	while (len)
	{
		*str = value;
		str += 1;
		len -= 1;
	}
	return (s);
}
