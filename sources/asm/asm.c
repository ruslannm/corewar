/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/05 15:50:20 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		read_file(t_parser *parser)
{
	char *line;

	while (get_next_line_asm(parser->fd, &line) > 0)
	{
		ft_printf("%s" , line);
		free(line);
	}
}

static t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser*)ft_memalloc(sizeof(t_parser))))
		exit_func(NULL, "init_parser", 1);
	parser->fd = fd;
	return (parser);
}

int				main(int argc, char **argv)
{
	int fd;
	t_parser	*parser;
	char *filename;

	fd = 0;
	if (argc == 2)
	{
		if (-1 == (fd = open(argv[1], O_RDONLY)))
			ft_printf("Error \n");
	}
	parser = init_parser(fd);
	read_file(parser);
	filename = replace_extension(parser, argv[1]);

/*	if (solution(m))
		result(m);
	else
		exit_func(m, 1);
	exit_func(m, 0);
*/
	return (0);
}
