/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:16:41 by rgero             #+#    #+#             */
/*   Updated: 2020/08/05 22:14:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*init_token(t_parser *parser, token_type type)
{
	t_token	*token;

	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		terminate(parser, "Can\'t initialize token");
	token->content = NULL;
	token->type = type;
	token->row = parser->row;
	if (type == SEPARATOR || type == NEW_LINE)
		token->column = parser->column - 1;
	else
		token->column = parser->column;
	return (token);
}