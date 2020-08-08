/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:11:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 16:12:53 by rgero            ###   ########.fr       */
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
	
	ft_printf("Unexpected token \"%s\" %s at [%03u:%03u]\n",
														token->content,
														type[token->type],
														token->row,
														token->column + 1);
	exit_func(parser, 1);
}
