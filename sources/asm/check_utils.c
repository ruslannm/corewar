/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:18:50 by rgero             #+#    #+#             */
/*   Updated: 2020/08/09 17:25:59 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*find_label(t_parser *parser, char *str)
{
	unsigned int i;

	i = 0;
	
	while (i < parser->array_info[LABELS][ARRAY_SIZE])
	{
		if (!ft_strcmp(parser->labels[i]->content, str))
			return (parser->labels[i]);
		i++;
	}
	return (NULL);
}

t_op_tab	*find_op(t_parser *parser, char *name)
{
	unsigned	i;

	i = 0;
	while (i < OP_TAB_SIZE)
	{
		if (!ft_strcmp(parser->orig_op_tab[i]->name, name))
			return (parser->orig_op_tab[i]);
		i++;
	}
	return (NULL);
}