/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:15:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/27 13:57:42 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "oper.h"

typedef struct		s_car
{
	int				id;
	unsigned int	step;
	int				regist[REG_NUMBER];
	struct s_car	*next;
	struct s_car	*prev;
	int				last_live_cycle;
	int				cycle_to_action;
	int				code;
	int				position;
	int				carry;
}					t_car;

typedef struct		s_player
{
	char			*name;
	char			*ex_code;
	size_t			ex_size;
	int				flag_n;
	int				id;
	char			*comment;
}					t_player;

typedef struct		s_players
{
	t_player		**arr;
	int32_t			dump_num;
	int8_t			dump_size;
	int				size;
	int				iter;
	int				is_aff;
}					t_players;

typedef struct		s_vm
{
	unsigned char	arena[MEM_SIZE];
	int				cycle_to_die;
	t_players		players;
	int				id_car;
	int				num_car;
	t_car			*carry;
	int				count_check;
	int				count_live;
	int				iter;
	t_op			operations;
	int				win_id;
	int				cur_cycle;
	int				dump_value;
	int				dump_size;
	int				is_aff;
}					t_vm;

typedef struct		s_pars
{
	char			**av;
	int				ac;
	int				i;
	int				fd;
	int				dump_flag;
}					t_pars;

#endif
