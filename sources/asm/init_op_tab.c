/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:15:32 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/10 17:33:46 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_op_tab(t_parser *parser)
{
	if (!(parser->orig_op_tab[0] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[0]->name = ft_strdup("live")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[0]->name = "live";
	parser->orig_op_tab[0]->code = 0x01;
	parser->orig_op_tab[0]->args_num = 1;
	parser->orig_op_tab[0]->args_types_code = 0;
	parser->orig_op_tab[0]->args_types[0] = T_DIR;
	parser->orig_op_tab[0]->args_types[1] = 0;
	parser->orig_op_tab[0]->args_types[2] = 0;
	parser->orig_op_tab[0]->t_dir_size = 4;
	if (!(parser->orig_op_tab[1] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[1]->name = ft_strdup("ld")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[1]->name = "ld";
	parser->orig_op_tab[1]->code = 0x02;
	parser->orig_op_tab[1]->args_num = 2;
	parser->orig_op_tab[1]->args_types_code = 1;
	parser->orig_op_tab[1]->args_types[0] = T_DIR | T_IND;
	parser->orig_op_tab[1]->args_types[1] = T_REG;
	parser->orig_op_tab[1]->args_types[2] = 0;
	parser->orig_op_tab[1]->t_dir_size = 4;
	if (!(parser->orig_op_tab[2] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[2]->name = ft_strdup("st")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[2]->name = "st";
	parser->orig_op_tab[2]->code = 0x03;
	parser->orig_op_tab[2]->args_num = 2;
	parser->orig_op_tab[2]->args_types_code = 1;
	parser->orig_op_tab[2]->args_types[0] = T_REG;
	parser->orig_op_tab[2]->args_types[1] = T_REG | T_IND;
	parser->orig_op_tab[2]->args_types[2] = 0;
	parser->orig_op_tab[2]->t_dir_size = 4;
	if (!(parser->orig_op_tab[3] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[3]->name = ft_strdup("add")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[3]->name = "add";
	parser->orig_op_tab[3]->code = 0x04;
	parser->orig_op_tab[3]->args_num = 3;
	parser->orig_op_tab[3]->args_types_code = 1;
	parser->orig_op_tab[3]->args_types[0] = T_REG;
	parser->orig_op_tab[3]->args_types[1] = T_REG;
	parser->orig_op_tab[3]->args_types[2] = T_REG;
	parser->orig_op_tab[3]->t_dir_size = 4;
	if (!(parser->orig_op_tab[4] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[4]->name = ft_strdup("sub")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[4]->name = "sub";
	parser->orig_op_tab[4]->code = 0x05;
	parser->orig_op_tab[4]->args_num = 3;
	parser->orig_op_tab[4]->args_types_code = 1;
	parser->orig_op_tab[4]->args_types[0] = T_REG;
	parser->orig_op_tab[4]->args_types[1] = T_REG;
	parser->orig_op_tab[4]->args_types[2] = T_REG;
	parser->orig_op_tab[4]->t_dir_size = 4;
	if (!(parser->orig_op_tab[5] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[5]->name = ft_strdup("and")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[5]->name = "and";
	parser->orig_op_tab[5]->code = 0x06;
	parser->orig_op_tab[5]->args_num = 3;
	parser->orig_op_tab[5]->args_types_code = 1;
	parser->orig_op_tab[5]->args_types[0] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[5]->args_types[1] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[5]->args_types[2] = T_REG;
	parser->orig_op_tab[5]->t_dir_size = 4;
	if (!(parser->orig_op_tab[6] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[6]->name = ft_strdup("or")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[6]->name = "or";
	parser->orig_op_tab[6]->code = 0x07;
	parser->orig_op_tab[6]->args_num = 3;
	parser->orig_op_tab[6]->args_types_code = 1;
	parser->orig_op_tab[6]->args_types[0] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[6]->args_types[1] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[6]->args_types[2] = T_REG;
	parser->orig_op_tab[6]->t_dir_size = 4;
	if (!(parser->orig_op_tab[7] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[7]->name = ft_strdup("xor")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[7]->name = "xor";
	parser->orig_op_tab[7]->code = 0x08;
	parser->orig_op_tab[7]->args_num = 3;
	parser->orig_op_tab[7]->args_types_code = 1;
	parser->orig_op_tab[7]->args_types[0] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[7]->args_types[1] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[7]->args_types[2] = T_REG;
	parser->orig_op_tab[7]->t_dir_size = 4;
	if (!(parser->orig_op_tab[8] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[8]->name = ft_strdup("zjmp")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[8]->name = "zjmp";
	parser->orig_op_tab[8]->code = 0x09;
	parser->orig_op_tab[8]->args_num = 1;
	parser->orig_op_tab[8]->args_types_code = 0;
	parser->orig_op_tab[8]->args_types[0] = T_DIR;
	parser->orig_op_tab[8]->args_types[1] = 0;
	parser->orig_op_tab[8]->args_types[2] = 0;
	parser->orig_op_tab[8]->t_dir_size = 2;
	if (!(parser->orig_op_tab[9] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[9]->name = ft_strdup("ldi")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[9]->name = "ldi";
	parser->orig_op_tab[9]->code = 0x0A;
	parser->orig_op_tab[9]->args_num = 3;
	parser->orig_op_tab[9]->args_types_code = 1;
	parser->orig_op_tab[9]->args_types[0] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[9]->args_types[1] = T_REG | T_DIR;
	parser->orig_op_tab[9]->args_types[2] = T_REG;
	parser->orig_op_tab[9]->t_dir_size = 2;
	if (!(parser->orig_op_tab[10] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[10]->name = ft_strdup("sti")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[10]->name = "sti";
	parser->orig_op_tab[10]->code = 0x0B;
	parser->orig_op_tab[10]->args_num = 3;
	parser->orig_op_tab[10]->args_types_code = 1;
	parser->orig_op_tab[10]->args_types[0] = T_REG;
	parser->orig_op_tab[10]->args_types[1] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[10]->args_types[2] = T_REG | T_DIR;
	parser->orig_op_tab[10]->t_dir_size = 2;
	if (!(parser->orig_op_tab[11] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[11]->name = ft_strdup("fork")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[11]->name = "fork";
	parser->orig_op_tab[11]->code = 0x0C;
	parser->orig_op_tab[11]->args_num = 1;
	parser->orig_op_tab[11]->args_types_code = 0;
	parser->orig_op_tab[11]->args_types[0] = T_DIR;
	parser->orig_op_tab[11]->args_types[1] = 0;
	parser->orig_op_tab[11]->args_types[2] = 0;
	parser->orig_op_tab[11]->t_dir_size = 2;
	if (!(parser->orig_op_tab[12] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[12]->name = ft_strdup("lld")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[12]->name = "lld";
	parser->orig_op_tab[12]->code = 0x0D;
	parser->orig_op_tab[12]->args_num = 2;
	parser->orig_op_tab[12]->args_types_code = 0;
	parser->orig_op_tab[12]->args_types[0] = T_DIR | T_IND;
	parser->orig_op_tab[12]->args_types[1] = T_REG;
	parser->orig_op_tab[12]->args_types[2] = 0;
	parser->orig_op_tab[12]->t_dir_size = 4;
	if (!(parser->orig_op_tab[13] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[13]->name = ft_strdup("lldi")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[13]->name = "lldi";
	parser->orig_op_tab[13]->code = 0x0E;
	parser->orig_op_tab[13]->args_num = 3;
	parser->orig_op_tab[13]->args_types_code = 1;
	parser->orig_op_tab[13]->args_types[0] = T_REG | T_DIR | T_IND;
	parser->orig_op_tab[13]->args_types[1] = T_REG | T_DIR;
	parser->orig_op_tab[13]->args_types[2] = T_REG;
	parser->orig_op_tab[13]->t_dir_size = 2;
	if (!(parser->orig_op_tab[14] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[14]->name = ft_strdup("lfork")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[14]->name = "lfork";
	parser->orig_op_tab[14]->code = 0x0F;
	parser->orig_op_tab[14]->args_num = 1;
	parser->orig_op_tab[14]->args_types_code = 0;
	parser->orig_op_tab[14]->args_types[0] = T_DIR;
	parser->orig_op_tab[14]->args_types[1] = 0;
	parser->orig_op_tab[14]->args_types[2] = 0;
	parser->orig_op_tab[14]->t_dir_size = 2;
	if (!(parser->orig_op_tab[15] = (t_op_tab*)malloc(sizeof(t_op_tab))))
		terminate(parser, ERR_MEMORY, "init_op_tab");
	if (!(parser->orig_op_tab[15]->name = ft_strdup("aff")))
		terminate(parser, ERR_MEMORY, "init_op_tab");
//	parser->orig_op_tab[15]->name = "aff";
	parser->orig_op_tab[15]->code = 0x10;
	parser->orig_op_tab[15]->args_num = 1;
	parser->orig_op_tab[15]->args_types_code = 1;
	parser->orig_op_tab[15]->args_types[0] = T_REG;
	parser->orig_op_tab[15]->args_types[1] = 0;
	parser->orig_op_tab[15]->args_types[2] = 0;
	parser->orig_op_tab[15]->t_dir_size = 4;
}
