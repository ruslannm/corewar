/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:52:20 by rgero             #+#    #+#             */
/*   Updated: 2020/08/06 22:31:49 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// only for debug

#include "asm.h"

void DEBUG_print_tokens(t_parser *parser)
{
	unsigned int i;

	ft_printf("print_tokens\n");
	i = 0;
	while (i < parser->tokens_size[1])
	{
		if (parser->tokens[i]->type == NEW_LINE)
			ft_printf("NEW_LINE\n");
		else if (parser->tokens[i]->type == SEPARATOR)
			ft_printf("separator -> ");
		else 
			ft_printf("%s -> ", parser->tokens[i]->content);
		++i;
	}
}