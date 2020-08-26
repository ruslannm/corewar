/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ex_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:24:09 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 12:08:32 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	valid_ex_code(t_pars *pars, t_players *players)
{
	char buf[players->arr[players->iter]->ex_size];
	char *exec_code;

	if ((read(pars->fd, buf, players->arr[players->iter]->ex_size)) \
	!= (ssize_t)players->arr[players->iter]->ex_size)
		ft_error("Exec code's size is invalid", "valid_ex_code", 2);
	exec_code = ft_calloc(players->arr[players->iter]->ex_size, sizeof(char));
	ft_memcpy(exec_code, buf, players->arr[players->iter]->ex_size);
	players->arr[players->iter]->ex_code = exec_code;
}
