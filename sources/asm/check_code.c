/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:06:49 by rgero             #+#    #+#             */
/*   Updated: 2020/08/09 21:34:04 by rgero            ###   ########.fr       */
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

static int8_t	check_args(t_parser *parser, int i, t_op_tab *op)
{
	int		arg_num;
	int8_t	types_code;
	int8_t	type;

	arg_num = 0;
	types_code = 0;
	while (arg_num < op->args_num)
	{
		if (parser->tokens[i]->type >= REGISTER && parser->tokens[i]->type <= INDIRECT_LABEL)
		{
			type = check_arg(parser, i, op, arg_num);
			types_code |= (get_arg_code(type) << 2 * (4 - arg_num - 1));
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
		else
			token_error(parser, parser->tokens[i]);
		if (arg_num++ != op->args_num - 1)
		{
			if (parser->tokens[i]->type != SEPARATOR)
				token_error(parser, parser->tokens[i]);
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
	}
	return (types_code);
}

static void		check_label(t_parser *parser, int i)
{
	char *content;

	if (!(content = ft_strsub(parser->tokens[i]->content,
				0, ft_strlen(parser->tokens[i]->content) - 1)))
		terminate(parser, ERR_MEMORY, "check_label");
	if (-1 == find_label(parser, content))
		add_label(parser, init_label(parser, &content, parser->op_pos));
}

static void		check_operator(t_parser *parser, int i)
{
	t_op_tab *op;
	int8_t	types_code;

	if ((op = find_op(parser, parser->tokens[i]->content)))
	{
		parser->code[parser->pos++] = op->code;
		parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		if (op->args_types_code)
			parser->pos++;
		types_code = check_args(parser, i, op);
		if (op->args_types_code)
			parser->code[parser->op_pos + 1] = types_code;
	}
	else
	{
		if (i < parser->array_info[TOKENS][ARRAY_SIZE]
			&& parser->tokens[i + 1]->type == NEW_LINE)
			token_error(parser, parser->tokens[i + 1]);
		else
			instruction_error(parser, parser->tokens[i]);
	}
}

void	check_code(t_parser *parser, int i)
{
	while (i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		parser->op_pos = parser->pos;
		if (parser->tokens[i]->type == LABEL)
		{
			check_label(parser, i);
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		}
		if (parser->tokens[i]->type == OPERATOR)
		{
			check_operator(parser, i);
			i = parser->array_info[TOKENS][ARRAY_INDEX];
		}
		if (parser->tokens[i]->type  == NEW_LINE)
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		else
			token_error(parser, parser->tokens[i]);
	}
}
