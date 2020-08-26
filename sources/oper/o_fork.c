/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 20:06:32 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:22:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_fork(t_vm *vm, t_car *car, t_args *arg)
{
	t_car	*new_car;
	int		pos;
	int		arg_dir;

	(void)arg->first;
	arg_dir = read_2_bytes(vm, (car->position + 1) % MEM_SIZE) % IDX_MOD;
	pos = get_pos(car, arg_dir);
	new_car = cp_car(car, pos, ++vm->id_car);
	ft_lstadd_start(&vm->carry, new_car);
	car->position = (car->position + 3) % MEM_SIZE;
	vm->num_car++;
}
