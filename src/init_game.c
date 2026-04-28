/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:40 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:07:55 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_player_img(t_cube *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->player, (*j) * 40, (*i) * 40);
	if (!data->img->player)
	{
		ft_printf("Failed to load player image");
	}
}

void	put_wall_img(t_cube *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->wall, (*j) * 40, (*i) * 40);
}

void	put_empty_img(t_cube *data, int *j, int *i)
{
	if (!data->img->empty)
		return ;
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->empty, (*j) * 40, (*i) * 40);
}

static int	get_color(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

static void	draw_background(t_cube *data, int floor_color, int ceil_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_pixel_put(data->mlx.mlx, data->mlx.win,
					x, y, ceil_color);
			else
				mlx_pixel_put(data->mlx.mlx, data->mlx.win,
					x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	ft_create_map(t_cube *data)
{
	draw_background(data, get_color(data->conf.floor),
		get_color(data->conf.ceil));
}
