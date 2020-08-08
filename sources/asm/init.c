/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:16:41 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 21:35:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*init_token(t_parser *parser, token_type type)
{
	t_token	*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		terminate(parser, ERR_MEMORY, "init_token");
	token->content = NULL;
	token->type = type;
	token->row = parser->row;
	if (type == SEPARATOR || type == NEW_LINE)
		token->column = parser->column - 1;
	else
		token->column = parser->column;
	return (token);
}

t_label		*init_label(t_parser *parser, char **content)
{
	t_label	*label;

	if (!(label = (t_label *)malloc(sizeof(t_label))))
	{
		ft_strdel(content);
		terminate(parser, ERR_MEMORY, "init_label");
	}
	label->content = *content;
	label->op_pos = parser->op_pos;
	return (label);
}

unsigned int *init_label_links(t_parser *parser, unsigned int capacity)
{
	unsigned int *new_label_links;
	unsigned int i;
	
	if (!(new_label_links = (unsigned int*)malloc(sizeof(unsigned int) *\
			capacity)))
			terminate(parser, ERR_MEMORY, "init_label_links");
	i = 0;
	while (i < capacity)
	{
		new_label_links[i] = -1;
		i++;
	}	
	return (new_label_links);
}