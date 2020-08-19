/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:29:16 by rgero             #+#    #+#             */
/*   Updated: 2020/08/19 23:16:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_max_capacity(t_parser *parser, int type)
{
	int		test;
	int		current;
	int		step;

	current = parser->array_info[type][ARRAY_SIZE];
	step = (type == CODE ? 10 : 1);
	if (current + step > parser->array_info[type][ARRAY_CAPACITY])
	{
		test = current * 2;
		if (test / 2 != current)
			terminate(parser, ERR_MEMORY, "check_max_capacity");
		parser->array_info[type][ARRAY_CAPACITY] = test;
		return (test);
	}
	return (0);
}

void		add_token(t_parser *parser, t_token *token)
{
	t_token	**new;
	int		i;

	if (check_max_capacity(parser, TOKENS))
	{
		if (!(new = (t_token**)malloc(sizeof(t_token*) *\
			parser->array_info[TOKENS][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_token");
		i = -1;
		while (++i < parser->array_info[TOKENS][ARRAY_SIZE])
			new[i] = parser->tokens[i];
		free(parser->tokens);
		parser->tokens = new;
	}
	parser->tokens[parser->array_info[TOKENS][ARRAY_SIZE]++] = token;
}

void		add_label(t_parser *parser, t_label *label)
{
	t_label	**new;
	int		i;

	if (check_max_capacity(parser, LABELS))
	{
		if (!(new = (t_label**)malloc(sizeof(t_label*) *\
			parser->array_info[LABELS][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_label");
		i = -1;
		while (++i < parser->array_info[LABELS][ARRAY_SIZE])
			new[i] = parser->labels[i];
		free(parser->labels);
		parser->labels = new;
	}
	parser->array_info[LABELS][ARRAY_INDEX] =
		parser->array_info[LABELS][ARRAY_SIZE];
	parser->labels[parser->array_info[LABELS][ARRAY_SIZE]++] = label;
}

void		add_link(t_parser *parser, t_link *link)
{
	t_link	**new;
	int		i;

	if (check_max_capacity(parser, LINKS))
	{
		if (!(new = (t_link**)malloc(sizeof(t_link*) *\
			parser->array_info[LINKS][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_label");
		i = -1;
		while (++i < parser->array_info[LINKS][ARRAY_SIZE])
			new[i] = parser->links[i];
		free(parser->links);
		parser->links = new;
	}
	parser->array_info[LINKS][ARRAY_INDEX] =
		parser->array_info[LINKS][ARRAY_SIZE];
	parser->links[parser->array_info[LINKS][ARRAY_SIZE]++] = link;
}

void		add_code_capacity(t_parser *parser)
{
	if (check_max_capacity(parser, CODE))
	{
		if (!(parser->code = (char *)realloc(parser->code,
			parser->array_info[CODE][ARRAY_CAPACITY])))
			terminate(parser, ERR_MEMORY, "add_code_capacity");
	}
}
