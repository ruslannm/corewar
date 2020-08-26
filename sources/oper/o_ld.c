/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:23:11 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 13:26:34 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	o_ld(t_vm *vm, t_car *car, t_args *arg)
{
	int argument;
	int arg_reg;
	int pos;
	int val;

	arg_reg = 0;
	(void)arg->first;
	argument = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(argument) == DIR_CODE && check_arg(argument << 2) == REG_CODE)
	{
		val = read_4_bytes(vm, (car->position + 2) % MEM_SIZE);
		arg_reg = vm->arena[(car->position + 6) % MEM_SIZE];
	}
	else if (check_arg(argument) == IND_CODE && \
	check_arg(argument << 2) == REG_CODE)
	{
		pos = (read_2_bytes(vm, (car->position + 2) % MEM_SIZE)) % IDX_MOD;
		val = read_4_bytes(vm, get_pos(car, pos));
		arg_reg = vm->arena[(car->position + 4) % MEM_SIZE];
	}
	if (arg_reg > 0 && arg_reg <= REG_NUMBER)
		set_reg(car, arg_reg, val, 1);
	car->position = get_pos(car, get_arg_step(argument, 2, DIR_SIZE));
}
