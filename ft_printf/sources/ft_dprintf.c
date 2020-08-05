/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:04:52 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/08 15:03:11 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, fd);
	va_start(data.ap, format);
	parse_format(format, &data);
	write(fd, data.buffer, data.i);
	va_end(data.ap);
	return (data.ret);
}
