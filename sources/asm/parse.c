/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:40:18 by rgero             #+#    #+#             */
/*   Updated: 2020/08/15 20:55:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_token(t_parser *parser, char **row)
{
	if (*(*row + parser->column) == SEPARATOR_CHAR && ++parser->column)
		add_token(parser, init_token(parser, SEPARATOR));
	else if (*(*row + parser->column) == '\n' && ++parser->column)
		parse_endline(parser);
	else if (*(*row + parser->column) == '.')
		parse_command(parser, *row, init_token(parser, COMMAND_NAME));
	else if (*(*row + parser->column) == '\"')
		parse_command_str(parser, row, init_token(parser, STRING));
	else if (*(*row + parser->column) == DIRECT_CHAR)
	{
		if (*(*row + parser->column + 1) == LABEL_CHAR)
			parse_direct_label(parser, *row, init_token(parser, DIRECT_LABEL));
		else
			parse_direct_nbr(parser, *row, init_token(parser, DIRECT));
	}
	else if (*(*row + parser->column) == LABEL_CHAR)
		parse_indirect_label(parser, *row, init_token(parser, INDIRECT_LABEL));
	else
		parse_str(parser, *row, init_token(parser, INDIRECT));
}
