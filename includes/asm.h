/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/25 15:38:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include "asm_error.h"

# define ARRAY_CAPACITY_MIN		1024
# define OP_TAB_SIZE			16
# define COMMAND_CHAR			'.'
# define REGISTER_CHAR			'r'
# define WHITESPACES			"\t\v\f\r "

typedef enum	e_type
{
	COMMAND_NAME,
	COMMAND_COMMENT,
	STRING,
	LABEL,
	INSTRUCTION,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	ENDLINE,
	END
}				t_type;

enum
{
	ARRAY_CAPACITY,
	ARRAY_SIZE,
	ARRAY_INDEX
};

enum
{
	TOKENS,
	LABELS,
	LINKS,
	CODE
};

typedef struct		s_op_tab
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	int				args_types_code;
	uint8_t			args_types[3];
	uint8_t			t_dir_size;
}					t_op_tab;

typedef struct		s_token
{
	char			*content;
	t_type			type;
	unsigned int	row;
	unsigned int	column;
	int32_t			op_pos;
	int8_t			type_code;
	int32_t			number;
	int				arg_len[3];
	t_op_tab		*op_tab;
}					t_token;

typedef struct		s_link
{
	int				token_index;
	int				label_index;
	int32_t			pos;
	int32_t			op_pos;
	size_t			size;

}					t_link;

typedef struct		s_label
{
	char			*content;
	int32_t			op_pos;
}					t_label;

/*
**  array_info: 0 - ARRAY_CAPACITY (memory allocated for array)
**				1 - ARR_SIZE (current size),
**				2 - ARR_INDEX
*/

typedef struct		s_parser
{
	int				fd;
	unsigned int	row;
	unsigned int	column;
	t_token			**tokens;
	t_label			**labels;
	t_link			**links;
	int				array_info[4][3];
	char			*code;
	int32_t			pos;
	int32_t			op_pos;
	char			*name;
	char			*comment;
	char			*buff;
	int				having_ins;
}					t_parser;

void				terminate(t_parser *parser, const char *error_info,
					const char *func);
void				exit_func(t_parser *parser, int error);

int					get_next_line_asm(const int fd, char **line,
					t_parser *parser);
int					is_filename(const char *filename);
char				*replace_extension(t_parser *parser, const char *filename);
void				read_file(t_parser *parser);

void				write_file(int fd, t_parser *parser);
void				int32_to_int8(char *str, int32_t pos, int32_t value,
					size_t size);
int8_t				get_types_len(t_token *token, int8_t type_code);
void				write_standart_output(t_parser *parser);

void				parse_token(t_parser *parser, char **row);
void				add_token(t_parser *parser, t_token *token);
void				add_label(t_parser *parser, t_label *label);
void				add_link(t_parser *parser, t_link *link);
void				add_code_capacity(t_parser *parser);

t_token				*init_token(t_parser *parser, t_type type);
t_label				*init_label(t_parser *parser, char **content, int op_pos,
					int token_index);
t_link				*init_link(t_parser *parser, int token_index, size_t size);

int					find_label(t_parser *parser, char *str);
t_op_tab			*find_op(char *name);

int					find_strchr(const char *s, int c);
int					is_delimiter(const char c);
int					is_register(const char *str);
char				*join_str(t_parser *parser, char **str1, char **str2);

void				lexical_error(t_parser *parser, t_token *token, char *row);
void				command_error(t_parser *parser, const char *command,
					int len);
void				token_error(t_parser *parser, t_token *token, char *row,
					int i);
void				token_end_error(t_parser *parser, t_token *token);
void				instruction_error(t_parser *parser, t_token *token);
void				arg_type_error(t_parser *parser, t_token *token,
					int arg_num, t_op_tab *op);
void				link_error(t_parser *parser, t_label *label,
					int label_index);
void				parse_command(t_parser *parser, char *row, t_token *token);
void				parse_command_str(t_parser *parser, char **row,
					t_token *token);
void				parse_direct_label(t_parser *parser, char *row,
					t_token *token);
void				parse_indirect_label(t_parser *parser, char *row,
					t_token *token);
void				parse_direct_nbr(t_parser *parser, char *row,
					t_token *token);
void				parse_str(t_parser *parser, char *row, t_token *token);
void				parse_endline(t_parser *parser);

void				check_command(t_parser *parser, int i);
void				check_code(t_parser *parser, int i);
int8_t				check_arg(t_parser *parser, int i,
					t_op_tab *op, int arg_num);
void				check_args_error(t_parser *parser, int i, int arg_num,
					t_op_tab *op);
void				replace_link(t_parser *parser);

char				*get_str(t_parser *parser, const char *row,
					unsigned start);
int32_t				ft_atoi32(const char *str);

#endif
