/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:46:06 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 09:18:20 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_error(const char *msg, const char *str, int code)
{
	if (str)
	{
		ft_putstr("\e[31mError\e[0m in function ");
		ft_putstr(str);
	}
	if (msg)
	{
		if (!str)
			ft_putstr("\e[31mError\e[0m");
		ft_putstr(": ");
		ft_putstr(msg);
	}
	if (str || msg)
		ft_putchar('\n');
	exit(code);
}
