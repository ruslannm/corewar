/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:56:27 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 14:07:50 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	plus_minus(t_vm *vm, t_car *car, t_args *arg, int type)
{
	int res_dir;

	car->step += 1;
	arg->f_val = read_1_byte(vm, get_pos(car, car->step)) - 1;
	car->step += REG_CODE;
	arg->s_val = read_1_byte(vm, get_pos(car, car->step)) - 1;
	car->step += REG_CODE;
	arg->t_val = read_1_byte(vm, get_pos(car, car->step)) - 1;
	if (arg->f_val >= 0 && arg->f_val < REG_NUMBER &&
		arg->s_val >= 0 && arg->s_val < REG_NUMBER &&
		arg->t_val >= 0 && arg->t_val < REG_NUMBER)
	{
		if (type == 1)
			res_dir = car->regist[arg->f_val] + car->regist[arg->s_val];
		else
			res_dir = car->regist[arg->f_val] - car->regist[arg->s_val];
		car->regist[arg->t_val] = res_dir;
		if (!res_dir)
			car->carry = 1;
		else
			car->carry = 0;
	}
}
