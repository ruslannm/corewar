/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/06 17:30:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void terminate(t_parser *parser, char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(str, 2);
	exit_func(parser, 1);
	/*
	if (error == 1)
		ft_printf("Memory allocation error in function \"%s\"\n", func_name);
	if (error == 2)
		ft_printf("Error with opening file in \"%s\"\n", func_name);
	if (error == 3)
		ft_printf("I can't create a file in \"%s\"\n", func_name);
*/
	//TODO print for other errors
}

void		exit_func(t_parser *parser, int error)
{
	if (!parser)
	{
		exit(error);
	}
	exit(error);
}
