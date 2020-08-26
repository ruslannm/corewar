/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:51:05 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:23:46 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_sti(t_vm *vm, t_car *car, t_args *arg)
{
	int p;
	int arg_reg;
	int i;

	arg->first = def_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->second = def_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = def_arg(vm->arena[get_pos(car, car->step)], 2);
	car->step += 1;
	if (arg->first != 0 && arg->second != 0 && arg->third != 0)
		if (check_reg(vm, car, arg->first, &arg_reg) &&\
	get_dir_2(vm, car, arg->second, &arg->s_val) && \
	get_third(vm, car, arg->third, &arg->t_val))
		{
			p = get_pos(car, (arg->s_val + arg->t_val) % IDX_MOD);
			i = -1;
			while (++i < 4)
				vm->arena[(p + i) % MEM_SIZE] =\
	*((char*)&car->regist[arg_reg] + 3 - i);
		}
	arg->first = arg->first == DIR_SIZE ? DIR_SIZE / 2 : arg->first;
	arg->second = arg->second == DIR_SIZE ? DIR_SIZE / 2 : arg->second;
	arg->third = arg->third == DIR_SIZE ? DIR_SIZE / 2 : arg->third;
	relocate(car, arg, 3);
}
