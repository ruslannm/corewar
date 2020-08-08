/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:07:21 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 10:12:32 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*join_str(t_parser *parser, char **str1, char **str2)
{
	char *ret;

	if (!(ret = ft_strjoin(*str1, *str2)))
		terminate(parser, ERR_MEMORY, "join_str");
	ft_strdel(str1);
	ft_strdel(str2);
	return (ret);
}

char	*get_str(t_parser *parser, const char *row, unsigned start)
{
	char	*str;

	if (!(str = ft_strsub(row, start, parser->column - start)))
		terminate(parser, ERR_MEMORY, "get_str");
	return (str);
}
