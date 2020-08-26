/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:44:55 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:25:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*ft_lstnew(int position, int id)
{
	t_car *lnew;

	if (!(lnew = ft_calloc(1, sizeof(t_car))))
		ft_error("Error in malloc", "ft_lstnew", 3);
	else
	{
		lnew->position = position;
		lnew->id = id;
		lnew->regist[0] = -id;
		lnew->step = 1;
	}
	return (lnew);
}
