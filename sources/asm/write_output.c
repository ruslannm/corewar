/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:22 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 20:56:02 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_op_content(t_parser *parser, int i,
									int current, int op_len)
{
	int			j;
	int			k;

	ft_printf("%-5d(%-3d) :%8c", current, op_len, ' ');
	ft_printf("%-10s", parser->tokens[i]->content);
	j = 1;
	k = 0;
	while (j <= parser->tokens[i]->op_tab->args_num + k)
	{
		if (parser->tokens[i + j]->type == SEPARATOR)
			k++;
		else
			ft_printf("%-18s", parser->tokens[i + j]->content);
		j++;
	}
	ft_printf("\n");
}

static void		print_int32(int32_t value, size_t size)
{
	uint32_t	i;
	uint8_t		tmp;

	tmp = 1;
	i = 0xFF;
	while (tmp < size)
	{
		i = i << 8;
		tmp++;
	}
	while (tmp)
	{
		ft_printf("%-4u", (uint8_t)((value & i) >> ((tmp - 1) * 8)));
		i = i >> 8;
		tmp--;
	}
	tmp = size;
	while (4 - tmp)
	{
		ft_printf("    ");
		tmp++;
	}
	ft_printf("  ");
}

static void		print_op_number_bit(t_parser *parser, int i)
{
	int			j;
	int			k;
	int			type_code;

	ft_printf("%20c", ' ');
	type_code = parser->tokens[i]->type_code;
	if (parser->tokens[i]->type_code < 0)
		type_code = 256 + parser->tokens[i]->type_code;
	if (parser->tokens[i]->op_tab->args_types_code)
		ft_printf("%-4d%-6d", parser->tokens[i]->op_tab->code, type_code);
	else
		ft_printf("%-4d      ", parser->tokens[i]->op_tab->code);
	j = 1;
	k = 0;
	while (j <= parser->tokens[i]->op_tab->args_num + k)
	{
		if (parser->tokens[i + j]->type == SEPARATOR)
			k++;
		else
			print_int32(parser->tokens[i + j]->number,
			parser->tokens[i]->arg_len[j - 1 - k]);
		j++;
	}
	ft_printf("\n");
}

static void		print_op_number(t_parser *parser, int i)
{
	int			j;
	int			k;
	int			type_code;

	ft_printf("%20c", ' ');
	type_code = parser->tokens[i]->type_code;
	if (parser->tokens[i]->type_code < 0)
		type_code = 256 + parser->tokens[i]->type_code;
	if (parser->tokens[i]->op_tab->args_types_code)
		ft_printf("%-4d%-6d", parser->tokens[i]->op_tab->code, type_code);
	else
		ft_printf("%-4d      ", parser->tokens[i]->op_tab->code);
	j = 1;
	k = 0;
	while (j <= parser->tokens[i]->op_tab->args_num + k)
	{
		if (parser->tokens[i + j]->type == SEPARATOR)
			k++;
		else
			ft_printf("%-18d", parser->tokens[i + j]->number);
		j++;
	}
	ft_printf("\n\n");
}

void			write_standart_output(t_parser *parser)
{
	int			i;
	int			current;
	int			op_len;
	t_token		*token;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", parser->pos);
	ft_printf("Name : \"%s\"\n", parser->name);
	ft_printf("Comment : \"%s\"\n\n", parser->comment);
	current = 0;
	i = -1;
	while (++i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		token = parser->tokens[i];
		if (token->type == LABEL)
			ft_printf("%-5d      :    %s\n", current, token->content);
		else if (parser->tokens[i]->type == INSTRUCTION)
		{
			op_len = get_types_len(token, token->type_code >> 2);
			print_op_content(parser, i, current, op_len);
			print_op_number_bit(parser, i);
			print_op_number(parser, i);
			current += op_len;
		}
	}
}
