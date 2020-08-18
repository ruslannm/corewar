/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:11:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 09:39:22 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lexical_error(t_parser *parser)
{
	ft_printf("Lexical error at [%u:%u]\n",
		parser->row,
		parser->column + 1);
	exit_func(parser, -1);
}

void	token_end_error(t_parser *parser, t_token *token)
{
	if (token->type == END)
		ft_printf("Syntax error - unexpected end of input"
					" (Perhaps you forgot to end with a newline ?)\n");
	exit_func(parser, -1);
}
