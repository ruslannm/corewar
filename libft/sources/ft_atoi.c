/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:26:56 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 22:27:06 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	result;
	size_t					i;
	size_t					sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 0 && str[i] <= 32) && (str[i] != 27) && (str[i] != '\0'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (i > 19 || result > 2147483647)
		return (sign == 1 ? -1 : 0);
	return (result * sign);
}
