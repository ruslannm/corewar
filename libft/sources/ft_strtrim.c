/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:26:42 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 22:39:44 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			&& start <= end && s[end] != '\0')
		end--;
	new = ft_strnew(end - start + 1);
	if (new == NULL)
		return (NULL);
	while (s[start] != '\0' && start <= end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
