/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:05:55 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:26:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int ac, char **av)
{
	t_vm virtual_machine;

	init_data(&virtual_machine, ac, av);
	print_start(&virtual_machine.players);
	game(&virtual_machine);
	free_data(&virtual_machine);
	return (0);
}
