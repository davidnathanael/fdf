/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 16:13:55 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *env)
{
	ft_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void	ft_handle_event(int keycode, t_env *env)
{
	if (keycode == 126)
		ft_move_up(env);
	else if (keycode == 125)
		ft_move_down(env);
	else if (keycode == 123)
		ft_move_left(env);
	else if (keycode == 124)
		ft_move_right(env);
	else if (keycode == 34)
		ft_rotate_up(env);
	else if (keycode == 37)
		ft_rotate_right(env);
	else if (keycode == 40)
		ft_rotate_down(env);
	else if (keycode == 38)
		ft_rotate_left(env);
	else if (keycode == 24)
		ft_zoom_in(env);
	else if (keycode == 27)
		ft_zoom_out(env);
	else if (keycode == 6)
		ft_increase_z(env);
	else if (keycode == 7)
		ft_decrease_z(env);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	else if (keycode == 8)
		ft_change_theme(env);
	else
		ft_handle_event(keycode, env);
	return (0);
}

void	ft_choose_position(t_env *env)
{
	if (env->map_y < 30)
	{
		env->origin_x = 800;
		env->origin_y = 500;
		env->pad = 30;
	}
	else if (env->map_y < 60)
	{
		env->origin_x = 800;
		env->origin_y = 300;
		env->pad = 20;
	}
	else if (env->map_y < 300)
	{
		env->origin_x = 800;
		env->origin_y = 100;
		env->pad = 10;
	}
	else
	{
		env->origin_x = 800;
		env->origin_y = 100;
		env->pad = 5;
	}
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		env.path = av[1];
		env.pad_z = 1;
		env.move_x = 1;
		env.move_y = 1;
		env.angle_a = -M_PI + M_PI / 6;
		env.angle_w = M_PI / 12;
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, "fdf");
		env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
		env.data = mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line),
			&(env.endian));
		env.map = ft_get_data(&env);
		env.theme = NORMAL;
		ft_choose_position(&env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_putendl_fd("usage: ./fdf <file>", 2);
	return (0);
}
