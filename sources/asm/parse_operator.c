/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 07:44:19 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 21:05:37 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			parse_operator(t_parser *parser, char *row,
					t_token *token, t_type type_prev)
{
	unsigned int	start;

	start = parser->column;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start) && row[parser->column] == LABEL_CHAR)
	{
		parser->column++;
		token->content = get_str(parser, row, start);
		token->type = LABEL;
		if (type_prev != ENDLINE && type_prev != LABEL)
			token_error(parser, token, row, 0);
		add_token(parser, token);
	}
	else if ((parser->column - start) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		if (token->type == INDIRECT)
			token->type = (is_register(token->content))\
			? REGISTER : INSTRUCTION;
		add_token(parser, token);
	}
	else
		lexical_error(parser, token, row);
}

void				parse_direct_label(t_parser *parser,
										char *row, t_token *token)
{
	unsigned int	start;

	start = parser->column;
	parser->column += 2;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start - 2) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
		lexical_error(parser, token, row);
}

void				parse_indirect_label(t_parser *parser,
										char *row, t_token *token)
{
	unsigned int	start;

	start = parser->column;
	if (row[parser->column] == LABEL_CHAR
	&& (parser->tokens[parser->array_info[TOKENS]
	[ARRAY_SIZE] - 1]->type == LABEL))
		lexical_error(parser, token, row);
	parser->column += 1;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - start - 1) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
		lexical_error(parser, token, row);
}

void				parse_direct_nbr(t_parser *parser,
									char *row, t_token *token)
{
	unsigned int	start;
	unsigned int	start_digit;

	start = parser->column;
	parser->column++;
	start_digit = parser->column;
	if (row[parser->column] == '-')
		start_digit = ++parser->column;
	while (ft_isdigit(row[parser->column]))
		parser->column++;
	if ((parser->column - start_digit) && is_delimiter(row[parser->column]))
	{
		token->content = get_str(parser, row, start);
		add_token(parser, token);
	}
	else
	{
		parser->column = start;
		lexical_error(parser, token, row);
	}
}

void				parse_str(t_parser *parser,
								char *row, t_token *token)
{
	unsigned int	start;
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
		parse_operator(parser, row, token,
		parser->tokens[parser->array_info[TOKENS][ARRAY_SIZE] - 1]->type);
	}
}
