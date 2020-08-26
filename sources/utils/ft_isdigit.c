/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:43:59 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 20:20:22 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
