/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:22:42 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/01 05:14:15 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_pixel	minimap_pos(t_cube *c, double x, double y)
{
	t_pixel	p;

	double dx = x - c->cam.pos_x;
	double dy = y - c->cam.pos_y;

	int center = (MMAP * TILE) / 2;

	p.x = (center + dx * TILE);
	p.y = (center + dy * TILE);

	return (p);
}

void	draw_vertical_line(t_img *img, int x, int start, int end, int color)
{
	for (int y = start; y <= end; y++)
	{
		update_pixel(img, x, y, color);
	}
}

void	ray(t_cube *c, double ray_dir_x, double ray_dir_y, int x)
{
	static int	f = 0;
	int	map_x = (int)floor(c->cam.pos_x);
	int	map_y = (int)floor(c->cam.pos_y);

	double	side_dist_x;
	double	side_dist_y;

	double delta_dist_x;
	double delta_dist_y;

	if (ray_dir_x == 0)
		delta_dist_x = 1e30;
	else
		delta_dist_x = fabs(1 / ray_dir_x);

	if (ray_dir_y == 0)
		delta_dist_y = 1e30;
	else
		delta_dist_y = fabs(1 / ray_dir_y);

	int	step_x;
	int	step_y;
	int	hit = 0;
	int	side;

	// 🔁 step direction + initial distance
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (c->cam.pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - c->cam.pos_x) * delta_dist_x;
	}

	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (c->cam.pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - c->cam.pos_y) * delta_dist_y;
	}

	// 🧱 DDA loop
	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}

		if (map_x < 0 || map_y < 0 ||
			map_x >= c->map.width || map_y >= c->map.height)
			break ;

		if (c->map.map[map_y][map_x] == '1')
			hit = 1;
	}

	// 📍 compute exact hit point
	double perp_wall_dist;

	if (side == 0)
		perp_wall_dist = (map_x - c->cam.pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - c->cam.pos_y + (1 - step_y) / 2) / ray_dir_y;

	double hit_x = c->cam.pos_x + ray_dir_x * perp_wall_dist;
	double hit_y = c->cam.pos_y + ray_dir_y * perp_wall_dist;

	// 🎯 convert to minimap
	t_pixel p = minimap_pos(c, hit_x, hit_y);

	int center = (MMAP * TILE) / 2;
	if (f == 0)
	{
		draw_line(&c->map_img, center, center, p.x, p.y, 0x00FF00);
		f++;
	}
	else if (f == WIN_WIDTH / 60)
		f = 0;
	else
		f++;
	// 🎯 wall height
		int line_height = (int)(WIN_HEIGHT / perp_wall_dist);

		int draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		int draw_end   =  line_height / 2 + WIN_HEIGHT / 2;

		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;

		// 🎨 simple color
		int color = 0xFF0000;

		// 🔥 shading (very important visual)
		if (side == 1)
			color = color / 2;

		(void)x;
		printf("dist = %f\n", perp_wall_dist);
		printf("%d %d %d\n", x, draw_start, draw_end);
		draw_vertical_line(&c->view_img, x, draw_start, draw_end, color);
//	(void)x;
}
