/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:09:14 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 17:09:15 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_chars(const char *s, const char *chars)
{
	size_t	left;
	size_t	right;

	if (!s)
		return (NULL);
	if (!chars || !(*chars))
		return (ft_strdup(s));
	left = 0;
	while (s[left] && ft_strchr(chars, s[left]))
		left++;
	right = ft_strlen(s) - 1;
	while (right > left && ft_strchr(chars, s[right]))
		right--;
	return (ft_strsub(s, left, right + 1 - left));
}
