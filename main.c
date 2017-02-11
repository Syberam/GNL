/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:30:37 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/11 20:18:17 by sbonnefo         ###   ########.fr       */
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
	int			j;

	j = 1;
	line = "lol0";
	if (argc != 2)
	{
		ft_putstr("usage: a.out <filename>");
	}
	else
	{
		while (j < 6)
		{
			n = 1;
			i = 0;
		fd = (const int)open(argv[j], O_RDONLY);
		ft_putstr("Le fichier a lire est designe par le fd : ");
		ft_putnbr(fd);
		ft_putchar('\n');
		while (n > 0)
		{
			n = get_next_line(fd, &line);
			ft_putnbr(n);
			ft_putchar('\n');
			if (n == 1)
			{
				i++;
				ft_putstr("\033[33mline nº");
				ft_putnbr(i);
				ft_putstr(" :\t\033[36m\"\033[0m");
				ft_putstr(line);
				ft_putstr("\033[36m\"$\033[0m\n");
			}
			else if (n == 0)
				ft_putendl("\033[32mEOF\033[0m");
			else
				ft_putendl("\033[31mError\033[0m");
		}
		j++;
		}
	}
	return (0);
}
