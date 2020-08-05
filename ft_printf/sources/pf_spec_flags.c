/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:57:52 by adisco            #+#    #+#             */
/*   Updated: 2020/07/15 23:00:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <string.h>
#include "pf_spec_flags.h"

void	pf_init_spec_flags(t_spec_flags *sf)
{
	sf->l = 0;
	sf->h = 0;
	sf->l_upper = 0;
	sf->z = 0;
	sf->j = 0;
	return ;
}

void	pf_upd_spec_flags(t_spec_flags *sf, char c)
{
	sf->l += (c == 'l') ? 1 : 0;
	sf->h += (c == 'h') ? 1 : 0;
	sf->l_upper += (c == 'L') ? 1 : 0;
	sf->z += (c == 'z') ? 1 : 0;
	sf->j += (c == 'j') ? 1 : 0;
}

int		pf_get_size(t_spec_flags sf)
{
	size_t		s1;
	intmax_t	s2;
	int			result;

	result = 0;
	if (sf.l == 0 && sf.h == 0)
		result = 4;
	else if (sf.l >= 1)
		result = 8;
	else if (sf.h == 1)
		result = 2;
	else if (sf.h == 2)
		result = 1;
	if (sf.z != 0)
		result = sizeof(s1);
	if (sf.j != 0)
		result = sizeof(s2);
	if (sf.l_upper >= 1)
		result = 16;
	return (result);
}
