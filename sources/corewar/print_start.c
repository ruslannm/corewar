/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:30:23 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 12:57:36 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_start(t_players *players)
{
	int		i;
	char	n;

	i = 0;
	n = '0';
	ft_putstr("Introducing contestants...\n");
	while (i < players->size)
	{
		ft_putstr("* Player ");
		n++;
		write(1, &n, 1);
		ft_putstr(", weighing ");
		ft_putnbr(players->arr[i]->ex_size);
		ft_putstr(" bytes, \"");
		ft_putstr(players->arr[i]->name);
		ft_putstr("\" (\"");
		ft_putstr(players->arr[i]->comment);
		ft_putstr("\") !");
		ft_putchar('\n');
		i++;
	}
}
