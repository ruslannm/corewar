/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:19:18 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int16_t	read_2_bytes(t_vm *vm, int position)
{
	int16_t	val;
	int		i;

	i = 0;
	val = 0;
	while (i < 2)
	{
		*((char *)&val + 1 - i) = vm->arena[(position + i) % MEM_SIZE];
		i++;
	}
	return (val);
}
