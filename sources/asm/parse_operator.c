/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 07:44:19 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 12:39:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_operator(t_parser *parser, char *row,	t_token *token)
{
	unsigned int start;

	start = parser->column;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start) && row[parser->column] == LABEL_CHAR)
	{
		token->content = get_str(parser, row, start);
		token->type = LABEL;
		add_token(parser, token);
		parser->column++;
	}
	else if ((parser->column - start) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		if (token->type == INDIRECT)
			token->type = (is_register(token->content)) ? REGISTER : OPERATOR;
		add_token(parser, token);
	}
	else
		lexical_error(parser);
}

void	parse_direct_label(t_parser *parser, char *row,	t_token *token)
{
	unsigned int start;

	start = parser->column;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
		lexical_error(parser);
}

void parse_indirect_label(t_parser *parser, char *row, t_token *token)
{
	unsigned int start;

	start = parser->column;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
		lexical_error(parser);
}

void	parse_direct_nbr(t_parser *parser,	char *row,	t_token *token)
{
	unsigned int	start;
	unsigned int	start_digit;

	start = parser->column;
	start_digit = parser->column;
	if (row[parser->column] == '-')
		start_digit = ++parser->column;
	while (ft_isdigit(row[parser->column]))
		parser->column++;
	if ((parser->column - start_digit)	&& is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
		lexical_error(parser);
}

void	parse_str(t_parser *parser,	char *row,	t_token *token)
{
	unsigned int start;
	unsigned int	start_digit;

	start = parser->column;
	start_digit = parser->column;
	if (row[parser->column] == '-')
		start_digit = ++parser->column;
	while (ft_isdigit(row[parser->column]))
		parser->column++;
	if ((parser->column - start_digit && is_delimiter(row[parser->column])))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
	{
		parser->column = start;
		parse_operator(parser, row, token);
	}
}
