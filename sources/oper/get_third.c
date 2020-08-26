/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_third.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:22:25 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_third(t_vm *vm, t_car *car, int arg, int *val)
{
	if (arg != REG_CODE && arg != DIR_SIZE)
		return (0);
	if (arg == REG_CODE)
	{
		*val = read_1_byte(vm, get_pos(car, car->step)) - 1;
		if (*val < 0 || *val >= REG_NUMBER)
			return (0);
		*val = car->regist[*val];
	}
	else
	{
		*val = read_2_bytes(vm, get_pos(car, car->step));
		arg = DIR_SIZE / 2;
	}
	car->step += arg;
	return (1);
}
