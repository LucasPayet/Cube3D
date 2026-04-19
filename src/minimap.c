/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:52:57 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 23:29:38 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(t_img *img, int start_x, int start_y, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			update_pixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = (x0 < x1) ? 1 : -1;
	int	sy = (y0 < y1) ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
	update_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void draw_player_dir(t_cube *c)
{
    int center = (MMAP * TILE) / 2;

    int end_x = center + c->cam.dir_x * TILE;
    int end_y = center + c->cam.dir_y * TILE;

    draw_line(&c->map_img, center, center, end_x, end_y, 0x00FF0000);
}

void	fill_minimap(t_cube *cube)
{
	int		px = (int)cube->cam.pos_x;
	int		py = (int)cube->cam.pos_y;

	double	frac_x = cube->cam.pos_x - px;
	double	frac_y = cube->cam.pos_y - py;

	double	offset_x = frac_x * TILE;
	double	offset_y = frac_y * TILE;

	int		start_x = px - 2;
	int		start_y = py - 2;

	for (int y = 0; y < MMAP; y++)
	{
		for (int x = 0; x < MMAP; x++)
		{
			int mx = start_x + x;
			int my = start_y + y;

			int color;

			if (mx < 0 || my < 0 ||
				mx >= cube->map.width || my >= cube->map.height)
				color = 0x000000;
			else if (cube->map.map[my][mx] == '1')
				color = 0x00FFFFFF;
			else
				color = 0x00333333;

			int draw_x = x * TILE - offset_x;
			int draw_y = y * TILE - offset_y;

			draw_square(&cube->map_img, draw_x, draw_y, TILE, color);
	printf("lol\n");
		}
	}
    // draw player at center
    int center = (MMAP * TILE) / 2;
	draw_square(&cube->map_img, center - TILE / 4, center - TILE / 4, TILE / 2, 0x00FF0000);
	draw_player_dir(cube);
}
