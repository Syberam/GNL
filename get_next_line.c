/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/21 18:06:05 by sbonnefo         ###   ########.fr       */
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

static int			ft_gnl(const int fd, char **line, int nbread, char **tmp)
{
	char			buff[BUFF_SIZE + 1];

	while ((*line == NULL || ft_strchr(*line, '\n') == NULL) /*&& nbread > 0*/)
	{
/*		ft_putstr("\033[36mline en entree de boucle : \033[0m");
		if (*line != NULL)
			ft_putstr(*line);
		ft_putchar('\n');
*/		if (*tmp != NULL)
		{
			if (ft_strchr(*tmp, '\n') == NULL)
			{
				if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
					return (nbread);
				buff[nbread] = 0;
				*tmp = ft_strdup(buff);
			}
			else
				*tmp = ft_strchr(*tmp, '\n') + 1;
		}
		else
		{
			if ((nbread = read(fd, buff, BUFF_SIZE)) < 1)
				return (nbread);
			buff[nbread] = 0;
			*tmp = ft_strdup(buff);
		}
		*line = ft_stock_line(&*line, *tmp);
		/*ft_putstr("line en fin de boucle : ");
		ft_putstr(*line);
		ft_putchar('\n');
*/
	}
/*	ft_putstr("line en sortie de boucle : ");
	ft_putstr(*line);
	ft_putchar('\n');
*/	if (ft_strchr(*line, '\n') != NULL)
		*line = ft_strsub(*line, 0, (ft_strlen(*line)
			- ft_strlen(ft_strchr(*line, '\n'))));
/*	ft_putstr("line apres suppr de \\n : ");
	ft_putstr(*line);
	ft_putchar('\n');
*/	


	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tmp;

	if (!*line || !fd || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	return (ft_gnl(fd, &*line, BUFF_SIZE, &tmp));
}
