# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 13:33:55 by lnickole          #+#    #+#              #
#    Updated: 2020/08/26 22:52:26 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAKEFILE = Makefile

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes
BIN_DIR = .

SRC_LIST = pf_putchar.c pf_putstr.c ft_printf.c pf_putnbr.c pf_putunbr.c \
		  pf_putaddr.c pf_putnbr_base.c pf_invalid.c pf_putpercent.c \
		  pf_putlong_base.c parse_flags.c pf_atoi.c put_padding.c pf_putfloat.c\
		  pf_strnequ.c parse_colors.c base_utils.c pf_float_padding.c \
		  putfloat_utils.c parse_functions.c ft_dprintf.c pf_spec_flags.c

HEADERS = ft_printf.h put_padding.h color.h base_utils.h pf_spec_flags.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_LIST:.c=.o))
INC = $(addprefix $(INC_DIR)/, $(HEADERS))

CFLAGS = -g3 -O3 -Wall -Wextra -Werror -I $(INC_DIR)

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
YELLOW := "\033[0;33m"
RESET :="\033[0m"

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${GREEN}"[INFO] Created libftprintf.a successfully!"${RESET}

clean: 
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@#echo ${CYAN}"[INFO] Removed [$(OBJ)] with success!"${RESET}
	@#echo ${CYAN}"[INFO] Removed [$(OBJ_DIR)/] with success!"${RESET}

fclean: clean
	@rm -Rf $(NAME)
	@rm -Rf ft_printf
	@#echo ${CYAN}"[INFO] Removed everything"${RESET}

re: fclean all

.PHONY: all clean fclean re
