/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:52:20 by rgero             #+#    #+#             */
/*   Updated: 2020/08/09 17:45:05 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// only for debug

#include "asm.h"

void DEBUG_print_tokens(t_parser *parser)
{
	unsigned int i;
	ft_printf("\nprint_tokens\n");
	i = 0;
	while (i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		if (parser->tokens[i]->type == NEW_LINE)
			ft_printf("NEW_LINE/%d\n", parser->tokens[i]->type);
		else if (parser->tokens[i]->type == SEPARATOR)
			ft_printf("SEPARATOR/%d -> ", parser->tokens[i]->type);
		else 
			ft_printf("%s/%d -> ", parser->tokens[i]->content, parser->tokens[i]->type);
		++i;
	}
	ft_printf("end print_tokens\n\n");
}