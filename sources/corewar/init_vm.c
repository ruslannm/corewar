/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:52:25 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 13:58:43 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_vm_arena(t_vm *vm, t_players *players)
{
	int i;
	int pos;

	i = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	while (i < players->iter)
	{
		pos = (MEM_SIZE / players->iter) * i;
		ft_memcpy(&(vm->arena[pos]), players->arr[i]->ex_code, \
		players->arr[i]->ex_size);
		i++;
	}
}

void		init_vm(t_vm *vm, t_players *players)
{
	init_vm_arena(vm, players);
	init_carry(vm, players->size);
	vm->dump_value = players->dump_num >= 0 ? players->dump_num : -1;
	vm->dump_size = players->dump_size;
	vm->win_id = players->size;
	vm->is_aff = players->is_aff;
}
