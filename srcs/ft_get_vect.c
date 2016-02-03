/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:59:23 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 16:09:03 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_vect2(t_env *env, t_vect *vect, int i, int j)
{
	int		pad;
	float	angle_a;
	float	angle_w;

	pad = env->pad;
	angle_a = env->angle_a;
	angle_w = env->angle_w;
	vect->x1 = env->origin_x + cos(angle_w) * (i * pad) - \
						sin(angle_w) * (j * pad);
	vect->y1 = env->origin_y - sin(angle_w) * sin(angle_a) * (i * pad) - \
						cos(angle_w) * sin(angle_a) * (j * pad) + \
						cos(angle_a) * (env->map[j][i].z * env->pad_z);
	vect->x2 = env->origin_x + cos(angle_w) * (i * pad) - \
						sin(angle_w) * ((j + 1) * pad);
	vect->y2 = env->origin_y - sin(angle_w) * sin(angle_a) * (i * pad) - \
						cos(angle_w) * sin(angle_a) * ((j + 1) * pad) + \
						cos(angle_a) * (env->map[j + 1][i].z * env->pad_z);
}

void	ft_set_vect(t_env *env, t_vect *vect, int i, int j)
{
	int		pad;
	float	angle_a;
	float	angle_w;

	pad = env->pad;
	angle_a = env->angle_a;
	angle_w = env->angle_w;
	vect->x1 = env->origin_x + cos(angle_w) * (i * pad) - \
						sin(angle_w) * (j * pad);
	vect->y1 = env->origin_y - sin(angle_w) * sin(angle_a) * (i * pad) - \
						cos(angle_w) * sin(angle_a) * (j * pad) + \
						cos(angle_a) * (env->map[j][i].z * env->pad_z);
	vect->x2 = env->origin_x + cos(angle_w) * ((i + 1) * pad) - \
						sin(angle_w) * (j * pad);
	vect->y2 = env->origin_y - sin(angle_w) * sin(angle_a) * ((i + 1) * pad) - \
						cos(angle_w) * sin(angle_a) * (j * pad) + \
						cos(angle_a) * (env->map[j][i + 1].z * env->pad_z);
}
