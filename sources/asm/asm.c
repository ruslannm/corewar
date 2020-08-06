/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/06 22:15:37 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser*)ft_memalloc(sizeof(t_parser))))
		terminate(NULL, "memory allocation in init_parser");
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
		terminate(NULL, "memory allocation in init_parser");
	if (!(parser->label_links = (int*)ft_memalloc(sizeof(int) *\
		parser->tokens_size[0])))
		terminate(NULL, "memory allocation in init_parser");
	parser->labels_size[0] = MIN_ARR;
	parser->labels_size[1] = 0;
	if (!(parser->labels = (t_label**)ft_memalloc(sizeof(t_label*) *\
		parser->labels_size[0])))
		terminate(NULL, "memory allocation in init_parser");
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
			terminate(NULL, "Can\'t open file with champion in main");
	}
	else if (argc == 1) //for debug
		fd = open(filename, O_RDONLY);  //for debug
	else
	{
		ft_printf("Usage: ./asm mychampion.s\n");
		return (0);
	}
	parser = init_parser(fd);
	read_file(parser);
//	filename = replace_extension(parser, argv[1]);
	filename = replace_extension(parser, filename);
	
//		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(parser, "Can\'t create file in main");
 DEBUG_print_tokens(parser);
	write_file(fd, parser);
	return (0);
}
