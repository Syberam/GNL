/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:54:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/11 20:37:18 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

typedef struct		s_glst
{
	char			*content;
	int				fd;
	struct s_glst	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
