/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_by_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:58:26 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 13:06:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
