/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exec_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:57:16 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:27:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	valid_exec_size(t_pars *pars, t_players *players)
{
	unsigned char	buf[4];
	unsigned int	exec_size;

	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("Exec_code is invalid", "valid_exc_size", 2);
	exec_size = bit_shift(buf, 4);
	if (exec_size > CHAMP_MAX_SIZE)
		ft_error("Ex_code is invalid", "valid_ex_size", 2);
	players->arr[players->iter]->ex_size = exec_size;
}
