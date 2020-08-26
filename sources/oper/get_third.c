/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_third.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/20 09:13:17 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int get_third(t_vm *vm, t_car *car, int arg, int *val)
{
    if (arg != REG_CODE && arg != DIR_SIZE)
        return(0);
    if (arg == REG_CODE)
    {
        *val = read_1_byte(vm, get_pos(car, car->step)) - 1;
        if (*val < 0 || *val >= REG_NUMBER)
            return(0);
        *val = car->regist[*val];
        // printf("%i\n", *val);
    }
    else
    {
        *val = read_2_bytes(vm, get_pos(car, car->step));
        // printf("val =%i\n", *val);
        arg = DIR_SIZE / 2;
    }
    car->step += arg;
    return (1);
}