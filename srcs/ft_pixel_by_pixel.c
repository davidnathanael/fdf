/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_by_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:58:26 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 16:09:02 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image_pixel_put(t_env *env, int x, int y, int color)
{
	if (x <= 0 || x >= WIN_W || y >= WIN_H || y < 0)
		return ;
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8)] = (color & 0xFF);
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8) + 1] = (color & 0xFF00) >> 8;
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8) + 2] = (color & 0xFF0000) >> 16;
}

void	ft_pixel_by_pixel_with_y(t_env *env, t_vect *vect, int clr, float slope)
{
	float		x;
	float		y;
	int			max;

	max = vect->y1 > vect->y2 ? vect->y1 : vect->y2;
	x = vect->y1 < vect->y2 ? vect->x1 : vect->x2;
	y = vect->y1 < vect->y2 ? vect->y1 : vect->y2;
	while (y < max)
	{
		ft_image_pixel_put(env, x, y, clr);
		x = x + slope;
		y++;
	}
}

void	ft_pixel_by_pixel_with_x(t_env *env, t_vect *vect, int color)
{
	float		x;
	float		y;
	float		slope;
	int			max;

	max = vect->x1 > vect->x2 ? vect->x1 : vect->x2;
	x = vect->x1 < vect->x2 ? vect->x1 : vect->x2;
	y = vect->x1 < vect->x2 ? vect->y1 : vect->y2;
	slope = (float)(vect->y1 - vect->y2) / (float)(vect->x1 - vect->x2);
	while (x < max)
	{
		ft_image_pixel_put(env, x, y, color);
		y = y + slope;
		x++;
	}
}
