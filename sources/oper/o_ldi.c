/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_ldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:38:58 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 14:39:53 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	o_ldi(t_vm *vm, t_car *car, t_args *arg)
{
	int els;
	int sum;
	int val;
	int arg_reg;

	(void)arg->first;
	car->step = 1 + 1;
	els = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, els))
	{
		sum = get_arg_n(vm, car, els) + get_arg_n(vm, car, els << 2);
		val = read_4_bytes(vm, get_pos(car, sum % IDX_MOD));
		arg_reg = vm->arena[(car->position + car->step) % MEM_SIZE];
		set_reg(car, arg_reg, val, 0);
	}
	car->position = get_pos(car, get_arg_step(els, 3, DIR_SIZE / 2));
	car->step = 1;
}
