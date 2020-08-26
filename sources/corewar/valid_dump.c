/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:01:26 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 11:18:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	check_dump(t_pars *pars)
{
	char *str;

	if (!pars->dump_flag)
		pars->dump_flag = 1;
	else if (pars->dump_flag)
		ft_error("Repetition of \"-dump\"", "valid dump", 2);
	if (!pars->av[++pars->i])
		ft_error("Flag \"-dump\" isn't correct", "valid dump", 2);
	str = pars->av[pars->i];
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error("Flag \"-dump\" is incorrect", "valid dump", 2);
		str++;
	}
}

int			valid_dump(t_pars *pars, t_players *players)
{
	int64_t	dump_number;
	int32_t	d_number;

	check_dump(pars);
	dump_number = ft_atoi(pars->av[pars->i]);
	d_number = dump_number;
	if ((int64_t)d_number != dump_number)
		ft_error("Over int in \"-dump\"", "valid dump", 2);
	if (ft_strequ(pars->av[(pars->i) - 1], "-d"))
		players->dump_size = 64;
	else
		players->dump_size = 32;
	players->dump_num = d_number >= 0 ? dump_number : -1;
	++pars->i;
	return (1);
}
