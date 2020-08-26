/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:41:10 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 11:57:05 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	set_players(t_players *players, int new_size)
{
	t_player **new_array;

	players->iter = 0;
	players->size = new_size;
	if (!(new_array = ft_calloc(new_size, sizeof(t_player *))))
		ft_error("Error in malloc", "set_players", 3);
	else
	{
		while (players->iter != new_size)
		{
			new_array[players->iter] = players->arr[players->iter];
			players->iter++;
		}
		free(players->arr);
		players->arr = new_array;
	}
}
