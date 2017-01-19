/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:30:37 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/19 17:02:07 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int			fd;
	int			n;
	char		*line;
	int			i;

	i = 0;
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
				i++;
				ft_putstr("\033[33mline nº");
				ft_putnbr(i);
				ft_putstr(" :\t\033[0m");
				ft_putstr(line);
				ft_putchar('\n');
			}
			else if (n == 0)
				ft_putstr("End Of File");
			else
				ft_putstr("Error");
		}
	}
	return (0);
}
