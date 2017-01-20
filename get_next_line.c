/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/20 17:21:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_stock_line(char **line, char *tmp)
{
	int		ibn;

	if (!(ft_strchr(tmp, '\n')))
		ibn = 0;
	else
		ibn = ft_strlen(ft_strchr(tmp, '\n'));
			if (*line == NULL)
			{
				*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ibn + 1);
			}
			else
			{
				*line = ft_strjoin(*line, ft_strsub(tmp, 0, (ft_strlen(tmp)
						- ibn + 1)));
			}
			return (*line);
}

static int			ft_gnl(const int fd, char **line, int nbread)
{
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;

	while ((*line == NULL || ft_strchr(*line, '\n') == NULL) && nbread > 0)
	{
		if (tmp != NULL)
		{
			if (ft_strchr(tmp, '\n') == NULL )
			{
				if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
					return (nbread);
				buff[nbread] = 0;
				tmp = buff;
			}
			else
			{	
				if (ft_strchr(tmp, '\n'))
					tmp = ft_strchr(tmp, '\n') + 1;
			}
				*line = ft_stock_line(&*line, tmp);
		}
		else
		{
			if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
					return (nbread);
			buff[nbread] = 0;
			tmp = buff;
			*line = ft_stock_line(&*line, tmp);
		}
	}
	*line = ft_strsub(*line, 0, (ft_strlen(*line)
				- ft_strlen(ft_strchr(*line, '\n'))));
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	if (!*line || !fd || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	/*ft_putstr("start\n");
	ft_putstr(ft_strchr(*line, '\n'));
	ft_putstr("end\n");
	*/return (ft_gnl(fd, &*line, BUFF_SIZE));
}
