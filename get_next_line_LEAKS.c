/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/22 18:02:59 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_stock_line(char **line, char *tmp)
{
	int				ibn;

	if (!(ft_strchr(tmp, '\n')))
		ibn = 0;
	else
		ibn = ft_strlen(ft_strchr(tmp, '\n')) - 1;
	if (*line == NULL)
		*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ibn);
	else
		*line = ft_strjoin(*line, ft_strsub(tmp, 0, (ft_strlen(tmp) - ibn)));
	return (*line);
}

int					ft_new_tmp(const int fd, char **tmp, int nbread)
{
	char			buff[BUFF_SIZE + 1];

	if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
		return (nbread);
	buff[nbread] = 0;
	*tmp = ft_strdup(buff);
	return (nbread);
}

static int			ft_gnl(const int fd, char **line, int nbread, char **tmp)
{
	while ((*line == NULL || ft_strchr(*line, '\n') == NULL) && nbread > 0)
	{
		if (nbread < BUFF_SIZE)
			return (1);
		if (*tmp != NULL)
		{
			if (ft_strchr(*tmp, '\n') == NULL)
				nbread = ft_new_tmp(fd, tmp, nbread);
			else
				*tmp = ft_strchr(*tmp, '\n') + 1;
			if (nbread < 1)
				return (nbread);
		}
		else
		{
			if ((nbread = ft_new_tmp(fd, tmp, nbread)) < 1)
				return (nbread);
		}
		*line = ft_stock_line(&*line, *tmp);
	}
	if (ft_strchr(*line, '\n') != NULL)
		*line = ft_strsub(*line, 0, (ft_strlen(*line)
			- ft_strlen(ft_strchr(*line, '\n'))));
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tmp;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	return (ft_gnl(fd, &*line, BUFF_SIZE, &tmp));
}
