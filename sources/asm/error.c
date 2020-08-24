/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:11:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/23 20:37:16 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_type[] = {
	"COMMAND_NAME",
	"COMMAND_COMMENT",
	"STRING",
	"LABEL",
	"INSTRUCTION",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"ENDLINE",
	"END"
};

void		token_error(t_parser *parser, t_token *token, char *row, int i)
{
	if (token->type == ENDLINE)
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s\n",
			token->row, token->column + 1, g_type[token->type]);
	else if (token->type == SEPARATOR)
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s \"%c\"\n",
			token->row, token->column + 1, g_type[token->type], SEPARATOR_CHAR);
	else if (token->type == END && parser->tokens[i - 1]->type != ENDLINE)
		token_end_error(parser, token);
	else
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s \"%s\"\n",
			token->row, token->column + 1, g_type[token->type], token->content);
	if (row)
	{
		if (token)
		{
			ft_strdel(&(token->content));
			free(token);
		}
		ft_strdel(&row);
	}
	exit_func(parser, -1);
}

void		command_error(t_parser *parser, const char *command, int len)
{
	ft_printf("Champion %s too long (Max length %u)\n", command, len);
	exit_func(parser, -1);
}

void		instruction_error(t_parser *parser, t_token *token)
{
	ft_printf("Invalid instruction at token [TOKEN][%03u:%03u] \
			INSTRUCTION \"%s\"\n",
			token->row, token->column + 1, token->content);
	exit_func(parser, -1);
}

void		arg_type_error(t_parser *parser, t_token *token, int arg_num,
		t_op_tab *op)
{
	int	i;

	ft_printf("Invalid parameter %d type ", arg_num);
	i = -1;
	while (g_type[token->type][++i] != '\0')
		ft_printf("%c", ft_tolower(g_type[token->type][i]));
	ft_printf(" for instruction %s\n", op->name);
	exit_func(parser, -1);
}

void		link_error(t_parser *parser, t_label *label, int label_index)
{
	int j;
	int token_index;

	ft_printf("No such label %s while attempting to dereference token [TOKEN]"\
		, label->content);
	j = -1;
	while (++j < parser->array_info[LINKS][ARRAY_SIZE])
	{
		if (label_index == parser->links[j]->label_index)
		{
			token_index = parser->links[j]->token_index;
			ft_printf("[%03u:%03u] %s \"%s\"\n",
				parser->tokens[token_index]->row,
				parser->tokens[token_index]->column + 1,
				g_type[parser->tokens[token_index]->type],
				parser->tokens[token_index]->content);
			break ;
		}
	}
	exit_func(parser, -1);
}
