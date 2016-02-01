/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:26:28 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 15:23:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_search_nb(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_point		ft_get_point(char *str, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	return (point);
}

t_point		*ft_create_tab(t_env *env, char *str, int pos)
{
	t_point	*list;
	char	**split;
	int		i;
	int		size;

	if (!ft_search_nb(str))
		return (NULL);
	split = ft_strsplit(str, ' ');
	size = ft_tablen(split);
	env->map_x = (size > env->map_x) ? size : env->map_x;
	if (!(list = (t_point *)malloc(sizeof(t_point) * (env->map_x + 1))))
		exit(0);
	i = 0;
	while (split[i])
	{
		list[i] = ft_get_point(split[i], i, pos);
		free(split[i]);
		i++;
	}
	free(split);
	while (++i < env->map_x)
		list[i] = ft_get_point("0", i, pos);
	return (list);
}

int			ft_get_size(char *argv)
{
	int		fd;
	char	*line;
	int		size;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("fdf");
		exit(1);
	}
	size = 0;
	while (get_next_line(fd, &line) == 1)
	{
		size++;
		free(line);
	}
	close(fd);
	return (size);
}

t_point		**ft_get_data(t_env *env)
{
	t_point	**map;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	env->map_x = 0;
	if (!(env->map_y = ft_get_size(env->path)))
		exit(0);
	if (!(map = (t_point **)malloc(sizeof(t_point *) * env->map_y + 1)))
		exit(0);
	if (!(fd = open(env->path, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = ft_create_tab(env, line, i);
		free(line);
		i++;
	}
	map[i] = ft_create_tab(env, line, i);
	map[i + 1] = NULL;
	close(fd);
	return (map);
}
