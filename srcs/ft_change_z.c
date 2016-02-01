/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:53:09 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/01 12:46:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_increase_z(t_env *env)
{
	env->pad_z++;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

void	ft_decrease_z(t_env *env)
{
	env->pad_z--;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}
