/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:22:00 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 16:25:16 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		if (haystack[h] == needle[n])
		{
			n++;
			if (needle[n] == '\0')
				return ((char*)haystack + h - n + 1);
			h++;
		}
		else
		{
			h = h - n + 1;
			n = 0;
		}
	}
	return (NULL);
}
