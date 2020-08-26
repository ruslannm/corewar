/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:46:34 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:54:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*check_carry(t_vm *vm, t_car *car)
{
	car->last_live_cycle++;
	if (!car->cycle_to_action)
	{
		car->code = read_1_byte(vm, car->position) - 1;
		if (car->code >= 0 && car->code < REG_NUMBER)
			car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
		else
			car->position = get_pos(car, 1);
	}
	else if (!(--car->cycle_to_action))
		oper_func(vm, car, &vm->operations.arg, car->code);
	return (car->next);
}
