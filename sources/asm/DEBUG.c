/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:52:20 by rgero             #+#    #+#             */
/*   Updated: 2020/08/09 21:24:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// only for debug

#include "asm.h"

void DEBUG_print_tokens(t_parser *parser)
{
	int i;
	
	ft_printf("\nprint_tokens\n");
	i = 0;
	while (i < parser->array_info[TOKENS][ARRAY_SIZE])
	{
		ft_printf("%d|", i);
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

void DEBUG_print_labels(t_parser *parser)
{
	int i;
	
	ft_printf("\nprint_labels\n");
	i = -1;
	while (++i < parser->array_info[LABELS][ARRAY_SIZE])
	{
			ft_printf("%d - op_pos = %d, %s\n", i, parser->labels[i]->op_pos, parser->labels[i]->content);
	}
	ft_printf("end print_label\n\n");
}

void DEBUG_print_links(t_parser *parser)
{
	int i;
	
	ft_printf("\nprint_links\n");
	i = -1;
	while (++i < parser->array_info[LINKS][ARRAY_SIZE])
	{
			ft_printf("%d - label_index=%d, row=%u, col=%u, pos=%d, op_pos = %d, size=%d\n", i, 
			parser->links[i]->label_index,
			parser->links[i]->row,
			parser->links[i]->column,
			parser->links[i]->pos,
			parser->links[i]->op_pos,
			parser->links[i]->size);
	}
	ft_printf("end print_links\n\n");
}
