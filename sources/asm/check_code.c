/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:06:49 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 21:13:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint8_t	get_arg_code(int8_t type)
{
	if (type == T_DIR)
		return (DIR_CODE);
	else if (type == T_REG)
		return (REG_CODE);
	else
		return (IND_CODE);
}

static int8_t	check_args(t_parser *parser, int i, t_op_tab *op, int arg_num)
{
	int8_t		types_code;
	int8_t		type;

	types_code = 0;
	while (arg_num < op->args_num)
	{
		if (parser->tokens[i]->type >= REGISTER
			&& parser->tokens[i]->type <= INDIRECT_LABEL)
		{
			type = check_arg(parser, i, op, arg_num);
			types_code |= (get_arg_code(type) << 2 * (4 - arg_num - 1));
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
		else
			token_error(parser, parser->tokens[i], 0, i);
		if (arg_num++ != op->args_num - 1)
		{
			if (parser->tokens[i]->type != SEPARATOR)
				token_error(parser, parser->tokens[i], NULL, i);
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
	}
	check_args_error(parser, i, arg_num, op);
	return (types_code);
}

static void		check_label(t_parser *parser, int i)
{
	char		*content;
	int			label_index;

	if (!(content = ft_strsub(parser->tokens[i]->content,
				0, ft_strlen(parser->tokens[i]->content) - 1)))
		terminate(parser, ERR_MEMORY, "check_label");
	label_index = find_label(parser, content);
	if (-1 == label_index)
		add_label(parser, init_label(parser, &content, parser->op_pos, i));
	else if (-1 == parser->labels[label_index]->op_pos)
	{
		parser->labels[label_index]->op_pos = parser->op_pos;
		parser->tokens[i]->op_pos = parser->op_pos;
		ft_strdel(&content);
	}
}

static void		check_operator(t_parser *parser, int i)
{
	t_op_tab	*op;
	int8_t		types_code;

	if ((op = find_op(parser->tokens[i]->content)))
	{
		parser->code[parser->pos++] = op->code;
		parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		if (op->args_types_code)
			parser->pos++;
		types_code = check_args(parser, i, op, 0);
		if (op->args_types_code)
			parser->code[parser->op_pos + 1] = types_code;
		parser->tokens[i - 1]->op_pos = parser->op_pos;
		parser->tokens[i - 1]->type_code = types_code;
		parser->tokens[i - 1]->op_tab = op;
	}
	else
	{
		if (i < parser->array_info[TOKENS][ARRAY_SIZE]
			&& parser->tokens[i + 1]->type == ENDLINE)
			token_error(parser, parser->tokens[i + 1], NULL, i + 1);
		else
			instruction_error(parser, parser->tokens[i]);
	}
}

void			check_code(t_parser *parser, int i)
{
	while (i < parser->array_info[TOKENS][ARRAY_SIZE] - 1)
	{
		parser->array_info[CODE][ARRAY_SIZE] = parser->pos;
		add_code_capacity(parser);
		parser->op_pos = parser->pos;
		if (parser->tokens[i]->type == LABEL)
		{
			check_label(parser, i);
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
		if (parser->tokens[i]->type == INSTRUCTION)
		{
			parser->having_ins = 1;
			check_operator(parser, i);
			i = parser->array_info[TOKENS][ARRAY_INDEX];
		}
		if (parser->tokens[i]->type == ENDLINE)
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		else
			token_error(parser, parser->tokens[i], NULL, i);
	}
	if (parser->tokens[i]->type == END && parser->having_ins != 1)
		token_error(parser, parser->tokens[i], NULL, i);
	replace_link(parser);
}
