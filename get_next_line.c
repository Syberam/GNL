/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/31 19:02:39 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				ft_fill_line(char **line, char *buff)
{
	char			*tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (*line)
		*line = ft_ext_strjoin_free(*line, ft_strchrcpy(tmp, buff, '\n'),
					(*line ? 3 : 2));
	else
		*line = ft_ext_strjoin_free(*line, ft_strchrcpy(tmp, buff, '\n'), 2);
	if (ft_strchr(buff, '\n'))
		buff = ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
	else
		ft_bzero(buff, BUFF_SIZE + 1);
}

t_gnl				*ft_select_fd(t_gnl **begin, int fd)
{
	t_gnl			*current;
	t_gnl			*new;

	if (!*begin)
	{
		if (!(new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
			return (NULL);
		if (!(new->content = ft_memalloc(sizeof(char) * (BUFF_SIZE +1))))
			return (NULL);
		new->content = "lol";
		new->next = NULL;
		*begin = new;
	}
	current = *begin;
	if (current->fd == 0)
		current->fd = fd;
	while (current)
	{
		if (fd == current->fd)
			return (current);
		if (!(current->next))
		{
			if (!(new->content = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (NULL);
			new->fd = fd;
			new->next = NULL;
			current->next = new;
			current = current->next;
		}
	}
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*buff;
	t_gnl			*current;
	int				nbread;

	nbread = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = NULL;
	if (!(current = ft_select_fd(&buff, fd)))
		return (-1);
	while (nbread > 0)
	{
		if (!(current->content))
		{
			nbread = read(current->fd, current->content, BUFF_SIZE);
			if (!*line && nbread == 0)
				return (0);
			ft_putendl("ligne 77");
			current->content = ft_strncpy(current->content, current->content, BUFF_SIZE);
			ft_putendl("ligne 79");
		}
		if (ft_strchr(current->content, '\n'))
			nbread = 0;
			ft_putendl("ligne 83");
		ft_fill_line(&*line, current->content);
	}
	return (1);
}
