/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:01:53 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:49 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			invalid_reg(t_vm *vm, t_car *car, int args, int num)
{
	int		reg_dir;
	int		pos;

	pos = (get_pos(car, get_arg_step(args, num, DIR_SIZE / 2)));
	reg_dir = (vm->arena[pos]);
	if (reg_dir < 1 || reg_dir > REG_NUMBER)
		return (1);
	car->step += 1;
	return (0);
}

int			valid_args(t_vm *vm, t_car *car, int args)
{
	int		res;
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = check_arg(args);
	arg2 = check_arg(args << 2);
	arg3 = check_arg(args << 4);
	res = 0;
	if ((arg1 == REG_CODE || arg1 == DIR_CODE || arg1 == IND_CODE) &&
	(arg2 == REG_CODE || arg2 == DIR_CODE) && (arg3 == REG_CODE))
		res = 1;
	if (arg1 == REG_CODE && invalid_reg(vm, car, args, 0))
		res = 0;
	if (arg2 == REG_CODE && invalid_reg(vm, car, args, 1))
		res = 0;
	if (arg3 == REG_CODE && invalid_reg(vm, car, args, 2))
		res = 0;
	car->step = 2;
	return (res);
}
