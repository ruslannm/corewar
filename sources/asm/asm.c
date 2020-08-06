/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/06 17:23:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser*)ft_memalloc(sizeof(t_parser))))
		terminate(NULL, "Can\'t initialize parser");
	parser->fd = fd;
	parser->row = 0;
	parser->column = 0;
	parser->pos = 0;
	parser->op_pos = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code = NULL;
	parser->code_size = 0;
	parser->tokens_size[0] = MIN_ARR;
	parser->tokens_size[1] = 0;
	if (!(parser->tokens = (t_token**)ft_memalloc(sizeof(t_token*) *\
		parser->tokens_size[0])))
		terminate(NULL, "Can\'t initialize parser");
	parser->labels_size[0] = MIN_ARR;
	parser->labels_size[1] = 0;
	if (!(parser->labels = (t_label**)ft_memalloc(sizeof(t_label*) *\
		parser->labels_size[0])))
		terminate(NULL, "Can\'t initialize parser");
	return (parser);
}

int				main(int argc, char **argv)
{
	int fd;
	t_parser	*parser;
	char *filename;

	fd = 0;
	filename = ft_strdup("rgero.s");
	if (argc == 2)
	{
		if (-1 == (fd = open(argv[1], O_RDONLY)))
			terminate(NULL, "Can\'t open file with champion");
	}
	else if (argc == 1) //for debug
		fd = open(filename, O_RDONLY);  //for debug

	parser = init_parser(fd);
	read_file(parser);
//	filename = replace_extension(parser, argv[1]);
	filename = replace_extension(parser, filename);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(parser, "Can\'t create file");
	write_file(fd, parser);
	if (argc == 2) {
		if (-1 == (fd = open(argv[1], O_RDONLY)))
			exit_func(NULL, "main" , 2);
		parser = init_parser(fd);
		read_file(parser);
		filename = replace_extension(parser, argv[1]);
		write_to_file(parser, filename);

/*		if (solution(m))
			result(m);
		else
			exit_func(m, 1);
		exit_func(m, 0);
*/
	}
	else if (argc > 2)
		ft_printf("Usage: ./asm mychampion.s\n");
	else
		ft_printf("Usage: ./asm mychampion.s\n");
	return (0);
}
