/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_lfork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:07:17 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:23:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_lfork(t_vm *vm, t_car *car, t_args *arg)
{
	t_car	*new;
	int		pos;
	int		arg_dir;

	(void)arg->first;
	arg_dir = read_2_bytes(vm, (car->position + 1) % MEM_SIZE);
	pos = get_pos(car, arg_dir);
	new = cp_car(car, pos, ++vm->id_car);
	ft_lstadd_start(&vm->carry, new);
	car->position = (car->position + 3) % MEM_SIZE;
	vm->num_car++;
}
