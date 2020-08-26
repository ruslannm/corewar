/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:51:49 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:25:15 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*del_func(t_car **head, t_car *cur_car)
{
	if (cur_car->next)
	{
		cur_car = cur_car->next;
		free(cur_car->prev);
		cur_car->prev = NULL;
		*head = cur_car;
	}
	else
	{
		free(cur_car);
		cur_car = NULL;
		*head = NULL;
	}
	return (cur_car);
}
