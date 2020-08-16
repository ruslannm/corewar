/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:22 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 17:35:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	int32_to_int8(char *str,
							int32_t pos,
							int32_t value,
							size_t size)
{
	uint8_t	i;

	if (1 == size)
		value =	(int8_t)(value);
	else if (2 == size)
		value =	(int16_t)(value);
	i = 0;
	while (size)
	{
		str[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void		write_file(int fd, t_parser *parser)
{
	unsigned int	len;
	unsigned int	pos;
	char			*bytecode;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + parser->pos;
	if (!(bytecode = ft_strnew((size_t)len)))
		terminate(parser, ERR_MEMORY, "write_file");
	int32_to_int8(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->name, ft_strlen(parser->name));
	pos += PROG_NAME_LENGTH;
	pos += 4;
	int32_to_int8(bytecode, pos, parser->pos, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->comment, ft_strlen(parser->comment));
	pos += COMMENT_LENGTH;
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->code, (size_t)parser->pos);
	write(fd, bytecode, (size_t)len);
}

static int8_t get_types_len(t_token *token)
{
	int i;
	int8_t ret;
	int8_t type_code; 

	ret = 1;
	if (token->op_tab->args_types_code == 0)
		return (ret + token->op_tab->t_dir_size);
	ret++;
	type_code = token->type_code >> 2;
	i = 0;
	while (i < 3)
	{
		if ((type_code & IND_CODE) == IND_CODE)
			ret += 2;
		else if ((type_code & REG_CODE) == REG_CODE)
			ret++;
		else if ((type_code & DIR_CODE) == DIR_CODE)
			ret += token->op_tab->t_dir_size;
		type_code = type_code >> 2;	
		i++;
	}
	return (ret);
}

static void print_op_content(t_parser *parser, int i)
{
	int j;
	int k;
	
	ft_printf("%8c", ' ');
	ft_printf("%-10s", parser->tokens[i]->content);
	j = 1;
	k = 0;
	while (j <= parser->tokens[i]->op_tab->args_num + k)
	{
		if (parser->tokens[i + j]->type == SEPARATOR)
			k++;
		else
			ft_printf("%-10s", parser->tokens[i + j]->content);
		j++;
	}
	ft_printf("\n");
}

static void print_op_number(t_parser *parser, int i)
{
	int j;
	int k;
	int type_code;

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
			ft_printf("%-10d", parser->tokens[i + j]->number);
		j++;
	}
	ft_printf("\n");
}


void		write_standart_output(t_parser *parser)
{
	int	i;
	int current;
	int op_len;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", parser->pos);
	ft_printf("Name : \"%s\"\n", parser->name);
	ft_printf("Comment : \"%s\"\n\n", parser->comment);
	
	current = 0;
	i = -1;
	while (++i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		if (parser->tokens[i]->type == LABEL)
			ft_printf("%-5d      :    %s\n", current, parser->tokens[i]->content);
		else if (parser->tokens[i]->type == INSTRUCTION)
		{
			op_len = get_types_len(parser->tokens[i]);
			ft_printf("%-5d(%-3d) :", current, op_len);
			print_op_content(parser, i);
			print_op_number(parser, i);
			current += op_len;
		}
	}
}
