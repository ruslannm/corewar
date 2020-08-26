/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:58:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:04 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	o_zjmp(t_vm *vm, t_car *car, t_args *arg)
{
	int arg_dir;

	(void)arg->first;
	if (car->carry)
	{
		arg_dir = read_2_bytes(vm, (car->position + 1) % MEM_SIZE);
		car->position = get_pos(car, arg_dir % IDX_MOD);
	}
	else
		car->position = (car->position + 3) % MEM_SIZE;
}
