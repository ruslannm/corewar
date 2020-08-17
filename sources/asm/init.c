/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:16:41 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 11:52:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*init_token(t_parser *parser, t_type type)
{
	t_token	*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		terminate(parser, ERR_MEMORY, "init_token");
	token->content = NULL;
	token->type = type;
	token->op_pos = -1;
	token->type_code = -1;
	token->row = parser->row;
	if (type == SEPARATOR || type == ENDLINE)
		token->column = parser->column - 1;
	else
		token->column = parser->column;
	return (token);
}

t_label		*init_label(t_parser *parser, char **content,
						int op_pos, int token_index)
{
	t_label	*label;

	if (!(label = (t_label *)malloc(sizeof(t_label))))
	{
		ft_strdel(content);
		terminate(parser, ERR_MEMORY, "init_label");
	}
	label->content = *content;
	label->op_pos = op_pos;
	parser->tokens[token_index]->op_pos = op_pos;
	return (label);
}

t_link		*init_link(t_parser *parser, int token_index, size_t size)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		terminate(parser, ERR_MEMORY, "init_link");
	link->label_index = parser->array_info[LABELS][ARRAY_INDEX];
	link->token_index = token_index;
	link->pos = parser->pos;
	link->op_pos = parser->op_pos;
	link->size = size;
	return (link);
}
