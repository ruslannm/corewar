/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:24:37 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/11 22:36:40 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = (char *)malloc(sizeof(*mem) * size);
	if (mem != NULL)
	{
		return (ft_memset(mem, 0, size));
	}
	else
	{
		return (NULL);
	}
}
