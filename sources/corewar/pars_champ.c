/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:32:30 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 11:25:08 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	pars_champ(t_pars *pars, t_players *players)
{
	check_m_h(pars);
	valid_champ_name(pars, players);
	valid_exec_size(pars, players);
	check_comment(pars, players);
	valid_ex_code(pars, players);
	players->iter++;
	pars->i++;
}
