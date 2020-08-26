/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:23:17 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:22:30 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_add(t_vm *vm, t_car *car, t_args *arg)
{
	arg->first = def_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->second = def_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = def_arg(vm->arena[get_pos(car, car->step)], 2);
	if (arg->first == REG_CODE && arg->second == REG_CODE &&\
	arg->third == REG_CODE)
		plus_minus(vm, car, arg, 1);
	relocate(car, arg, 3);
}
