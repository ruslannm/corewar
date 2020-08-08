/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:23:34 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 12:39:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	find_end_str(t_parser *parser, const char *row)
{
	unsigned i;

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

static void	update_row(t_parser *parser, char **row, char *ptr)
{
	char *new;

	if (!(new = ft_strdup(ptr)))
		terminate(parser, ERR_MEMORY, "update_row");
	ft_strdel(row);
	*row = new;
}

void	parse_command_str(t_parser *parser,	char **row,	t_token *token)
{
	unsigned int start;
	char	*end;
	ssize_t	size;
	char	*str;

	start = parser->column;
	size = 1;
	while (!(end = ft_strchr(&((*row)[start + 1]), '\"'))
		&& (size = get_next_line_asm(parser->fd, &str)) > 0)
		*row = join_str(parser, row, &str);
	find_end_str(parser, *row);
	if (size == -1)
		terminate(parser, ERR_READ, "parse_command_str");
	if (size == 0)
		lexical_error(parser);
	if (!(token->content = ft_strsub(*row, start, end + 1 - &((*row)[start]))))
		terminate(parser, ERR_MEMORY, "parse_command_str");
	if (end - parser->column != *row)
		update_row(parser, row, end - parser->column);
	parser->column++;
	add_token(parser, token);
}

void	parse_command(t_parser *parser,	char *row,	t_token *token)
{
	unsigned int start;

	start = parser->column;
	while (row[parser->column]
		&&  0 == is_delimiter(row[parser->column]))
		parser->column++;
	if (!(token->content = ft_strsub(row, start, parser->column - start)))
		terminate(parser, ERR_MEMORY, "parse_command");
	add_token(parser, token);
}
