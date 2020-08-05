/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:08:29 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/24 12:23:11 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pf_spec_flags.h"

void	parse_options(const char *s, int *i, t_data *data)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == ' '
			|| s[*i] == '0')
	{
		if (s[*i] == '-')
			data->left = 1;
		else if (s[*i] == '+')
			data->plus = 1;
		else if (s[*i] == ' ')
			data->space = 1;
		else if (s[*i] == '#')
			data->sharp = 1;
		else if (s[*i] == '0')
			data->zero = 1;
		(*i)++;
	}
}

void	parse_l_min(const char *s, int *i, t_data *data)
{
	int	nb;

	if (s[*i] >= '1' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->l_min = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
}

void	parse_prec(const char *s, int *i, t_data *data)
{
	int	nb;

	while (s[*i] == '.')
		(*i)++;
	if (s[*i] >= '0' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->prec = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
	else if (s[*i] == '*')
	{
		data->prec = va_arg(data->ap, int);
		if (data->prec < 0)
			data->prec = -1;
		(*i)++;
	}
	else
		data->prec = 0;
}

void	parse_size(const char *s, int *i, t_data *data)
{
	t_spec_flags	sf;

	pf_init_spec_flags(&sf);
	while (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == 'L')
	{
		pf_upd_spec_flags(&sf, s[*i]);
		(*i)++;
	}
	data->size = pf_get_size(sf);
}

void	parse_wildcard(int *i, t_data *data)
{
	data->l_min = va_arg(data->ap, int);
	if (data->l_min < 0)
	{
		data->left = 1;
		data->l_min = -data->l_min;
	}
	(*i)++;
}
