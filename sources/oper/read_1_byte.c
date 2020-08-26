/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_1_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:35:08 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:24:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	read_1_byte(t_vm *vm, int position)
{
	unsigned char val;

	val = vm->arena[position];
	return (val);
}
