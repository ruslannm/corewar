/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:29:48 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/20 09:13:09 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int check_reg(t_vm *vm, t_car *car, int code, int *arg)
{
	if (code != REG_CODE)
		return (0);
	*arg = read_1_byte(vm, get_pos(car, car->step)) - 1;
	// printf("arg = %i\n", *arg);
	car->step += 1;
	return ((*arg >= 0 && *arg < REG_NUMBER) ? 1 : 0);
}