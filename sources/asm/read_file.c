/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/08 19:39:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void skip_whitespaces(t_parser * parser, const char *row)
{
	while (ft_strchr(WHITESPACES, row[parser->column]))
		parser->column++;
}

void	skip_comment(t_parser *parser, const char *row)
{
	if (row[parser->column] == COMMENT_CHAR)
		while (row[parser->column] && row[parser->column] != '\n')
			parser->column++;
}

void		read_file(t_parser *parser)
{
	int size;
	char *row;

	while (++(parser->row) && !(parser->column = 0) &&
		(size = get_next_line_asm(parser->fd, &row)) > 0)
	{
//if (parser->row > 2) break;
		while (row[parser->column])
		{
			skip_whitespaces(parser, row);
			skip_comment(parser, row);
			if (row[parser->column])
				parse_token(parser, &row);
		}
		ft_strdel(&row);
	}
	if (size < 0)
		terminate(parser, ERR_READ, "read_file");
	parser->tokens_size[ARRAY_INDEX] = 0;
	check_command(parser, 0);
}
