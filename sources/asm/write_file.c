/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:22 by rgero             #+#    #+#             */
/*   Updated: 2020/08/06 21:31:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	int_to_bigendian(char *str,
							int32_t pos,
							int32_t value,
							size_t size)
{
	uint8_t	i;

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

	len = 4;
	pos = 0;
	if (!(bytecode = ft_strnew(len)))
		terminate(parser, "Memory allocation in write_file");
	int_to_bigendian(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	write(fd, bytecode, len);
	free(bytecode);
}
