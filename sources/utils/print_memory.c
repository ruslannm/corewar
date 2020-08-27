/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:48:57 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 11:55:52 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add(int i)
{
	char			*str;

	str = "0123456789abcdef";
	ft_putstr("0x");
	ft_putchar(str[((i >> 8) / 16) % 16]);
	ft_putchar(str[(i >> 8) % 16]);
	ft_putchar(str[(i / 16) % 16]);
	ft_putchar(str[i % 16]);
	ft_putstr(" : ");
}

void		print_memory(const void *arena, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*p;
	char			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)arena;
	i = 0;
	while (i < MEM_SIZE)
	{
		add(i);
		j = 0;
		while (j < size && i + j < MEM_SIZE)
		{
			ft_putchar(str[(*(p + i + j) / 16) % 16]);
			ft_putchar(str[*(p + i + j) % 16]);
			ft_putstr(" ");
			j++;
		}
		ft_putchar('\n');
		i += size;
	}
}
