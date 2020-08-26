/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:31:36 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:43 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_oper(t_vm *vm)
{
	vm->operations.op_cycles[0] = 10;
	vm->operations.op_cycles[1] = 5;
	vm->operations.op_cycles[2] = 5;
	vm->operations.op_cycles[3] = 10;
	vm->operations.op_cycles[4] = 10;
	vm->operations.op_cycles[5] = 6;
	vm->operations.op_cycles[6] = 6;
	vm->operations.op_cycles[7] = 6;
	vm->operations.op_cycles[8] = 20;
	vm->operations.op_cycles[9] = 25;
	vm->operations.op_cycles[10] = 25;
	vm->operations.op_cycles[11] = 800;
	vm->operations.op_cycles[12] = 10;
	vm->operations.op_cycles[13] = 50;
	vm->operations.op_cycles[14] = 1000;
	vm->operations.op_cycles[15] = 2;
}
