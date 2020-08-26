/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:14:43 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/12 09:28:52 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_car *del_end(t_car *cur_car)
{
    cur_car->prev->next = NULL;
    free(cur_car);
    return (NULL);
}
