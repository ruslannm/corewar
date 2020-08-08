/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:18:50 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 21:14:50 by rgero            ###   ########.fr       */
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
