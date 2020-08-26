/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_1_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:35:08 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 13:09:34 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

unsigned char	read_1_byte(t_vm *vm, int position)
{
	unsigned char val;

	val = vm->arena[position];
	return (val);
}
