/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 08:51:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/19 15:41:48 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int get_dir_2(t_vm *vm, t_car *car, int arg, int *value)
{
    if (arg == REG_CODE)
    {
        *value = read_1_byte(vm, get_pos(car, car->step)) - 1;
        if (*value >= 0 && *value < REG_NUMBER)
        {
            // printf("%i\n", *value);
            *value = car->regist[*value];
        }
        else
            return (0);
    }
    else if (arg == IND_SIZE)
    {
        *value = read_4_bytes(vm, get_pos(car, read_2_bytes(vm, get_pos(car, car->step)) % IDX_MOD));
        // printf("%i\n", *value);
    }
    else if (arg == DIR_SIZE)
    {
        *value = read_2_bytes(vm, get_pos(car, car->step));
        arg = DIR_SIZE / 2;
        // printf("%i\n", *value);
    }       
    else
        return(0);
    car->step += arg;
    // printf("%i\n", car->step);
    return (1);
}

int get_dir_4(t_vm *vm, t_car *car, int arg, int *value)
{
    if (arg == REG_CODE)
    {
        *value = read_1_byte(vm, get_pos(car, car->step)) - 1;
        if (*value >= 0 && *value < REG_NUMBER)
        {
            // printf("%i\n", *value);
            *value = car->regist[*value];}
        else
            return (0);
    }
    else if (arg == IND_SIZE){
        // printf("%i\n", *value);
        *value = read_4_bytes(vm, get_pos(car, read_2_bytes(vm, get_pos(car, car->step)) % IDX_MOD));
        }
    else if (arg == DIR_SIZE){
        // printf("%i\n", *value);
        *value = read_4_bytes(vm, get_pos(car, car->step));
        }
    else
        return (0);
    car->step += arg;
    // printf("%i\n", *value);
    return (1);
}