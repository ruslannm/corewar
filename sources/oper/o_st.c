/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:51:54 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:23:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_second(t_vm *vm, t_car *car, int type, int *arg)
{
	if (type != REG_CODE && type != IND_SIZE)
		return (0);
	if (type == REG_CODE)
	{
		*arg = read_1_byte(vm, get_pos(car, car->step)) - 1;
		if (*arg < 0 || *arg >= REG_NUMBER)
			return (0);
	}
	else
		*arg = read_2_bytes(vm, get_pos(car, car->step)) % IDX_MOD;
	car->step += type;
	return (1);
}

void	o_st(t_vm *vm, t_car *car, t_args *arg)
{
	int arg_reg;
	int pos;
	int i;

	arg->first = def_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->second = def_arg(vm->arena[get_pos(car, car->step)], 1);
	car->step += 1;
	if (check_reg(vm, car, arg->first, &arg_reg) && \
	get_second(vm, car, arg->second, &arg->s_val))
	{
		if (arg->second == REG_CODE)
			car->regist[arg->s_val] = car->regist[arg_reg];
		else
		{
			pos = get_pos(car, arg->s_val);
			i = -1;
			while (++i < 4)
				vm->arena[(pos + i) % MEM_SIZE] = \
	*((char *)&car->regist[arg_reg] + 3 - i);
		}
	}
	relocate(car, arg, 2);
}
