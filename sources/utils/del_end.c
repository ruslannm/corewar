/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:14:43 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:19:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*del_end(t_car *cur_car)
{
	cur_car->prev->next = NULL;
	free(cur_car);
	return (NULL);
}
