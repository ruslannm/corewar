/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:29:16 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 21:35:17 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void add_token(t_parser *parser, t_token *token)
{
	t_token	**new_tokens;
	unsigned int *new_label_links;
	unsigned int 	i;

	if (!(i = 0) && parser->array_info[TOKENS][ARRAY_SIZE] + 1
		> parser->array_info[TOKENS][ARRAY_CAPACITY])
	{
		if ((parser->array_info[TOKENS][ARRAY_CAPACITY] *= 2)
			> ARRAY_CAPACITY_MAX)
			terminate(parser, ERR_MEMORY, "add_token");
		if (!(new_tokens = (t_token**)malloc(sizeof(t_token*) *\
			parser->array_info[TOKENS][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_token");
		new_label_links = init_label_links(parser, 
			parser->array_info[TOKENS][ARRAY_CAPACITY]);
		while (i < parser->array_info[TOKENS][ARRAY_SIZE])
		{
			new_tokens[i] = parser->tokens[i];
			new_label_links[i] = parser->label_links[i];
			i++;
		}
		free(parser->tokens);
		free(parser->label_links);
		parser->tokens = new_tokens;
		parser->label_links = new_label_links;
	}
	parser->tokens[parser->array_info[TOKENS][ARRAY_SIZE]++] = token;
}

void add_label(t_parser *parser, t_label *label)
{
	t_label	**new_labels;
	unsigned int 	i;

	if (!(i = 0) && parser->array_info[LABELS][ARRAY_SIZE] + 1
		> parser->array_info[LABELS][ARRAY_CAPACITY])
	{
		if ((parser->array_info[LABELS][ARRAY_CAPACITY] *= 2) > ARRAY_CAPACITY_MAX)
			terminate(parser, ERR_MEMORY, "add_label");
		if (!(new_labels = (t_label**)malloc(sizeof(t_label*) *\
			parser->array_info[LABELS][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_label");
		while (i < parser->array_info[LABELS][ARRAY_SIZE])
			new_labels[i] = parser->labels[i];
		free(parser->labels);
		parser->labels = new_labels;
	}
	parser->labels[parser->array_info[LABELS][ARRAY_SIZE]++] = label;

}