/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:59:45 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 13:07:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_in(t_env *env)
{
	env->pad++;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_zoom_out(t_env *env)
{
	env->pad--;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}
