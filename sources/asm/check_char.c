/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:53:38 by rgero             #+#    #+#             */
/*   Updated: 2020/08/15 07:54:59 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			find_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int			is_delimiter(const char c)
{
	if (find_strchr(WHITESPACES, c) || c == '\0' || c == '\n' || c == '\"'
		|| c == '-' || c == COMMAND_CHAR || c == DIRECT_CHAR
		|| c == SEPARATOR_CHAR || c == COMMENT_CHAR || c == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int			is_register(const char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	if (len > 1 && len < 4 && str[i++] == REGISTER_CHAR)
	{
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0' && ft_atoi(&str[1]) > 0)
			return (1);
	}
	return (0);
}
