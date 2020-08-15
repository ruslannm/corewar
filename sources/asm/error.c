/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:11:37 by rgero             #+#    #+#             */
/*   Updated: 2020/08/15 20:43:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lexical_error(t_parser *parser)
{
	ft_printf("Lexical error at [%u:%u]\n",
													parser->row,
													parser->column + 1);
	exit_func(parser, -1);
}

void	token_error(t_parser *parser, t_token *token)
{
	char	*type[] = {
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
		"END"};
	
	if (token->type == NEW_LINE)
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s\n",
			token->row,	token->column + 1, type[token->type]);
	else if (token->type == SEPARATOR)
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s \"%c\"\n",
			token->row,	token->column + 1, type[token->type], SEPARATOR_CHAR);
	else
		ft_printf("Syntax error at token [TOKEN][%03u:%03u] %s \"%s\"\n",
			token->row,	token->column + 1, type[token->type], token->content);
	exit_func(parser, -1);
}

void	command_error(t_parser *parser, const char *command, int len)
{
	ft_printf( "Champion %s too long (Max length %u)\n", command, len);
	exit_func(parser, -1);
}

void	instruction_error(t_parser *parser, t_token *token)
{
	ft_printf("Invalid instruction at token [TOKEN][%03u:%03u] INSTRUCTION \"%s\"\n",
		token->row,	token->column + 1, token->content);	
	exit_func(parser, -1);
}

void	arg_type_error(t_parser *parser, t_token *token, int arg_num, t_op_tab *op)
{
	char	*type[] = {
		"command_name",
		"command_comment",
		"string",
		"label",
		"operator",
		"register",
		"direct",
		"direct_label",
		"indirect",
		"indirect_label",
		"separator",
		"new_line"};

	ft_printf("Invalid parameter %d type %s for instruction %s\n", arg_num,
		type[token->type],	op->name);	
//	ft_printf("Invalid parameter %d type for instruction %s\n", arg_num,
//		type[token->type],	op->name);	

	exit_func(parser, -1);
}

void	link_error(t_parser * parser, t_label *label)
{
	char	*type[] = {
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
			"END"};
	int i;

	i = find_token(parser, ft_strjoin(":", label->content));
//	ft_printf("i %d\n", i);
//	ft_printf("%s\n", parser->tokens[i]->content);
//	ft_printf("%03u\n", parser->tokens[i]->row);
//	ft_printf("%03u\n", parser->tokens[i]->column);
//	ft_printf("%s\n", type[parser->tokens[i]->type]);
	ft_printf("No such label %s while attempting to dereference token [TOKEN][%03u:%03u] %s \":%s\"\n",
		   label->content, parser->tokens[i]->row, parser->tokens[i]->column + 1, type[parser->tokens[i]->type], label->content);
	exit_func(parser, -1);
}
