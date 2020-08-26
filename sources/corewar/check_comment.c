/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:01:16 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:54:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_comment(t_pars *pars, t_players *players)
{
	char	buf[COMMENT_LENGTH + 1];
	char	*comment;
	int32_t	ln;

	if ((read(pars->fd, buf, COMMENT_LENGTH)) != COMMENT_LENGTH)
		ft_error("Size of the champ is invalid", "check_comment", 2);
	buf[COMMENT_LENGTH] = '\0';
	ln = ft_strlen(buf);
	comment = ft_calloc(ln + 1, sizeof(char));
	comment[ln] = '\0';
	ft_memcpy(comment, buf, ln);
	players->arr[players->iter]->comment = comment;
	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("Null's octet is invalid", "check_comment", 2);
}
