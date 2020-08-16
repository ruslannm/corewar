/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:18:50 by rgero             #+#    #+#             */
/*   Updated: 2020/08/16 20:23:54 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	find_label(t_parser *parser, char *str)
{
	int i;

	i = 0;
	while (i < parser->array_info[LABELS][ARRAY_SIZE])
	{
		if (!ft_strcmp(parser->labels[i]->content, str))
		{
			parser->array_info[LABELS][ARRAY_INDEX] = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

t_op_tab	*find_op(char *name)
{
	int	i;

	i = -1;
	while (++i < OP_TAB_SIZE)
	{
		if (!ft_strcmp(g_op_tab[i].name, name))
			return (&g_op_tab[i]);
	}
	return (NULL);
}

void	replace_link(t_parser *parser)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < parser->array_info[LABELS][ARRAY_SIZE])
	{
		if (parser->labels[i]->op_pos == -1)
			link_error(parser, parser->labels[i], i);
		else
		{
			j = -1;
			while (++j < parser->array_info[LINKS][ARRAY_SIZE])
			{
				if (i == parser->links[j]->label_index)
				{
					k = parser->labels[i]->op_pos - parser->links[j]->op_pos;
					parser->tokens[parser->links[j]->token_index]->number = k;
					int32_to_int8(parser->code, parser->links[j]->pos, k,
						parser->links[j]->size);
				}
			}
		}
	}
}

