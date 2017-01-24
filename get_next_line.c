/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/24 20:36:40 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int					ft_new_tmp(const int fd, char *buff, int nbread)
{


	*tmp = ft_strdup(buff);
	return (nbread);
}
*/

int					get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	size_t			mal;
	int				nbread;

	mal = 0;
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
		return (nbread);
	buff[nbread] = 0;
	while (ft_strchr(buff, '\n') == NULL)
	{

		if (*line != NULL)
			mal = 1;
		*line = ft_ext_strjoin_free(*line, buff, mal);
		if (nbread < BUFF_SIZE)
			return (1);
		if ((nbread = read(fd, buff, BUFF_SIZE)) < 0)
			return (nbread);
		buff[nbread] = 0;
	}
	return (1);
}
