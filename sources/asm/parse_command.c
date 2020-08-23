/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:23:34 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 21:20:54 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			find_end_str(t_parser *parser, const char *row)
{
	unsigned		i;

	i = ++(parser->column);
	while (row[i] && row[i] != '\"')
	{
		if (row[i] == '\n')
		{
			parser->row++;
			parser->column = 0;
		}
		else
			parser->column++;
		i++;
	}
}

static void			update_row(t_parser *parser, char **row, char *ptr)
{
	char			*new;

	if (!(new = ft_strdup(ptr)))
	{
		ft_strdel(row);
		terminate(parser, ERR_MEMORY, "update_row");
	}
	ft_strdel(row);
	*row = new;
}

void				parse_command_str(t_parser *parser,
										char **row, t_token *token)
{
	unsigned int	start;
	char			*end;
	ssize_t			size;
	char			*str;

	start = parser->column;
	size = 1;
	while (!(end = ft_strchr(&((*row)[start + 1]), '\"'))
		&& (size = get_next_line_asm(parser->fd, &str, parser)) > 0)
		*row = join_str(parser, row, &str);
	find_end_str(parser, *row);
	if (size == -1)
		terminate(parser, ERR_READ, "parse_command_str");
	if (size == 0)
		lexical_error(parser, token, *row);
	if (!(token->content = ft_strsub(*row, start, end + 1 - &((*row)[start]))))
		terminate(parser, ERR_MEMORY, "parse_command_str");
	if (end - parser->column != *row)
		update_row(parser, row, end - parser->column);
	parser->column++;
	add_token(parser, token);
}

void				parse_command(t_parser *parser, char *row, t_token *token)
{
	int				len;

	len = ft_strlen(row + parser->column);
	if (len > 4 && 0 == ft_strncmp(NAME_CMD_STRING, row + parser->column, 5))
	{
		if (!(token->content = ft_strdup(NAME_CMD_STRING)))
			terminate(parser, ERR_MEMORY, "parse_command");
		token->type = COMMAND_NAME;
		parser->column += 5;
	}
	else if (len > 7 && 0 == ft_strncmp(COMMENT_CMD_STRING,
										row + parser->column, 8))
	{
		if (!(token->content = ft_strdup(COMMENT_CMD_STRING)))
			terminate(parser, ERR_MEMORY, "parse_command");
		token->type = COMMAND_COMMENT;
		parser->column += 8;
	}
	else
		lexical_error(parser, token, row);
	add_token(parser, token);
}

void				parse_endline(t_parser *parser)
{
	int				i;

	i = parser->array_info[TOKENS][ARRAY_SIZE];
	if (i >= 1 && parser->tokens[i - 1]->type == ENDLINE)
	{
		parser->tokens[i - 1]->row = parser->row;
		parser->tokens[i - 1]->column = parser->column - 1;
	}
	else
		add_token(parser, init_token(parser, ENDLINE));
}
