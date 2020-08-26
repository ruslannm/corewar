/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:17:01 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:56 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_to_reg(t_vm *vm, t_car *car, int result, int third)
{
	int reg_dir;

	reg_dir = read_1_byte(vm, get_pos(car, car->step)) - 1;
	if ((third == REG_CODE) && (reg_dir >= 0 && reg_dir < REG_NUMBER))
	{
		car->regist[reg_dir] = result;
		car->carry = result ? 0 : 1;
	}
}
