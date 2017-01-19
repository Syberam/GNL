/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/19 19:33:31 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void				ft_fill_line(char **line, char *tmp)
{
	if (!*line)
		*line = ft_strsub(tmp, 0, ft_strlen(tmp)
			- ft_strlen(ft_strchr(tmp, '\n')));
	else
		*line = ft_strjoin(*line,
			ft_strsub(tmp, 0, (ft_strlen(tmp)
				- ft_strlen(ft_strchr(tmp, '\n')))));
	tmp = ft_strchr(tmp, '\n');
	if (tmp)
		tmp = tmp + 1;
}
*/
int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;
	int				nbread;

	*line = NULL;
	nbread = 1;
	if (tmp)
	{
		*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n')));
	}
	else
	{
		while (nbread > 0)
		{
			if (!(nbread = read(fd, buff, BUFF_SIZE)))
				return (1);
			buff[BUFF_SIZE] = 0;
			if (!tmp)
				tmp = buff;
			else
				tmp = ft_strjoin(tmp, buff);
		}
		return (get_next_line(fd, &*line));
	}
	return (1);
}

tout stocker dans tmp, mais la partie envoyee dans line, decaler au second tour.
utiliser ft_strncmp(line, tmp, ft_strlen(line));
