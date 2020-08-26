/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:37:17 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:22:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_pos(t_car *car, int position)
{
	int	new_position;

	new_position = car->position + position;
	if (new_position >= MEM_SIZE || -new_position >= MEM_SIZE)
		new_position %= MEM_SIZE;
	if (new_position < 0)
		new_position += MEM_SIZE;
	return (new_position);
}

void	set_reg(t_car *car, int reg, int value, int f)
{
	if (f)
		car->carry = value ? 0 : 1;
	car->regist[--reg] = value;
}

int		get_arg_step(int args, int num, int dir_size)
{
	int	add;
	int	shift;

	add = 1;
	shift = 0;
	while (num--)
	{
		if (check_arg(args << shift) == REG_CODE)
			add += 1;
		else if (check_arg(args << shift) == DIR_CODE)
			add += dir_size;
		else if (check_arg(args << shift) == IND_CODE)
			add += 2;
		shift += 2;
	}
	return (++add);
}
