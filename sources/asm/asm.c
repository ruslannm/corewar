/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/08 21:31:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser*)malloc(sizeof(t_parser))))
		terminate(NULL, ERR_MEMORY, "init_parser");
	parser->fd = fd;
	parser->row = 0;
	parser->column = 0;
	parser->pos = 0;
	parser->op_pos = 0;
	parser->name = NULL;
	parser->comment = NULL;
	if (!(parser->code = (char *)malloc(CHAMP_MAX_SIZE)))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->code_size = 0;
	parser->array_info[TOKENS][ARRAY_CAPACITY] = ARRAY_CAPACITY_MIN;
	parser->array_info[TOKENS][ARRAY_SIZE] = 0;
	if (!(parser->tokens = (t_token**)malloc(sizeof(t_token*) *\
		parser->array_info[TOKENS][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->label_links = init_label_links(parser,
		parser->array_info[TOKENS][ARRAY_CAPACITY]);
	parser->array_info[LABELS][ARRAY_CAPACITY] = ARRAY_CAPACITY_MIN;
	parser->array_info[LABELS][ARRAY_SIZE] = 0;
	if (!(parser->labels = (t_label**)malloc(sizeof(t_label*) *\
		parser->array_info[LABELS][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	if (!(parser->orig_op_tab = (t_op_tab**)ft_memalloc(sizeof(t_op_tab*) * 16)))
		terminate(parser, ERR_MEMORY, "init_parser");
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
			terminate(NULL, ERR_OPEN, "main");
	}
	else if (argc == 1) //for debug
		fd = open(filename, O_RDONLY);  //for debug
	else
	{
		ft_printf("Usage: ./asm mychampion.s\n");
		return (0);
	}
	parser = init_parser(fd);
	init_op_tab(parser);
	read_file(parser);
//	filename = replace_extension(parser, argv[1]);
	filename = replace_extension(parser, filename);
	
//		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(parser, ERR_CREATE, "main");
 DEBUG_print_tokens(parser);
	write_file(fd, parser);
	return (0);
}
