/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:17:28 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 09:03:18 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
