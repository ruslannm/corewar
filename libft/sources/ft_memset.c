/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:48:20 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 20:32:38 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*set;

	i = 0;
	set = (unsigned char*)b;
	while (i < len)
	{
		set[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
