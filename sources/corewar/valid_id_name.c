/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_id_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:04:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 16:47:36 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	sort_id(t_players *players, int i, int j)
{
	t_player **ar;

	ar = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	while (++i < players->iter)
		if (!(players->arr[i]->flag_n))
			ar[j++] = players->arr[i];
	i = -1;
	while (++i < players->iter)
		while (players->arr[i]->flag_n && i != players->arr[i]->id - 1)
			ft_swap(&players->arr[players->arr[i]->id - 1], &players->arr[i]);
	i = -1;
	j = 0;
	while (++i < players->iter)
	{
		if (!(players->arr[i]->flag_n))
			players->arr[i] = ar[j++];
		players->arr[i]->id = i + 1;
	}
	free(ar);
}

void		valid_name(t_pars *pars, t_players *players)
{
	char *ptr;

	if (pars->i == pars->ac)
		ft_error("No player after \"-n\"", "valid_name", 2);
	ptr = pars->av[pars->i] + (ft_strlen(pars->av[pars->i]) - 4);
	if (!ft_strequ(ptr, ".cor"))
		ft_error("Invalid format of the file", "valid_name", 2);
	if ((pars->fd = open(pars->av[pars->i], O_RDONLY)) <= 0)
		ft_error("Invalid file", "valid_name", 2);
	if (!players->arr[players->iter])
		players->arr[players->iter] = ft_calloc(1, sizeof(t_player));
	players->arr[players->iter]->id = players->iter + 1;
	players->arr[players->iter]->flag_n = 0;
}

void		validate_id(t_players *players)
{
	int i;
	int j;

	i = -1;
	while (++i < players->iter)
	{
		if (players->arr[i]->id > players->iter)
			ft_error("Too large id", "valid_id", 2);
		j = i;
		{
			while (++j < players->iter)
				if (players->arr[i]->flag_n && players->arr[j]->flag_n &&\
				players->arr[i]->id == players->arr[j]->id)
					ft_error("Id repetition", "valid id", 2);
		}
	}
	i = -1;
	j = 0;
	sort_id(players, i, j);
}
