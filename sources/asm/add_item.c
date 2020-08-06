/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:29:16 by rgero             #+#    #+#             */
/*   Updated: 2020/08/06 17:13:06 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void add_token(t_parser *parser, t_token *token)
{
	t_token	**new;
	unsigned int 	i;

	if (parser->tokens_size[1] + 1 > parser->tokens_size[0])
	{
		if ((parser->tokens_size[0] *= 2) > MAX_ARR)
			terminate(parser, "Memory accocation");
		if (!(new = (t_token**)ft_memalloc(sizeof(t_token*) *\
			parser->tokens_size[0])))
			terminate(parser, "Memory accocation");
		i = -1;
		while (++i < parser->tokens_size[1])
			new[i] = parser->tokens[i];
		free(parser->tokens);
		parser->tokens = new;
	}
	parser->tokens[parser->tokens_size[1]++] = token;
}