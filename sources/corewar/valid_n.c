/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:25:48 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 16:56:27 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	valid_n(t_pars *pars, t_players *players)
{
	size_t	j;
	int64_t	ident;
	int32_t	id;

	j = 0;
	pars->i++;
	if (pars->i == pars->ac)
		ft_error("Invalid \"-n\"", "valid flag", 2);
	while (pars->av[pars->i][j])
	{
		if (!ft_isdigit(pars->av[pars->i][j]))
			ft_error("id is incorrect", "pars_id", 2);
		j++;
	}
	ident = ft_atoi(pars->av[pars->i++]);
	id = ident;
	if ((int64_t)id != ident)
		ft_error("Over int in \"-n\"", "valid flag", 2);
	if ((id > MAX_PLAYERS) || (id < 1))
		ft_error("id is incorrect", "pars id", 2);
	valid_name(pars, players);
	players->arr[players->iter]->flag_n = 1;
	players->arr[players->iter]->id = id;
}
