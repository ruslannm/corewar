/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:17 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/08 14:55:18 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_left_spaces(t_data *data)
{
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
}

void	put_sign(t_data *data, long nb)
{
	if (data->padding.sign)
	{
		if (nb < 0)
			fill_buffer(data, "-", 1);
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
	}
}

void	put_zeros(t_data *data)
{
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
}

void	put_right_spaces(t_data *data)
{
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}
