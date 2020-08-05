/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:15:32 by lnickole          #+#    #+#             */
/*   Updated: 2019/08/18 15:56:25 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline(char **s, char **line, int fd, int nbread)
{
	char	*temp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		temp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = temp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (nbread == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[10000];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			nbread;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((nbread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nbread] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (nbread < 0)
		return (-1);
	else if (nbread == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (newline(s, line, fd, nbread));
}
