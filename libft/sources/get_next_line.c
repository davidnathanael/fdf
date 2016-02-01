/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:36:11 by amanukya          #+#    #+#             */
/*   Updated: 2015/12/11 20:08:33 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_append_to_line(char **line, char *to_add, int len_add)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(*line) + len_add + 1);
	tmp = ft_strcpy(tmp, *line);
	tmp = ft_strncat(tmp, to_add, len_add);
	free(*line);
	*line = tmp;
}

static void		ft_make_change(char **line, t_lst_fd **lst, char *src, char *nl)
{
	char *tmp;

	if (src[0] != '\n')
		ft_append_to_line(line, src, nl - src);
	if ((nl)[1] != 0)
	{
		tmp = ft_strnew(ft_strlen(nl + 1) + 1);
		tmp = ft_strcpy(tmp, nl + 1);
		if ((*lst)->bufsave)
			ft_strdel(&((*lst)->bufsave));
		(*lst)->bufsave = tmp;
	}
	else
	{
		ft_strdel(&((*lst)->bufsave));
		(*lst)->bufsave = NULL;
	}
}

static int		ft_find_nl(char **line, t_lst_fd **lst, char *buf, int fd)
{
	char			*nl;
	int				ret;

	if ((*lst)->bufsave && (nl = ft_strchr((*lst)->bufsave, '\n')))
		ft_make_change(line, lst, (*lst)->bufsave, nl);
	else
	{
		if (((*lst)->bufsave))
		{
			*line = ft_strnew(ft_strlen((*lst)->bufsave) + 1);
			*line = ft_strcpy(*line, (*lst)->bufsave);
		}
		while (!(nl = ft_strchr(buf, '\n')))
		{
			ft_append_to_line(line, buf, ft_strlen(buf));
			if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
				return (-1);
			buf[ret] = 0;
			if (ret == 0)
				return (0);
		}
		ft_make_change(line, lst, buf, nl);
	}
	return (1);
}

static t_lst_fd	*ft_add_fd(int fd)
{
	t_lst_fd	*new;

	if (!(new = (t_lst_fd *)malloc(sizeof(t_lst_fd))))
		return (NULL);
	new->fd = fd;
	if (!(new->bufsave = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	new->next = NULL;
	return (new);
}

int				get_next_line(int const fd, char **line)
{
	static t_lst_fd			*lst_fd = NULL;
	t_lst_fd				*tmp;
	char					*buf;
	int						ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!lst_fd)
		if (!(lst_fd = ft_add_fd(fd)))
			return (-1);
	tmp = lst_fd;
	while (tmp->fd != fd)
	{
		if (!(tmp->next) && tmp->fd != fd)
			tmp->next = ft_add_fd(fd);
		tmp = tmp->next;
	}
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	ret = ft_find_nl(line, &tmp, buf, fd);
	free(buf);
	return (ret);
}
