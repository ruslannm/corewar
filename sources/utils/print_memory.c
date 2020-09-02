/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:48:57 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 18:59:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*g_str = "0123456789abcdef";

static void	add(int i)
{
	ft_putstr("0x");
	ft_putchar(g_str[((i >> 8) / 16) % 16]);
	ft_putchar(g_str[(i >> 8) % 16]);
	ft_putchar(g_str[(i / 16) % 16]);
	ft_putchar(g_str[i % 16]);
	ft_putstr(" : ");
}

void		print_memory(const void *arena, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*p;

	p = (unsigned char *)arena;
	i = 0;
	while (i < MEM_SIZE)
	{
		add(i);
		j = 0;
		while (j < size && i + j < MEM_SIZE)
		{
			ft_putchar(g_str[(*(p + i + j) / 16) % 16]);
			ft_putchar(g_str[*(p + i + j) % 16]);
			ft_putstr(" ");
			j++;
		}
		ft_putchar('\n');
		i += size;
	}
}
