/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:53:38 by rgero             #+#    #+#             */
/*   Updated: 2020/08/05 22:56:17 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' ||	c == ' ')
		return (1);
	return (0);
}

int	is_delimiter(char c)
{
	if (c == '\0' || c == '\n' || is_whitespace(c) || c == COMMAND_CHAR
		|| c == '\"' || c == DIRECT_CHAR || c == SEPARATOR_CHAR
		|| c == COMMENT_CHAR)
		return (1);
	return (0);
}