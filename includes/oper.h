/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:27:42 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 16:37:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPER_H
# define OPER_H

# include "corewar.h"
# include "vm.h"

typedef struct s_vm	t_vm;

typedef struct s_car	t_car;

typedef struct	s_args
{
	int			first;
	int			second;
	int			third;
	int			f_val;
	int			s_val;
	int			t_val;
}				t_args;

typedef struct	s_op
{
	int			op_cycles[16];
	t_args		arg;
}				t_op;

void			set_oper(t_vm *vm);
void			oper_func(t_vm *vm, t_car *car, t_args *arg, int i);
void			o_live(t_vm *vm, t_car *car, t_args *arg);
int				get_pos(t_car *car, int position);
int				read_4_bytes(t_vm *vm, int position);
void			o_ld(t_vm *vm, t_car *car, t_args *arg);
int				check_arg(int arg);
int16_t			read_2_bytes(t_vm *vm, int position);
int				get_arg_step(int args, int num, int dir_size);
void			set_reg(t_car *car, int reg, int value, int f);
void			o_st(t_vm *vm, t_car *car, t_args *arg);
int				def_arg(unsigned char code, unsigned inx);
unsigned char	read_1_byte(t_vm *vm, int position);
void			relocate(t_car *car, t_args *args, int type);
int				check_reg(t_vm *vm, t_car *car, int code, int *arg);
void			plus_minus(t_vm *vm, t_car *car, t_args *arg, int type);
void			o_add(t_vm *vm, t_car *car, t_args *arg);
void			o_sub(t_vm *vm, t_car *car, t_args *arg);
void			o_add(t_vm *vm, t_car *car, t_args *arg);
void			write_to_reg(t_vm *vm, t_car *car, int result, int third);
void			o_or(t_vm *vm, t_car *car, t_args *arg);
int				get_dir_4(t_vm *vm, t_car *car, int sw_arg, int *arg);
int				get_dir_2(t_vm *vm, t_car *car, int sw_arg, int *arg);
void			o_and(t_vm *vm, t_car *car, t_args *arg);
void			o_xor(t_vm *vm, t_car *car, t_args *arg);
void			o_zjmp(t_vm *vm, t_car *car, t_args *arg);
int				get_arg_n(t_vm *vm, t_car *car, int arg);
void			o_ldi(t_vm *vm, t_car *car, t_args *arg);
int				valid_args(t_vm *vm, t_car *car, int args);
int				invalid_reg(t_vm *vm, t_car *car, int args, int num);
void			o_sti(t_vm *vm, t_car *car, t_args *arg);
int				get_third(t_vm *vm, t_car *car, int arg, int *val);
t_car			*cp_car(t_car *main, int position, int id);
void			o_fork(t_vm *vm, t_car *car, t_args *arg);
void			o_lld(t_vm *vm, t_car *car, t_args *arg);
void			o_lldi(t_vm *vm, t_car *car, t_args *arg);
void			o_lfork(t_vm *vm, t_car *car, t_args *arg);
void			o_aff(t_vm *vm, t_car *car, t_args *arg);

#endif
