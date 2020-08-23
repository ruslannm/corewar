/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:07:21 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 15:24:45 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*join_str(t_parser *parser, char **str1, char **str2)
{
	char	*ret;

	if (!(ret = ft_strjoin(*str1, *str2)))
	{
		ft_strdel(str1);
		ft_strdel(str2);
		terminate(parser, ERR_MEMORY, "join_str");
	}
	ft_strdel(str1);
	ft_strdel(str2);
	return (ret);
}

char		*get_str(t_parser *parser, const char *row, unsigned start)
{
	char	*str;

	if (!(str = ft_strsub(row, start, parser->column - start)))
		terminate(parser, ERR_MEMORY, "get_str");
	return (str);
}

int8_t		get_types_len(t_token *token, int8_t type_code)
{
	int		i;
	int8_t	ret;
	int8_t	tmp;

	if (token->op_tab->args_types_code == 0)
	{
		token->arg_len[0] = token->op_tab->t_dir_size;
		return (1 + token->op_tab->t_dir_size);
	}
	ret = 2;
	i = -1;
	while (++i < 3)
	{
		tmp = 0;
		if ((type_code & IND_CODE) == IND_CODE)
			tmp = 2;
		else if ((type_code & REG_CODE) == REG_CODE)
			tmp = 1;
		else if ((type_code & DIR_CODE) == DIR_CODE)
			tmp = token->op_tab->t_dir_size;
		token->arg_len[2 - i] = tmp;
		ret += tmp;
		type_code = type_code >> 2;
	}
	return (ret);
}
