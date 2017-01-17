/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/17 20:30:04 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_gnl(const int fd, char **line, int nbread)
{
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;

	if (!tmp)
	{
		if (!(nbread = read(fd, buff, BUFF_SIZE)))
			return (nbread);
		buff[nbread] = 0;
		tmp = buff;
		return (ft_gnl(fd, &*line, nbread));
	}
	else
	{
		if (!*line)
		*line = ft_strsub(tmp, 0, ft_strlen(tmp)
				- ft_strlen(ft_strchr(tmp, '\n')));
		else
		*line = ft_strjoin(*line, 
			ft_strsub(tmp, 0, ft_strlen(tmp)
				- ft_strlen(ft_strchr(tmp, '\n'))));
		tmp = ft_strchr(tmp, '\n') + 1;
		if (nbread < BUFF_SIZE && ft_strlen(tmp) == 1)
			return (0);
		else if (nbread == BUFF_SIZE && ft_strlen(tmp) == 1)
			return (ft_gnl(fd, &*line, nbread));
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	*line = NULL;
	return (ft_gnl(fd, &*line, BUFF_SIZE));
}
