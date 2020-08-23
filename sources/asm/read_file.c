/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/23 20:26:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	skip_whitespaces(t_parser *parser, const char *row)
{
	while (find_strchr(WHITESPACES, row[parser->column]))
		parser->column++;
}

static void	skip_comment(t_parser *parser, const char *row)
{
	if (row[parser->column] == COMMENT_CHAR
	|| row[parser->column] == ALT_COMMENT_CHAR)
		while (row[parser->column] && row[parser->column] != '\n')
			parser->column++;
}

void		read_file(t_parser *parser)
{
	int		size;
	char	*row;

	while (++(parser->row) && !(parser->column = 0) &&
		(size = get_next_line_asm(parser->fd, &row, parser)) > 0)
	{
		while (row[parser->column])
		{
			skip_whitespaces(parser, row);
			skip_comment(parser, row);
			if (row[parser->column])
				parse_token(parser, &row);
		}
		ft_strdel(&row);
	}
	add_token(parser, init_token(parser, END));
	if (size < 0)
		terminate(parser, ERR_READ, "read_file");
	parser->array_info[TOKENS][ARRAY_INDEX] = 0;
	parser->array_info[LABELS][ARRAY_INDEX] = 0;
	check_command(parser, 0);
	check_code(parser, parser->array_info[TOKENS][ARRAY_INDEX]);
}
