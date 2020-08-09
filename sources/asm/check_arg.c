/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:28:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/09 16:06:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int8_t	get_arg_type(token_type type)
{
	if (type == DIRECT || type == DIRECT_LABEL)
		return (T_DIR);
	else if (type == INDIRECT || type == INDIRECT_LABEL)
		return (T_IND);
	else if (type == REGISTER)
		return (T_REG);
	else
		return (0);
}

static void		check_num(t_parser *parser, unsigned int i, t_op_tab *op)
{
	unsigned	start;
	size_t		size;

	start = (parser->tokens[i]->type == DIRECT) ? 1 : 0;
	size = (parser->tokens[i]->type == DIRECT) ? op->t_dir_size : IND_SIZE;
	if (size == 2)
		int32_to_int8(parser->code,	parser->pos, 
			ft_atoi32(&parser->tokens[i]->content[start], MODUL16),size);
	else
		int32_to_int8(parser->code,	parser->pos,
			ft_atoi32(&parser->tokens[i]->content[start], MODUL32), size);
	parser->pos += size;
}

static void		check_register(t_parser *parser, unsigned int i)
{
	int32_to_int8(parser->code,	parser->pos,
				(int8_t)ft_atoi(&parser->tokens[i]->content[1]), 1);
	parser->pos += 1;
}

int8_t			check_arg(t_parser *parser, unsigned int i,
							t_op_tab *op, int arg_num)
{
	int8_t	type;

	type = get_arg_type(parser->tokens[i]->type);
	if (!(op->args_types[arg_num] & type))
		arg_type_error(parser, parser->tokens[i], arg_num, op);
	if (parser->tokens[i]->type == INDIRECT
		|| parser->tokens[i]->type == DIRECT)
		check_num(parser, i, op);
/*	else if (parser->tokens[i]->type == INDIRECT_LABEL
		|| parser->tokens[i]->type == DIRECT_LABEL)
		check_links(parser, i, op);
*/
	else
		check_register(parser, i);
	return (type);
}
