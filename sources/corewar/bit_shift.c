/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:46:31 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:48:15 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	bit_shift(unsigned char *buffer, int n)
{
	int				i;
	unsigned int	x_number;

	i = 0;
	x_number = 0;
	while (i < n)
	{
		x_number |= buffer[i];
		if (i == n - 1)
			break ;
		x_number <<= 8;
		i++;
	}
	return (x_number);
}
