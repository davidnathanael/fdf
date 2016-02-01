/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:59:14 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 15:26:50 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_up(t_env *env)
{
	env->angle_a -= 0.3;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_rotate_down(t_env *env)
{
	env->angle_a += 0.3;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_rotate_right(t_env *env)
{
	env->angle_w -= 0.3;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_rotate_left(t_env *env)
{
	env->angle_w += 0.3;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}
