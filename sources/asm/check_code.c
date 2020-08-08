/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:06:49 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 21:11:57 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_label(t_parser *parser, unsigned int i)
{
	t_label	*label;
	unsigned int j;
	char *content;

	if (!(content = ft_strsub(parser->tokens[i]->content,
				0, ft_strlen(parser->tokens[i]->content - 1))))
		terminate(parser, ERR_MEMORY, "check_label");
	if (!(label = find_label(parser->labels, content)))
		add_label(parser, init_label(parser, &content));
}

/*
static void		check_operator(t_parser *parser, t_token **current)
{
	t_op	*op;
	int8_t	types_code;

	if ((op = get_op((*current)->content)))
	{
		parser->code[parser->pos++] = op->code;
		(*current) = (*current)->next;
		if (op->args_types_code)
			parser->pos++;
		types_code = process_args(parser, current, op);
		if (op->args_types_code)
			parser->code[parser->op_pos + 1] = types_code;
	}
	else
		operator_error((*current));
}
*/

void	check_code(t_parser *parser, unsigned int i)
{
	while (i <= parser->array_info[TOKENS][ARRAY_SIZE])
	{
		parser->op_pos = parser->pos;
		if (parser->tokens[i]->type == LABEL)
		{
			check_label(parser, i);
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
/*		if (parser->tokens[i]->type == OPERATOR)
			process_operator(parser, current);
*/		if (parser->tokens[i]->type  == NEW_LINE)
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		else
			token_error(parser, parser->tokens[i]);
	}
}
