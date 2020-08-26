# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 13:38:10 by lnickole          #+#    #+#              #
#    Updated: 2020/08/26 22:48:08 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

DIR_SRC		= sources
DIR_OBJ 	= objects
DIR_INC 	= includes

SRC_LIST	= ft_abs.c ft_atoi.c ft_bzero.c ft_free_array.c ft_intlen.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c\
			ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
			ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
			ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_reverse_bits_64.c ft_str_secure_del.c\
			ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
			ft_strequ.c ft_string_array_delete.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnlen.c ft_strnstr.c ft_strrchr.c\
			ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strtrim_char.c ft_strtrim_chars.c\
			ft_swap.c ft_tolower.c ft_toupper.c get_next_line.c

HEADERS		= libft.h get_next_line.h

SRC			= $(addprefix $(DIR_SRC)/, $(SRC_LIST))
OBJ			= $(addprefix $(DIR_OBJ)/, $(SRC_LIST:.c=.o))
INC			= $(addprefix $(DIR_INC)/, $(HEADERS))

FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJ) $(INC)
	@ar rc $(NAME) $(OBJ)
	@echo $(NAME) -\> Build done!

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@gcc -c -I $(DIR_INC) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(DIR_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re