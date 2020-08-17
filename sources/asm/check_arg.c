/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:28:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 14:13:25 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int8_t	get_arg_type(t_type type)
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

static void		check_num(t_parser *parser, int i, t_op_tab *op)
{
	unsigned	start;
	int32_t		nb;
	size_t		size;

	start = (parser->tokens[i]->type == DIRECT) ? 1 : 0;
	size = (parser->tokens[i]->type == DIRECT) ? op->t_dir_size : IND_SIZE;
	nb = ft_atoi32(parser->tokens[i]->content + start);
	if (size == 2)
		int32_to_int8(parser->code, parser->pos, (int16_t)nb, size);
	else
		int32_to_int8(parser->code, parser->pos, nb, size);
	parser->tokens[i]->number = nb;
	parser->pos += size;
}

static void		check_link(t_parser *parser, int i, t_op_tab *op)
{
	t_label		*label;
	char		*name;
	unsigned	start;
	size_t		size;

	start = (parser->tokens[i]->type == DIRECT_LABEL) ? 2 : 1;
	size = (parser->tokens[i]->type == DIRECT_LABEL) ? op->t_dir_size :\
			IND_SIZE;
	if (!(name = ft_strsub(parser->tokens[i]->content,\
				start, ft_strlen(parser->tokens[i]->content) - start)))
		terminate(parser, ERR_MEMORY, "check_links");
	if (-1 == find_label(parser, name))
	{
		label = init_label(parser, &name, -1, i);
		add_label(parser, label);
	}
	else
		ft_strdel(&name);
	add_link(parser, init_link(parser, i, size));
	parser->pos += size;
}

static void		check_register(t_parser *parser, int i)
{
	int32_t nb;

	nb = ft_atoi(parser->tokens[i]->content + 1);
	int32_to_int8(parser->code, parser->pos, nb, 1);
	parser->tokens[i]->number = nb;
	parser->pos += 1;
}

int8_t			check_arg(t_parser *parser, int i,
							t_op_tab *op, int arg_num)
{
	int8_t	type;

	type = get_arg_type(parser->tokens[i]->type);
	if (!(op->args_types[arg_num] & type))
		arg_type_error(parser, parser->tokens[i], arg_num, op);
	if (parser->tokens[i]->type == INDIRECT
		|| parser->tokens[i]->type == DIRECT)
		check_num(parser, i, op);
	else if (parser->tokens[i]->type == INDIRECT_LABEL
		|| parser->tokens[i]->type == DIRECT_LABEL)
		check_link(parser, i, op);
	else
		check_register(parser, i);
	return (type);
}
