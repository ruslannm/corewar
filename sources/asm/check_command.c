/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:27:44 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 21:14:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char *get_info(t_parser *parser, const char *command, int max_len, unsigned int i)
{
	int len;
	char *str;	

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
		token_error(parser, parser->tokens[i]);
	return (str);
}

void		check_command(t_parser *parser, unsigned int i)
{
	while ((!parser->name || !parser->comment)
		&& i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		if (parser->tokens[i]->type == COMMAND	&& !parser->name
			&& 0 == ft_strcmp(parser->tokens[i]->content, NAME_CMD_STRING))
		{
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
			parser->name = get_info(parser, "name", PROG_NAME_LENGTH, i);
		}
		else if (parser->tokens[i]->type == COMMAND	&& !parser->comment
			&& 0 == ft_strcmp(parser->tokens[i]->content, COMMENT_CMD_STRING))
		{
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
			parser->comment = get_info(parser, "comment", COMMENT_LENGTH, i);
		}
		else if (parser->tokens[i]->type == NEW_LINE)
		{
			parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
			continue;
		}
		else
			token_error(parser, parser->tokens[i]);
		parser->array_info[TOKENS][ARRAY_INDEX] = ++i;
		if (parser->tokens[i]->type != NEW_LINE)
			token_error(parser, parser->tokens[i]);
	}
}
