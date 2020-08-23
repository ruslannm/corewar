/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/23 20:27:24 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_tokens(t_parser *parser, t_token **tokens)
{
	int		i;

	if (tokens)
	{
		i = 0;
		while (i < parser->array_info[TOKENS][ARRAY_SIZE])
		{
			if (tokens[i])
			{
				ft_strdel(&(tokens[i]->content));
				free(tokens[i]);
				tokens[i] = NULL;
			}
			i++;
		}
		free(tokens);
	}
	tokens = NULL;
}

static void	free_labels(t_parser *parser, t_label **labels)
{
	int		i;

	if (labels)
	{
		i = 0;
		while (i < parser->array_info[LABELS][ARRAY_SIZE])
		{
			if (labels[i])
			{
				ft_strdel(&labels[i]->content);
				free(labels[i]);
				labels[i] = NULL;
			}
			i++;
		}
		free(labels);
	}
	labels = NULL;
}

static void	free_links(t_parser *parser, t_link **links)
{
	int		i;

	if (links)
	{
		i = 0;
		while (i < parser->array_info[LINKS][ARRAY_SIZE])
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
	if (parser)
	{
		free_tokens(parser, parser->tokens);
		free_labels(parser, parser->labels);
		free_links(parser, parser->links);
		ft_strdel(&parser->code);
		ft_strdel(&parser->name);
		ft_strdel(&parser->comment);
		ft_strdel(&parser->buff);
		free(parser);
		if (error)
			exit(error);
	}
	else
		exit(error);
}
