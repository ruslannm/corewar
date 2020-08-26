/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_midl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:14:28 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/12 09:31:55 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_car *del_midl(t_car *cur_car)
{
    t_car *tmp;

    tmp = cur_car;
    cur_car = cur_car->next;
    cur_car->prev = tmp->prev;
    cur_car->prev->next = cur_car;
    free(tmp);
    return (cur_car);
}