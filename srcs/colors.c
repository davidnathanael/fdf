/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:57:30 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 16:13:58 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_theme(t_env *env)
{
	env->theme = (env->theme == NORMAL) ? RELIEF : NORMAL;
	ft_bzero(env->data, WIN_W * WIN_H * env->bpp / 8);
	expose_hook(env);
}

int		ft_get_color(int theme, int level)
{
	if (theme == NORMAL)
	{
		if (level == UNDER_SEA)
			return (RED);
		else if (level == SEA)
			return (WHITE);
		else if (level == ALT)
			return (YELLOW);
		else if (level == ABOVE_SEA)
			return (BLUE);
	}
	else if (theme == RELIEF)
	{
		if (level == UNDER_SEA)
			return (BLUE);
		else if (level == SEA)
			return (YELLOW);
		else if (level == ALT)
			return (GREEN);
		else if (level == ABOVE_SEA)
			return (BROWN);
	}
	return (0);
}

int		ft_choose_color(int theme, int z1, int z2)
{
	if (z1 > 0 && z2 > 0 && z1 == z2)
		return (ft_get_color(theme, ABOVE_SEA));
	else if (z1 == 0 && z2 == 0)
		return (ft_get_color(theme, SEA));
	else if (z1 < 0 && z2 < 0)
		return (ft_get_color(theme, UNDER_SEA));
	else
		return (ft_get_color(theme, ALT));
}
