/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 21:03:25 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 21:08:51 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		len--;
		i++;
	}
	return (str);
}
