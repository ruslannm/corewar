/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/09 07:32:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void terminate(t_parser *parser, const char *error_info, const char *func)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(error_info, 2);
	ft_putstr_fd(" in function ", 2);
	ft_putendl_fd(func, 2);
	exit_func(parser, 1);
}

void		exit_func(t_parser *parser, int error)
{
	if (!parser)
	{
		exit(error);
	}
	exit(error);
}
