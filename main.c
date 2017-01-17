/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:30:37 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/17 16:22:17 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int			fd;
	int			n;
	char		*line;

	n = 1;
	if (argc != 2)
	{
		ft_putstr("usage: a.out <filename>");
	}
	else
	{
		fd = (const int)open(argv[1], O_RDONLY);
		while (n > 0)
		{
			n = get_next_line(fd, &line);
			if (n == 1)
			{
				ft_putstr(line);
				ft_putchar('\n');
			}
		}
	}
	return (0);
}
