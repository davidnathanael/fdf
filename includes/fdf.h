/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:36:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/02/03 16:13:53 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include <stdio.h>

# define WIN_H	1200
# define WIN_W	1900

# define BLUE	0x0000FF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define WHITE	0xFFFFFF
# define BROWN 	0x302013
# define YELLOW 0xF4EE60

typedef enum	e_theme
{
	NORMAL,
	RELIEF,
}				t_theme;

typedef enum	e_level
{
	UNDER_SEA,
	SEA,
	ALT,
	ABOVE_SEA,
}				t_level;

typedef enum	e_bool
{
	FALSE,
	TRUE,
}				t_bool;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_vect
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
}				t_vect;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			tx;
	int			ty;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*data;
	void		*img;
	int			size_line;
	int			endian;
	int			bpp;
	char		*path;
	int			map_x;
	int			map_y;
	int			max_z;
	int			pad;
	int			move_x;
	int			move_y;
	int			pad_z;
	float		angle_w;
	float		angle_a;
	int			origin_x;
	int			origin_y;
	int			theme;
	t_point		**map;
}				t_env;

void			ft_draw(t_env *e);
void			ft_draw_line(t_env *e, t_vect *vect, int z1, int z2);
t_point			**ft_get_data(t_env *e);
void			ft_zoom_in(t_env *e);
void			ft_zoom_out(t_env *e);
int				expose_hook(t_env *e);

void			ft_move_left(t_env *e);
void			ft_move_right(t_env *e);
void			ft_move_down(t_env *e);
void			ft_move_up(t_env *e);

void			ft_rotate_left(t_env *e);
void			ft_rotate_right(t_env *e);
void			ft_rotate_down(t_env *e);
void			ft_rotate_up(t_env *e);

void			ft_decrease_z(t_env *e);
void			ft_increase_z(t_env *e);

void			ft_change_theme(t_env *env);
int				ft_choose_color(int theme, int z1, int z2);

void			ft_set_vect(t_env *e, t_vect *vect, int i, int j);
void			ft_set_vect2(t_env *e, t_vect *vect, int i, int j);

void			ft_image_pixel_put(t_env *e, int x, int y, int color);
void			ft_pixel_by_pixel_with_y(t_env *e, t_vect *vect,
										int color, float slope);
void			ft_pixel_by_pixel_with_x(t_env *e, t_vect *vect, int color);

#endif
