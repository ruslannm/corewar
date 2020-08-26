/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:51:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:22:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_and(t_vm *vm, t_car *car, t_args *arg)
{
	int val;

	arg->first = def_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->second = def_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = def_arg(vm->arena[get_pos(car, car->step)], 2);
	car->step += 1;
	if (arg->first != 0 && arg->second != 0 && arg->third != 0 && \
	get_dir_4(vm, car, arg->first, &arg->f_val) && \
	get_dir_4(vm, car, arg->second, &arg->s_val))
	{
		val = arg->f_val & arg->s_val;
		write_to_reg(vm, car, val, arg->third);
	}
	relocate(car, arg, 3);
}
