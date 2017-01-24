/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:54:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/24 19:58:00 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

int			get_next_line(const int fd, char **line);

#endif
