/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:50:33 by amanukya          #+#    #+#             */
/*   Updated: 2015/12/13 11:28:59 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 3

typedef struct					s_lst_fd
{
	char				*bufsave;
	int					fd;
	struct s_lst_fd		*next;
}								t_lst_fd;

int								get_next_line(int const fd, char **line);

#endif
