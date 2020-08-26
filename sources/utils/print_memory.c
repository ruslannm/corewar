/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:48:57 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/18 12:49:47 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			add(int i)
{
	char			*str;

	str = "0123456789abcdef";
	ft_putstr("0x");
	write(1, &str[((i >> 8) / 16) % 16], 1);
	write(1, &str[(i >> 8) % 16], 1);
	write(1, &str[(i / 16) % 16], 1);
	write(1, &str[i % 16], 1);
	ft_putstr(" : ");
}

void	print_memory(const void *arena, size_t size)
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
			write(1, &str[(*(p + i + j) / 16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			ft_putstr(" ");
			j++;
		}
		ft_putchar('\n');
		i += size;
	}
}
