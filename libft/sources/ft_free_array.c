/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:06:38 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 18:06:39 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_array(char **array, int ret_val)
{
	int i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array && *array)
		free(array);
	return (ret_val);
}
