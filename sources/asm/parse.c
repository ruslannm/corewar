/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:40:18 by rgero             #+#    #+#             */
/*   Updated: 2020/08/06 22:30:25 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_operator(t_parser *parser,	char *row,	unsigned int start,
		t_token *token)
{
	unsigned column;

	token->column = start;
	column = parser->column;
	while (row[parser->column]
		&&  0 == is_delimiter(row[parser->column]))
		parser->column++;
	if (!(token->content = ft_strsub(row, start, parser->column - start)))
		terminate(parser, "memory allocation in parse_operator");
	add_token(parser, token);
}

void	parse_token(t_parser *parser, char **row)
{
	if (*(*row + parser->column) == SEPARATOR_CHAR && ++parser->column)
		add_token(parser, init_token(parser, SEPARATOR));
	else if (*(*row + parser->column) == '\n' && ++parser->column)
		add_token(parser, init_token(parser, NEW_LINE));
	else if (*(*row + parser->column) == '.')
		parse_operator(parser, *row, ++parser->column,
					init_token(parser, COMMAND));
	else if (*(*row + parser->column) == '\"')
		parse_str(parser, row, parser->column, init_token(parser, STRING));
}
