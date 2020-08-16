/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/16 20:52:43 by rgero            ###   ########.fr       */
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
		parser->name = NULL;
	parser->comment = NULL;
	parser->array_info[TOKENS][ARRAY_CAPACITY] = ARRAY_CAPACITY_MIN;
	parser->array_info[TOKENS][ARRAY_SIZE] = 0;
	if (!(parser->tokens = (t_token**)malloc(sizeof(t_token*) *\
		parser->array_info[TOKENS][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->array_info[LABELS][ARRAY_CAPACITY] = ARRAY_CAPACITY_MIN;
	parser->array_info[LABELS][ARRAY_SIZE] = 0;
	if (!(parser->labels = (t_label**)malloc(sizeof(t_label*) *\
		parser->array_info[LABELS][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->array_info[LINKS][ARRAY_CAPACITY] = ARRAY_CAPACITY_MIN;
	parser->array_info[LINKS][ARRAY_SIZE] = 0;
	if (!(parser->links = (t_link**)malloc(sizeof(t_link*) *\
		parser->array_info[LINKS][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->array_info[CODE][ARRAY_CAPACITY] = CHAMP_MAX_SIZE;
	if (!(parser->code = (char *)malloc(parser->array_info[CODE][ARRAY_CAPACITY])))
		terminate(parser, ERR_MEMORY, "init_parser");
	parser->pos = 0;
	parser->op_pos = 0;
	if (!(parser->orig_op_tab = (t_op_tab**)malloc(sizeof(t_op_tab*) * OP_TAB_SIZE)))
		terminate(parser, ERR_MEMORY, "init_parser");
	return (parser);
}

static int			get_fd(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc == 3 && ft_strcmp("-a", argv[1]) == 0)
		fd = open(argv[2], O_RDONLY);
	else
	{
		fd = -2;
		ft_printf("Usage: ./asm [-a] <sourcefile.s>\n    -a : Instead of");
    	ft_printf(" creating a .cor file, outputs a stripped and annotated");
		ft_printf(" version of the code to the standard output\n");
	}
	if (-1 == fd)
	ft_printf("Can't read source file %s\n", argv[argc - 1]);
	return (fd);
}

int				main(int argc, char **argv)
{
	int fd;
	t_parser	*parser;
	char *filename;

	if (-1 >= (fd = get_fd(argc, argv)))
		return (0);
	parser = init_parser(fd);
	init_op_tab(parser);
	read_file(parser);
	if (argc == 2)
	{	
		filename = replace_extension(parser, argv[1]);
		//if	((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1) 
		//S_IRUSR | S_IWUSR - запись и чтение только для владельца = 0600
		if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		{
			free(filename);
			terminate(parser, ERR_CREATE, "main");
		}
		write_file(fd, parser);
		ft_printf("Writing output program to %s\n", filename);
	}
	else
		write_standart_output(parser);
	return (0);
}

//for DEBUG only
/*
int	main(int argc, char **argv)
{
	int fd;
	t_parser	*parser;
	char *filename;

//	filename = ft_strdup("./test2/tests/asm/error/param_nonexistent_label.s");
	filename = ft_strdup("./rgero.s");
	fd = get_fd(argc, argv);
	fd = open(filename, O_RDONLY);  //for debug
	parser = init_parser(fd);
	init_op_tab(parser);
	read_file(parser);
	filename = replace_extension(parser, filename);
	
//		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
//	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
	{
		free(filename);
		terminate(parser, ERR_CREATE, "main");
	}

// DEBUG_print_tokens(parser);
 //DEBUG_print_labels(parser);
 //DEBUG_print_links(parser);

	write_standart_output(parser);
//	ft_printf("Writing output program to %s\n", filename);

	return (0);
}
*/