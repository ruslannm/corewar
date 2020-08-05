/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:27:01 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 22:41:23 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	sign;
	char	*str;

	i = 0;
	sign = 0;
	if (n == 0 || n == -2147483648)
		return (n ? ft_strdup("-2147483648") : ft_strdup("0"));
	str = n < 0 ? ft_strnew(ft_intlen(-n) + 1) : ft_strnew(ft_intlen(n));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign > 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
