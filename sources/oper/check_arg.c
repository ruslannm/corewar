/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:41:44 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 13:13:08 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	check_arg(int arg)
{
	arg = (arg >> 6) & 0x03;
	if (0x01 == arg)
		return (REG_CODE);
	else if (0x02 == arg)
		return (DIR_CODE);
	else if (0x03 == arg)
		return (IND_CODE);
	return (0);
}
