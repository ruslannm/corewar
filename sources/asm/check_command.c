/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:27:44 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 21:49:00 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_info(t_parser *parser, const char *command,
						int max_len, unsigned int i)
{
	int		len;
	char	*str;

	str = NULL;
	if (parser->tokens[i]->type == STRING)
	{
		len = ft_strlen(parser->tokens[i]->content);
		if (len - 2 > max_len)
			command_error(parser, command, max_len);
		if (!(str = ft_strsub(parser->tokens[i]->content,
					1, len - 2)))
			terminate(parser, ERR_MEMORY, "get_info");
	}
	else
		token_error(parser, parser->tokens[i], NULL, i);
	return (str);
}

void		check_command(t_parser *parser, int i)
{
	while ((!parser->name || !parser->comment)
		&& i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		if (parser->tokens[i]->type == END)
			token_error(parser, parser->tokens[i], NULL, i);
		else if (parser->tokens[i]->type == COMMAND_NAME && !parser->name
		&& (parser->array_info[TOKENS][ARRAY_INDEX] = ++i))
			parser->name = get_info(parser, "name", PROG_NAME_LENGTH, i);
		else if (parser->tokens[i]->type == COMMAND_COMMENT && !parser->comment
		&& (parser->array_info[TOKENS][ARRAY_INDEX] = ++i))
			parser->comment = get_info(parser, "comment", COMMENT_LENGTH, i);
		else if (parser->tokens[i]->type == ENDLINE
		&& (parser->array_info[TOKENS][ARRAY_INDEX] = ++i))
			continue;
		else
			token_error(parser, parser->tokens[i], NULL, i);
		parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		if (parser->tokens[i]->type != ENDLINE)
			token_error(parser, parser->tokens[i], NULL, i);
	}
}
