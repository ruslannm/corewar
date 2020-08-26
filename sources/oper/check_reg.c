/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:29:48 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:21:57 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_reg(t_vm *vm, t_car *car, int code, int *arg)
{
	if (code != REG_CODE)
		return (0);
	*arg = read_1_byte(vm, get_pos(car, car->step)) - 1;
	car->step += 1;
	return ((*arg >= 0 && *arg < REG_NUMBER) ? 1 : 0);
}
