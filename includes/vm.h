/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:15:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:28:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "oper.h"

typedef struct s_car
{
	int id;
	unsigned int step;  /*количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции*/
	int regist[REG_NUMBER];
	struct s_car *next;
	struct s_car *prev;
	int last_live_cycle; /*цикл, в котором в последний раз была выполнена операция live*/
	int cycle_to_action; /*количество циклов до исполнения операции*/
	int code; /*код операции*/
	int position; /*позиция каретки*/
	int carry;
}				t_car;

typedef struct s_player
{
	char *name;
	char *ex_code;
	size_t ex_size;
	int flag_n;
	int id;
	char *comment;
}				t_player;

typedef struct s_players
{
	t_player	**arr;
	int32_t dump_num;
	int8_t  dump_size;
	int size;
	int iter;
}		t_players;

typedef struct s_vm
{
	unsigned char	arena[MEM_SIZE];
	int cycle_to_die;
	t_players	players;
	int id_car;
	int num_car;
	t_car *carry;
	int count_check; 
	int count_live; /*Количество операций live*/
	int iter; /* количество циклов, прошедших после старта*/
	t_op  operations;
	int win_id;
	int cur_cycle;
	int dump_value;
	int dump_size;
}						t_vm;

typedef struct s_pars
{
	char **av;
	int ac;
	int i;
	int fd;
	int     dump_flag;
}				t_pars;

#endif
