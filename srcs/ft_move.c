/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:57:46 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 13:04:15 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_left(t_env *env)
{
	env->origin_x -= 10;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_move_right(t_env *env)
{
	env->origin_x += 10;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_move_down(t_env *env)
{
	env->origin_y += 10;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_move_up(t_env *env)
{
	env->origin_y -= 10;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}
