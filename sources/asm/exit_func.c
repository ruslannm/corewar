/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/15 13:19:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_tokens(t_token **tokens)
{
	int		i;

	if (tokens)
	{
		i = 0;
		while (tokens[i])
		{
			if (tokens[i])
			{
				free(tokens[i]->content);
				free(tokens[i]->op_tab);
				free(tokens[i]);
				tokens[i] = NULL;
			}
			i++;
		}
		free(tokens);
	}
	tokens = NULL;
}

static void	free_labels(t_label **labels)
{
	int		i;

	if (labels)
	{
		i = 0;
		while (labels[i])
		{
			if (labels[i])
			{
				free(labels[i]->content);
				free(labels[i]);
				labels[i] = NULL;
			}
			i++;
		}
		free(labels);
	}
	labels = NULL;
}

static void	free_links(t_link **links)
{
	int		i;

	if (links)
	{
		i = 0;
		while (links[i])
		{
			if (links[i])
			{
				free(links[i]);
				links[i] = NULL;
			}
			i++;
		}
		free(links);
	}
	links = NULL;
}

void		terminate(t_parser *parser, const char *error_info,
						const char *func)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(error_info, 2);
	ft_putstr_fd(" in function ", 2);
	ft_putendl_fd(func, 2);
	exit_func(parser, -1);
}

void		exit_func(t_parser *parser, int error)
{
	if (!parser)
	{
		free_tokens(parser->tokens);
		free_labels(parser->labels);
		free_links(parser->links);
		free(parser->code);
		free(parser->name);
		free(parser->comment);
		free(parser);
		exit(error);
	}
	exit(error);
}
