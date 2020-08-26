/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:28:06 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 08:56:56 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	init_players(t_players *players)
{
	if (!(players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player *))))
		ft_error("Malloc error", "init_players", 3);
	players->dump_num = -1;
	players->size = MAX_PLAYERS;
}

void	init_data(t_vm *vm, int ac, char **av)
{
	ft_memset(vm, 0, sizeof(t_vm));
	set_oper(vm);
	init_players(&(vm->players));
	parsing(&(vm->players), ac, av);
	init_vm(vm, &(vm->players));
}
