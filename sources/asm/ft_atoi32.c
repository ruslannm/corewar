/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:49:57 by rgero             #+#    #+#             */
/*   Updated: 2020/08/15 16:23:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int32_t		ft_atoi32(const char *str)
{
	unsigned long	result;
	unsigned long	border;
	size_t			i;
	int				sign;

	result = 0;
	border = (unsigned long)(FT_LONG_MAX / 10);
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
		&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (str[i] - '0') > 8))
		&& sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int32_t)(result * sign));
}
/*
int main()
{
	char *s = "1985623468534121213213213213213213";
	printf("s=%s, atoi=%d, ft_atoi=%d", s, atoi(s), ft_atoi32(s));
	return (0);
}
*/