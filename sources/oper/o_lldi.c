/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:44:54 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/20 19:26:49 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void o_lldi(t_vm *vm, t_car *car, t_args *arg)
{
    int els;
    int val;
    int arg_reg3;

    (void)arg->first;
    car->step = 2;
    // printf("%i\n", car->position);
    els = vm->arena[(car->position + 1) % MEM_SIZE];
    // printf("ar=%i\n", els);
    if (valid_args(vm, car, els))
    {
        val = read_4_bytes(vm, get_pos(car, get_arg_n(vm, car, els) +\
         get_arg_n(vm, car, els << 2)));
        arg_reg3 = vm->arena[(car->position + car->step) % MEM_SIZE];
        // printf("%i\n", val);
        // printf("%i\n", arg_reg3);
        set_reg(car, arg_reg3, val, 1);
    }
    car->position = get_pos(car, get_arg_step(els, 3, DIR_SIZE / 2));
    // printf("%i\n", car->position);
    // printf("%i\n", car->carry);
    car->step = 1;
}