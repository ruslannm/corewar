/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:11:17 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/21 21:01:09 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_sign(char *str)
{
	if ((*str >= '0' && *str <= '9')
			|| (*str == '+' && (str[1] >= '0' && str[1] <= '9')))
		return (1);
	if (*str == '-' && (str[1] >= '0' && str[1] <= '9'))
		return (-1);
	return (0);
}

static long	proceed(char *str, int sign)
{
	long	res;
	long	prev;
	long	diff;

	res = 0;
	prev = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		diff = (sign > 0) ? (*str - '0') : ('0' - *str);
		res = 10L * prev + diff;
		if (sign > 0 && res < prev)
			return (-1);
		if (sign < 0 && res > prev)
			return (0);
		prev = res;
		str++;
	}
	return (res);
}

int			pf_atoi(const char *str)
{
	char	*tmp;
	int		sign;

	tmp = (char *)str;
	while ((*tmp == '\n' || *tmp == '\t' || *tmp == '\v'
				|| *tmp == '\r' || *tmp == ' ' || *tmp == '\f') ? 1 : 0)
		tmp++;
	sign = get_sign(tmp);
	if (!sign)
		return (0);
	return ((int)proceed(tmp, sign));
}

long double	pf_round_prec(long double nb, int prec)
{
	long		ipart;
	long double	rest;
	long double	correction;
	long double	shift;
	long double	result;

	ipart = (long)nb;
	result = (long double)ipart;
	rest = nb - result;
	shift = power(10., prec + 1);
	if (nb > 0)
		correction = (rest * shift + (5.l * shift - 1.l) / shift) / shift;
	else
		correction = (rest * shift - (5.l * shift - 1.l) / shift) / shift;
	result += (correction < 1. && correction > -1.) ? rest : correction;
	return (result);
}
