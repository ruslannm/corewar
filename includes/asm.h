/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/08 11:33:37 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include "asm_error.h"

# define MAX_ARR		1000000
# define MIN_ARR		1000
# define COMMAND_CHAR	'.'
# define REGISTER_CHAR	'r'
# define WHITESPACES	"\t\v\f\r "

typedef enum
{
	COMMAND,
	COMMAND_STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE
}	token_type;

typedef struct			s_token
{
	char				*content;
	token_type			type;
	unsigned int		row;
	unsigned int		column;
}						t_token;

typedef struct			s_link
{
	unsigned			row;
	unsigned			column;
	int32_t				pos;
	int32_t				op_pos;
	size_t				size;
}						t_link;

typedef struct			s_label
{
	char				*content;
	int32_t				op_pos;
	t_link				**links;
}						t_label;

/*
**   tokens_size, label_size: 0 - max size, 1 - current size
*/

typedef struct	s_parser
{
	int					fd;
	unsigned int		row;
	unsigned int		column;
	t_token				**tokens;
	int					*label_links;
	unsigned int		tokens_size[2];
	int32_t				pos;
	int32_t				op_pos;
	char				*name;
	char				*comment;
	char				*code;
	int32_t				code_size;
	t_label				**labels;
	unsigned int		labels_size[2];
}						t_parser;


void terminate(t_parser *parser, const char *error_info, const char *func);
void	exit_func(t_parser *parser, int error);
int		get_next_line_asm(const int fd, char **line);
int 	is_filename(const char *filename);
char	*replace_extension(t_parser * parser, const char *filename);
void		read_file(t_parser *parser);
void	write_file(int fd, t_parser *parser);
void	parse_token(t_parser *parser, char **row);
void 	add_token(t_parser *parser, t_token *token);
t_token		*init_token(t_parser *parser, token_type type);
int		is_delimiter(const char c);
int		is_register(const char *str);
char	*join_str(t_parser *parser, char **str1, char **str2);
void	lexical_error(t_parser *parser);
void	parse_command(t_parser *parser,	char *row,	t_token *token);
void	parse_command_str(t_parser *parser,	char **row,	t_token *token);
void	parse_operator(t_parser *parser, char *row,	t_token *token);
void	parse_direct_label(t_parser *parser, char *row,	t_token *token);
void	parse_direct_nbr(t_parser *parser,	char *row,	t_token *token);

char	*get_str(t_parser *parser, const char *row, unsigned start);

//void	write_to_file(t_parser * parser, const char *filename); // create and write commands to file *.cor

//int lexer(char *filename);
//int is_kword(char *id);
//int add_token(struct token *tok);

//delete. only for debug
void DEBUG_print_tokens(t_parser *parser);

#endif
