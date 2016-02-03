/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:50:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 13:04:00 by ddela-cr         ###   ########.fr       */
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
