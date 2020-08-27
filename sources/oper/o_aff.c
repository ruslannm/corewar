/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:15:05 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 14:00:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_aff(t_vm *vm, t_car *car, t_args *arg)
{
	int val;

	arg->first = def_arg(vm->arena[get_pos(car, car->step)], 0);
	car->step += 1;
	if (arg->first == REG_CODE && vm->is_aff)
	{
		arg->f_val = read_1_byte(vm, get_pos(car, car->step)) - 1;
		if (arg->f_val >= 0 && arg->f_val < REG_NUMBER)
		{
			val = (char)car->regist[arg->f_val];
			ft_putstr("AFF: ");
			ft_putchar(val);
			ft_putchar('\n');
		}
	}
	relocate(car, arg, 1);
}
