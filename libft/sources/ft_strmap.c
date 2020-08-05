/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:25:40 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 18:55:38 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	map = ft_strnew(ft_strlen(s));
	if (map == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
