/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:17:28 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:20:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*ft_calloc(size_t elem, size_t size_elem)
{
	void	*pt;
	size_t	size;

	size = elem * size_elem;
	pt = malloc(size);
	if (pt)
		ft_memset(pt, 0, size);
	return (pt);
}
