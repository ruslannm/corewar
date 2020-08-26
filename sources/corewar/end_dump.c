/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:47:24 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 13:03:12 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	end_dump(t_vm *vm)
{
	t_car	*tmp;

	print_memory(vm->arena, vm->dump_size);
	tmp = vm->carry;
	return (1);
}
