/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:26:50 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/16 21:51:07 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countelements(const char *s, char c)
{
	size_t elements;
	size_t i;

	if (s == NULL || c == 0)
		return (0);
	elements = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
		{
			elements++;
		}
		i++;
	}
	if (s[0] != '\0')
		elements++;
	return (elements);
}

static char	*ft_element(const char *s, char c, size_t *i)
{
	char	*str;
	size_t	k;

	if (s == NULL || c == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	k = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i] != '\0')
		*i += 1;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	elements;
	char	**str;

	if (s == NULL || c == 0)
		return (NULL);
	i = 0;
	j = 0;
	elements = ft_countelements(s, c);
	str = (char **)malloc(sizeof(char*) * (elements + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (s[i] == c && s[i] != '\0')
		i++;
	while (j < elements && s[i] != '\0')
	{
		str[j] = ft_element(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
