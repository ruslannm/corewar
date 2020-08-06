/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:07:21 by rgero             #+#    #+#             */
/*   Updated: 2020/08/06 21:31:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*join_str(t_parser *parser, char **str1, char **str2)
{
	char *ret;

	if (!(ret = ft_strjoin(*str1, *str2)))
		terminate(parser, "memory allocation in join_str");
	ft_strdel(str1);
	ft_strdel(str2);
	return (ret);
}
