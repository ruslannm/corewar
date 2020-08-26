/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 17:22:01 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:23:17 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_live(t_vm *vm, t_car *car, t_args *arg)
{
	int champ;

	(void)arg->first;
	vm->count_live++;
	car->last_live_cycle = 0;
	champ = read_4_bytes(vm, (car->position + 1) % MEM_SIZE) * -1;
	if (champ > 0 && champ <= vm->players.size)
		vm->win_id = champ;
	car->position = ((car->position) + 5) % MEM_SIZE;
	car->step = 1;
}
