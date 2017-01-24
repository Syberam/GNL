/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:30:37 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/22 19:36:42 by sbonnefo         ###   ########.fr       */
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
	line = "lol0";
	if (argc != 2)
	{
		ft_putstr("usage: a.out <filename>");
	}
	else
	{
		fd = (const int)open(argv[1], O_RDONLY);
		ft_putstr("Le fichier a lire est designe pas le fd : ");
		ft_putnbr(fd);
		ft_putchar('\n');
		while (n > 0)
		{
			n = get_next_line(fd, &line);
			if (n == 1)
			{
				i++;
				ft_putstr("\033[33mline nº");
				ft_putnbr(i);
				ft_putstr(" :\t\033[36m\"\033[0m");
				ft_putstr(line);
				ft_putstr("\033[36m\"$\033[0m\n");
				ft_putnbr(ft_strcmp(line, "1234567"));
			}
			else if (n == 0)
			{
				ft_putstr(line);
				ft_putstr("\033[32mEOF\033[0m");
			}
			else
				ft_putstr("\033[31mError\033[0m");
		}
	}
	return (0);
}
