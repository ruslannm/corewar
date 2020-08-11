/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:49:57 by rgero             #+#    #+#             */
/*   Updated: 2020/08/11 18:15:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int	ft_atoi32(const char *str, long long modul)
{
	int	i;
	int	sign;
	long long ret;

	ret = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		ret *= 10;
		ret += str[i++] - 48;
		if (1 == sign && ret > modul - 1)
			return (ret % modul);
		if (-1 == sign && ret > modul)
			return (modul - ret % modul);
	}
	return (sign == -1 ? modul - ret : ret);
}
