/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:40 by celia             #+#    #+#             */
/*   Updated: 2026/05/06 19:00:23 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
