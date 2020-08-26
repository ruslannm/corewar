/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:43:33 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:25:26 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_data(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->players.iter)
	{
		free((vm->players.arr[i]->name));
		free(vm->players.arr[i]->comment);
		free(vm->players.arr[i]->ex_code);
		free(vm->players.arr[i]);
		i++;
	}
	free(vm->players.arr);
}
