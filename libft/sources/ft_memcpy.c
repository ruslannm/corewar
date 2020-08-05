/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:48:44 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/12 12:12:37 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
