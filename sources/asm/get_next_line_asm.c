/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_asm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:15:32 by lnickole          #+#    #+#             */
/*   Updated: 2020/08/23 15:03:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		newline(t_parser *p, char **line, int fd, int nbread)
{
	char		*temp;
	int			len;

	len = 0;
	while (p->buff[len] != '\n' && p->buff[len] != '\0')
		len++;
	if (p->buff[len] == '\n')
	{
		*line = ft_strsub(p->buff, 0, len + 1);
		temp = ft_strdup(p->buff + len + 1);
		free(p->buff);
		p->buff = temp;
		if (p->buff[0] == '\0')
			ft_strdel(&(p->buff));
	}
	else if (p->buff[len] == '\0')
	{
		if (nbread == BUFF_SIZE)
			return (get_next_line_asm(fd, line, p));
		*line = ft_strdup(p->buff);
		ft_strdel(&(p->buff));
	}
	return (1);
}

int				get_next_line_asm(const int fd, char **line, t_parser *p)
{
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			nbread;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	while ((nbread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nbread] = '\0';
		if (p->buff == NULL)
			p->buff = ft_strnew(1);
		temp = ft_strjoin(p->buff, buffer);
		free(p->buff);
		p->buff = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (nbread < 0)
		return (-1);
	else if (nbread == 0 && (p->buff == NULL || p->buff[0] == '\0'))
		return (0);
	return (newline(p, line, fd, nbread));
}
