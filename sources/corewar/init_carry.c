/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:31:59 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:26:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_carry(t_vm *vm, int iter)
{
	t_car	*list;
	int		i;

	i = 0;
	list = ft_lstnew(0, 1);
	vm->id_car++;
	vm->num_car = 1;
	while (++i < iter)
	{
		ft_lstadd_start(&list, ft_lstnew((MEM_SIZE / iter) * i, i + 1));
		vm->id_car++;
		vm->num_car++;
	}
	vm->carry = list;
}
