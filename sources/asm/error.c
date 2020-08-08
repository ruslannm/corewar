/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:11:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 19:45:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lexical_error(t_parser *parser)
{
	ft_printf("Lexical error at [%u:%u]\n",
													parser->row,
													parser->column + 1);
	exit_func(parser, 1);
}

void	token_error(t_parser *parser, t_token *token)
{
	char	*type[] = {
		"COMMAND",
		"STRING",
		"LABEL",
		"OPERATOR",
		"REGISTER",
		"DIRECT",
		"DIRECT_LABEL",
		"INDIRECT",
		"INDIRECT_LABEL",
		"SEPARATOR",
		"NEW_LINE"};
	
	ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s \"%s\"",
		token->row,	token->column + 1, type[token->type], token->content);
	exit_func(parser, 1);
}

void	command_error(t_parser *parser, const char *command, int len)
{
	ft_printf( "Champion %s too long (Max length %u)\n", command, len);
	exit_func(parser, 1);
}
