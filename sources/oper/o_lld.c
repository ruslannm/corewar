/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 08:07:35 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/20 19:25:42 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void o_lld(t_vm *vm, t_car *car, t_args *arg)
{
    int els;
    int arg_reg;

    (void)arg->first;
    els = vm->arena[(car->position + 1) % MEM_SIZE];
    if (check_arg(els) == DIR_CODE && check_arg(els << 2) == REG_CODE)
    {
        arg_reg = vm->arena[(car->position + 6) % MEM_SIZE];
        // printf("%i\n", arg_reg);
        if (arg_reg > 0 && arg_reg <= REG_NUMBER)
            set_reg(car, arg_reg, read_4_bytes(vm, (car->position + 2) % MEM_SIZE), 1);
    }
    else if (check_arg(els) == IND_CODE && check_arg(els << 2) == REG_CODE)
    {
        arg_reg = vm->arena[(car->position + 4) % MEM_SIZE];
        // printf("%i\n", arg_reg);
        if (arg_reg > 0 && arg_reg <= REG_NUMBER)
            set_reg(car, arg_reg, read_2_bytes(vm, get_pos(car, read_2_bytes(vm, \
            (car->position + 2) % MEM_SIZE))), 1);
    }
    // printf("%i\n", car->carry);
    car->position = get_pos(car, get_arg_step(els, 2, DIR_SIZE));
    // printf("%i\n", car->position);
}