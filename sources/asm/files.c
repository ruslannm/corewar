/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:07:08 by rgero             #+#    #+#             */
/*   Updated: 2020/08/08 09:54:00 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_filename(const char *filename)
{
	int		len;

	if (filename)
	{
		len = ft_strlen(filename);
		if (len >= 2)
		{
			if (0 == ft_strcmp(&filename[len - 2], ".s"))
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

char		*replace_extension(t_parser *parser, const char *filename)
{
	char	*newname;
	int		len;

	if (filename)
	{
		len = ft_strlen(filename);
		if (!(newname = ft_strnew(len + 2)))
			terminate(parser, ERR_MEMORY, "replace_extension");
		newname = ft_strncpy(newname, filename, len - 1);
		newname = ft_strcat(newname, "cor");
		return (newname);
	}
	return (NULL);
}
