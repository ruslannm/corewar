/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:21:42 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/05 19:28:34 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t result;
	size_t find;

	i = 0;
	find = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			result = i;
			find = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return (((void*)s) + i);
	if (find == 1)
		return (((void*)s) + result);
	return (NULL);
}
