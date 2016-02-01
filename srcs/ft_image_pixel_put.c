/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:57:50 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 13:03:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image_pixel_put(t_env *env, int x, int y, int col)
{
	if (x <= 0 || x >= WIN_W || y >= WIN_H || y < 0)
		return ;
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8)] = (col & 0xFF);
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8) + 1] = (col & 0xFF00) >> 8;
	env->data[(y * env->size_line)\
	+ (x * env->bpp / 8) + 2] = (col & 0xFF0000) >> 16;
}
