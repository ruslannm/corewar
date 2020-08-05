/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:06:15 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 17:06:16 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = (char *)s;
	while (*tmp++)
	{
		if (len < maxlen)
			len++;
		else
			break ;
	}
	return (len);
}
