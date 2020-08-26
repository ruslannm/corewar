# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 22:43:12 by lnoisome          #+#    #+#              #
#    Updated: 2020/08/26 22:50:38 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_LIBFT 			= libft
NAME_LIBFT			= $(DIR_LIBFT)/libft.a
DIR_INC_LIBFT		= $(DIR_LIBFT)/includes

DIR_FT_PRINTF 		= ft_printf
NAME_FT_PRINTF		= $(DIR_FT_PRINTF)/libftprintf.a
DIR_INC_PRINTF		= $(DIR_FT_PRINTF)/includes

GCC_LIBFT 			= -L $(DIR_LIBFT) -lft
GCC_FT_PRINTF		= -L $(DIR_FT_PRINTF) -lftprintf

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

CC = gcc
FLAGS = -Wall -Wextra -Werror

DIR_SRC				= sources
DIR_OBJ 			= objects
DIR_HEADER 			= includes

NAME_ASM = asm
NAME_COREWAR = corewar

DIR_SRC_ASM			= $(DIR_SRC)/$(NAME_ASM)
DIR_OBJ_ASM 		= $(DIR_OBJ)/$(NAME_ASM)

SRC_LIST_ASM 	= 	add_item.c\
					asm.c\
					check_arg.c\
					check_char.c\
					check_command.c\
					check_code.c\
					check_utils.c\
					get_next_line_asm.c\
					error.c\
					error_parse.c\
					exit_func.c\
					init.c\
					files.c\
					find_op.c\
					ft_atoi32.c\
					parse.c\
					parse_command.c\
					parse_operator.c\
					read_file.c\
					utils.c\
					write_output.c\
					write_file.c

HEADERS_ASM			= asm.h asm_error.h op.h

SRC_ASM			= $(addprefix $(DIR_SRC_ASM)/, $(SRC_LIST_ASM))
OBJ_ASM			= $(addprefix $(DIR_OBJ_ASM)/, $(SRC_LIST_ASM:.c=.o))
D_FILES_ASM		= $(addprefix $(DIR_OBJ_ASM)/, $(patsubst %.c, %.d, $(SRC_LIST_ASM)))
HEADER_ASM			= $(addprefix $(DIR_HEADER)/, $(HEADERS_ASM))

DIR_SRC_COREWAR		= $(DIR_SRC)/$(NAME_COREWAR)
DIR_OBJ_COREWAR		= $(DIR_OBJ)/$(NAME_COREWAR)

SRC_LIST_COREWAR = main.c \
		init_data.c \
		ft_error.c \
		init_vm.c \
		parsing.c \
		valid_dump.c \
		valid_n.c \
		valid_id_name.c \
		pars_champ.c \
		check_m_h.c \
		bit_shift.c \
		valid_champ_name.c \
		valid_exec_size.c \
		check_comment.c \
		valid_ex_code.c \
		set_players.c \
		init_carry.c \
		ft_lstnew.c \
		ft_lstadd.c \
		print_start.c \
		free_data.c \
		game.c \
		check_live.c \
		check_carry.c \
		end_dump.c \
		del_fun.c \
		conclusion.c

HEADERS_COREWAR	= corewar.h op.h

SRC_COREWAR	= $(addprefix $(DIR_SRC_COREWAR)/, $(SRC_LIST_COREWAR))
OBJ_COREWAR = $(addprefix $(DIR_OBJ_COREWAR)/, $(patsubst %.c, %.o, $(SRC_LIST_COREWAR)))
D_FILES_COREWAR = $(addprefix $(DIR_OBJ_COREWAR)/, $(patsubst %.c, %.d, $(SRC_LIST_COREWAR)))
HEADER_COREWAR = $(addprefix $(DIR_HEADER)/, $(HEADERS_COREWAR))

NAME_OPER = oper
DIR_SRC_OPER	= $(DIR_SRC)/$(NAME_OPER)
DIR_OBJ_OPER	= $(DIR_OBJ)/$(NAME_OPER)

SRC_LIST_OPER = set_oper.c \
		oper_func.c \
		o_live.c \
		read_4_bytes.c \
		o_ld.c \
		read_2_bytes.c \
		get_set_pos.c \
		check_arg.c \
		def_arg.c \
		relocate.c \
		read_1_byte.c \
		o_st.c \
		check_reg.c \
		o_add.c \
		plus_minus.c \
		o_sub.c \
		o_and.c \
		write_to_reg.c \
		get_arg_dir.c \
		o_or.c \
		o_xor.c \
		o_zjmp.c \
		o_ldi.c \
		valid_args.c \
		get_arg.c \
		o_sti.c \
		get_third.c \
		o_fork.c \
		carret.c \
		o_lldi.c \
		o_lld.c \
		o_lfork.c \
		o_aff.c

HEADERS_OPER	= oper.h

SRC_OPER	= $(addprefix $(DIR_SRC_COREWAR)/, $(SRC_LIST_COREWAR))
OBJ_OPER = $(addprefix $(DIR_OBJ_OPER)/, $(patsubst %.c, %.o, $(SRC_LIST_OPER)))
D_FILES_OPER = $(addprefix $(DIR_OBJ_OPER)/, $(patsubst %.c, %.d, $(SRC_LIST_OPER)))
HEADER_OPER = $(addprefix $(DIR_HEADER)/, $(HEADERS_OPER))

NAME_UTILS = utils
DIR_SRC_UTILS		= $(DIR_SRC)/$(NAME_UTILS)
DIR_OBJ_UTILS		= $(DIR_OBJ)/$(NAME_UTILS)

SRC_LIST_UTILS = ft_strlen.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strequ.c \
		ft_strcmp.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_swap.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_putstr.c \
		print_memory.c \
		del_end.c \
		del_start.c \
		del_midl.c \
		ft_calloc.c  

HEADERS_UTILS	= utils.h

SRC_UTILS	= $(addprefix $(DIR_SRC_COREWAR)/, $(SRC_LIST_COREWAR))
OBJ_UTILS = $(addprefix $(DIR_OBJ_UTILS)/, $(patsubst %.c, %.o, $(SRC_LIST_UTILS)))
D_FILES_UTILS = $(addprefix $(DIR_OBJ_UTILS)/, $(patsubst %.c, %.d, $(SRC_LIST_UTILS)))
HEADER_UTILS = $(addprefix $(DIR_HEADER)/, $(HEADERS_UTILS))

C_COREWAR = $(SRC_COREWAR) $(SRC_UTILS) $(SRC_OPER)
O_COREWAR = $(OBJ_COREWAR) $(OBJ_UTILS) $(OBJ_OPER)
D_ALL = $(D_FILES_COREWAR) \& $(D_FILES_UTILS) \& $(D_FILES_OPER) \& $(D_FILES_ASM)

.PHONY: all clean fclean re

all: $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM): $(DIR_OBJ_ASM) $(OBJ_ASM) $(NAME_LIBFT) $(NAME_FT_PRINTF) $(HEADER_ASM)
	@$(CC) $(FLAGS) $(OBJ_ASM) -o $(NAME_ASM) $(GCC_LIBFT) $(GCC_FT_PRINTF)
	@echo $(GREEN)$(NAME_ASM) -\> Build done!$(RESET)

$(DIR_OBJ_ASM):
	@mkdir -p $(DIR_OBJ_ASM)

$(NAME_LIBFT):
	@make -C $(DIR_LIBFT)/

$(NAME_FT_PRINTF):
	@make -C $(DIR_FT_PRINTF)/

$(DIR_OBJ_ASM)/%.o: $(DIR_SRC_ASM)/%.c $(HEADER_ASM)
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -I $(DIR_INC_LIBFT) -I $(DIR_INC_PRINTF) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(NAME_COREWAR): $(DIR_OBJ_COREWAR) $(DIR_OBJ_UTILS) $(DIR_OBJ_OPER) $(O_COREWAR)
	@$(CC) $(FLAGS) $(O_COREWAR) -o $(NAME_COREWAR)
	@echo $(GREEN)$(NAME_COREWAR) -\> Build done!$(RESET)

$(DIR_OBJ_COREWAR):
	@mkdir -p $(DIR_OBJ_COREWAR)

$(DIR_OBJ_COREWAR)%.o: $(DIR_SRC_COREWAR)%.c
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(DIR_OBJ_UTILS):
	@mkdir -p $(DIR_OBJ_UTILS)

$(DIR_OBJ_UTILS)%.o: $(DIR_SRC_UTILS)%.c
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(DIR_OBJ_OPER):
	@mkdir -p $(DIR_OBJ_OPER)

$(DIR_OBJ_OPER)%.o: $(DIR_SRC_OPER)%.c
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

clean:
	@/bin/rm -rf $(DIR_OBJ)
	@make clean -C $(DIR_LIBFT)/
	@make clean -C $(DIR_FT_PRINTF)/
	@rm -f  $(OBJ_ASM) $(O_COREWAR) $(D_ALL)
	@echo $(RED)Object files was deleted$(RESET)

fclean: clean
	@make fclean -C $(DIR_LIBFT)/
	@make fclean -C $(DIR_FT_PRINTF)/
	@rm -f $(NAME_ASM)
	@echo $(RED)$(NAME_ASM) was deleted$(RESET)
	@rm -f $(NAME_COREWAR)
	@echo $(RED)$(NAME_COREWAR) was deleted$(RESET)

include $(wildcard $(D_ALL))

re: fclean all
