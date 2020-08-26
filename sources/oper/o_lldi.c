/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:44:54 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:23:28 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_lldi(t_vm *vm, t_car *car, t_args *arg)
{
	int els;
	int val;
	int arg_reg3;

	(void)arg->first;
	car->step = 2;
	els = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, els))
	{
		val = read_4_bytes(vm, get_pos(car, get_arg_n(vm, car, els) +\
	get_arg_n(vm, car, els << 2)));
		arg_reg3 = vm->arena[(car->position + car->step) % MEM_SIZE];
		set_reg(car, arg_reg3, val, 1);
	}
	car->position = get_pos(car, get_arg_step(els, 3, DIR_SIZE / 2));
	car->step = 1;
}
