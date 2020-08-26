/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_champ_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:01:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 11:27:30 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	valid_champ_name(t_pars *pars, t_players *players)
{
	char	buf[PROG_NAME_LENGTH + 1];
	char	*name;
	size_t	size;

	if ((read(pars->fd, buf, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		ft_error("Champ name is invalid", "valid_champ_name", 2);
	buf[PROG_NAME_LENGTH] = '\0';
	size = ft_strlen(buf);
	name = ft_calloc(size + 1, sizeof(char));
	name[size] = '\0';
	ft_memcpy(name, buf, size);
	players->arr[players->iter]->name = name;
	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("Null's octet is invalid", "valid_champ_name", 2);
}
