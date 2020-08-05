/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlong_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:16:27 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/24 13:32:15 by adisco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		pf_check_base(char *base)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] <= ' ' || base[i] > '~' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static void			pf_print(size_t nbr, size_t len, char *base, t_data *data)
{
	if (nbr < len)
		fill_buffer(data, &base[nbr], 1);
	else
	{
		pf_print((nbr) / len, len, base, data);
		pf_print((nbr) % len, len, base, data);
	}
}

void				pf_putlong_base(size_t nbr, char *base, t_data *data)
{
	size_t		len;

	len = pf_check_base(base);
	if (len > 1)
		pf_print(nbr, len, base, data);
}
