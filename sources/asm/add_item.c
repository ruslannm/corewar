/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:29:16 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 09:15:24 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void add_token(t_parser *parser, t_token *token)
{
	t_token	**new_tokens;
	int *new_label_links;
	unsigned int 	i;

	if (parser->tokens_size[1] + 1 > parser->tokens_size[0])
	{
		if ((parser->tokens_size[0] *= 2) > MAX_ARR)
			terminate(parser, ERR_MEMORY, "add_token");
		if (!(new_tokens = (t_token**)ft_memalloc(sizeof(t_token*) *\
			parser->tokens_size[0])))
			terminate(parser, ERR_MEMORY, "add_token");
		if (!(new_label_links = (int*)ft_memalloc(sizeof(int) *\
			parser->tokens_size[0])))
			terminate(parser, ERR_MEMORY, "add_token");
		i = -1;
		while (++i < parser->tokens_size[1])
		{
			new_tokens[i] = parser->tokens[i];
			new_label_links[i] = parser->label_links[i];
		}
		free(parser->tokens);
		free(parser->label_links);
		parser->tokens = new_tokens;
		parser->label_links = new_label_links;
	}
	parser->tokens[parser->tokens_size[1]++] = token;
}