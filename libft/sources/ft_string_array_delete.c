/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_delete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:03:22 by lnickole          #+#    #+#             */
/*   Updated: 2020/03/01 17:03:24 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_string_array_delete(char ***as)
{
	char	**as1;

	if (!as || !(*as))
		return ;
	as1 = *as;
	while (*as1)
		ft_str_secure_del(as1++);
	free(*as);
	*as = NULL;
}
