/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:21:52 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 16:26:38 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t h;
	size_t n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[h] != '\0')
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
