/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:52:54 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/18 15:01:01 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int get_arg_n(t_vm *vm, t_car *car, int arg)
{
    int res;
    int val;

    res = 0;
    if (check_arg(arg) == REG_CODE)
    {
        val = (vm->arena[(car->position + car->step) % MEM_SIZE]);
        res = car->regist[--val];
        car->step++;
    }
    else if (check_arg(arg) == DIR_CODE)
	{
		res = read_2_bytes(vm, (car->position + car->step) % MEM_SIZE);
		car->step += 2;
	}
	else if (check_arg(arg) == IND_CODE)
	{
		val = read_2_bytes(vm, (car->position + car->step) % MEM_SIZE);
		res = read_4_bytes(vm, get_pos(car, val % IDX_MOD));
		car->step += 2;
	}
	return (res);
}