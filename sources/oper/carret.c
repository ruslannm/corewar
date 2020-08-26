/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:10:05 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/18 21:21:48 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_car *cp_car(t_car *main, int position, int id)
{
    t_car *new;

    if (!(new = ft_calloc(1, sizeof(t_car))))
        ft_error("Error in malloc", "copy carret", 3);
    else
    {
        ft_memcpy(new, main, sizeof(t_car));
        new->position = position;
        new->id = id;
    }
    return (new);
}

