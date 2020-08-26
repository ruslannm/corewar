/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:07:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 13:16:31 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	oper_func_cont(t_vm *vm, t_car *car, t_args *arg, int i)
{
	if (i == 10)
		o_sti(vm, car, arg);
	else if (i == 11)
		o_fork(vm, car, arg);
	else if (i == 12)
		o_lld(vm, car, arg);
	else if (i == 13)
		o_lldi(vm, car, arg);
	else if (i == 14)
		o_lfork(vm, car, arg);
	else if (i == 15)
		o_aff(vm, car, arg);
}

void	oper_func(t_vm *vm, t_car *car, t_args *arg, int i)
{
	if (i == 0)
		o_live(vm, car, arg);
	else if (i == 1)
		o_ld(vm, car, arg);
	else if (i == 2)
		o_st(vm, car, arg);
	else if (i == 3)
		o_add(vm, car, arg);
	else if (i == 4)
		o_sub(vm, car, arg);
	else if (i == 5)
		o_and(vm, car, arg);
	else if (i == 6)
		o_or(vm, car, arg);
	else if (i == 7)
		o_xor(vm, car, arg);
	else if (i == 8)
		o_zjmp(vm, car, arg);
	else if (i == 9)
		o_ldi(vm, car, arg);
	else
		oper_func_cont(vm, car, arg, i);
}
