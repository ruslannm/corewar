/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:22:13 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:54:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*kill_carry(t_vm *vm, t_car **head, t_car *cur_car, int cycle_to_die)
{
	if (cur_car->last_live_cycle >= cycle_to_die)
	{
		--vm->num_car;
		if (cur_car->prev && !cur_car->next)
			return (del_end(cur_car));
		else if (cur_car == *head)
			return (del_start(head, cur_car));
		else if (cur_car->prev && cur_car->next)
			return (del_midl(cur_car));
	}
	return (cur_car->next);
}

int		check_live(t_vm *vm)
{
	t_car *tmp;

	vm->count_check++;
	tmp = vm->carry;
	while (tmp)
		tmp = kill_carry(vm, &vm->carry, tmp, vm->cycle_to_die);
	if (vm->count_live >= NBR_LIVE || vm->count_check >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->count_check = 0;
	}
	vm->iter = 0;
	vm->count_live = 0;
	return (vm->carry ? 1 : 0);
}
