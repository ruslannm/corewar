/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:22 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 11:07:15 by rgero            ###   ########.fr       */
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

void		write_standart_output(t_parser *parser)
{
	int	i;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", parser->pos);
	ft_printf("Name : \"%s\"\n", parser->name);
	ft_printf("Comment : \"%s\"\n\n", parser->comment);
	
	i = -1;
	while (++i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		if (parser->tokens[i]->type == LABEL)
			ft_printf("%8d    :    %s\n", parser->tokens[i]->op_pos, parser->tokens[i]->content);
		else if (parser->tokens[i]->type == INSTRUCTION)
			ft_printf("%8d:(%d) :    %s\n", parser->tokens[i]->op_pos, parser->tokens[i]->type_code, parser->tokens[i]->content);
	}
}
