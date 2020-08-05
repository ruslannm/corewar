/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:21:23 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/06 19:31:38 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t len2;

	i = 0;
	len = ft_strlen(dst);
	if (len > size)
		len = size;
	len2 = len;
	if (size > 1)
	{
		while (src[i] != '\0' && len < size - 1)
		{
			dst[len] = src[i];
			i++;
			len++;
		}
		while (len < size)
		{
			dst[len] = '\0';
			i++;
			len++;
		}
	}
	return (len2 + ft_strlen(src));
}
