/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:58:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:20:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

__int64_t	ft_atoi(const char *s)
{
	__int64_t	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' ||\
	s[i] == '\f' || s[i] == '\n')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb * sign);
}
