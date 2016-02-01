/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 07:43:35 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 15:49:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_choose_color(int z1, int z2)
{
	if (z1 != 0 && z2 != 0 && z1 == z2)
		return (RED);
	else if (z1 - z2 == 0)
		return (WHITE);
	else if (z1 <= 0 && z2 <= 0)
		return (BLUE);
	else
		return (GREEN);
}

void	ft_draw_line(t_env *env, t_vect *vect, int z1, int z2)
{
	float		slope;
	int			color;

	color = ft_choose_color(z1, z2);
	slope = (float)(vect->x1 - vect->x2) / (float)(vect->y1 - vect->y2);
	if (vect->y1 != vect->y2 && fabs(slope) < 1)
		ft_pixel_by_pixel_with_y(env, vect, color, slope);
	else
		ft_pixel_by_pixel_with_x(env, vect, color);
}

void	ft_draw(t_env *e)
{
	int		i;
	int		j;
	t_vect	vect;
	t_vect	vect2;

	j = 0;
	while (j < e->map_y && j < WIN_H)
	{
		i = 0;
		while (i < e->map_x && i < WIN_W)
		{
			if (i < e->map_x - 1)
			{
				ft_set_vect(e, &vect, i, j);
				ft_draw_line(e, &vect, e->map[j][i].z, e->map[j][i + 1].z);
			}
			if (j < e->map_y - 1)
			{
				ft_set_vect2(e, &vect2, i, j);
				ft_draw_line(e, &vect2, e->map[j][i].z, e->map[j + 1][i].z);
			}
			i++;
		}
		j++;
	}
}
