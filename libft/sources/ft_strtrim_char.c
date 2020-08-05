/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:07:57 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 17:07:59 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char(const char *s, char c)
{
	size_t	left;
	size_t	right;

	if (!s)
		return (NULL);
	if (!c)
		return (ft_strdup(s));
	left = 0;
	while (c == *(s + left))
		left++;
	right = ft_strlen(s) - 1;
	while (right > left && c == *(s + right))
		right--;
	return (ft_strsub(s, left, right + 1 - left));
}
