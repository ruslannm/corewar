/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/05 15:46:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum
{
	LABEL,
	OPER,
	REG,
	DIR,
	DIR_LABEL,
	IND,
	IND_LABEL,
	SEP,
	NEW_LINE
}	token_type;

typedef struct			s_token
{
	char				*content;
	token_type			type;
	unsigned int		row;
	unsigned int		column;
	struct s_token		*next;
}						t_token;

typedef struct			s_link
{
	unsigned			row;
	unsigned			column;
	int32_t				pos;
	int32_t				op_pos;
	size_t				size;
	struct s_mention	*next;
}						t_link;



typedef struct			s_label
{
	char				*content;
	int32_t				op_pos;
	t_link				*links;
	struct s_label		*next;
}						t_label;

typedef struct	s_parser
{
	int					fd;
	unsigned			row;
	unsigned			column;
	t_token				*tokens;
	int32_t				pos;
	int32_t				op_pos;
	char				*name;
	char				*comment;
	char				*code;
	int32_t				code_size;
	t_label				*labels;
}						t_parser;


void		exit_func(t_parser *parser, char *func_name, int error);
int		get_next_line_asm(const int fd, char **line);
int 	is_filename(const char *filename);
char	*replace_extension(t_parser * parser, const char *filename);

//int lexer(char *filename);
//int is_kword(char *id);
//int add_token(struct token *tok);

#endif
