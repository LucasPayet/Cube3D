/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:29:43 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/10 17:19:45 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	try_move(t_cube *c, double new_x, double new_y)
{
	if (c->map.map[(int)c->cam.pos_y][(int)new_x] != '1')
		c->cam.pos_x = new_x;
	if (c->map.map[(int)new_y][(int)c->cam.pos_x] != '1')
		c->cam.pos_y = new_y;
}

static void	move_cam(t_cube *c)
{
	if (c->keys.w)
		try_move(c, c->cam.pos_x + c->cam.dir_x * c->cam.move_speed,
			c->cam.pos_y + c->cam.dir_y * c->cam.move_speed);
	if (c->keys.s)
		try_move(c, c->cam.pos_x - c->cam.dir_x * c->cam.move_speed,
			c->cam.pos_y - c->cam.dir_y * c->cam.move_speed);
	if (c->keys.a)
		try_move(c, c->cam.pos_x - c->cam.plane_x * c->cam.move_speed,
			c->cam.pos_y - c->cam.plane_y * c->cam.move_speed);
	if (c->keys.d)
		try_move(c, c->cam.pos_x + c->cam.plane_x * c->cam.move_speed,
			c->cam.pos_y + c->cam.plane_y * c->cam.move_speed);
}

static void	update_state(t_cube *c)
{
	move_cam(c);
	if (c->keys.left)
		rotate(c, -c->cam.rot_speed);
	if (c->keys.right)
		rotate(c, c->cam.rot_speed);
}

static void	draw_background(t_cube *c)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceil_color;

	y = 0;
	ceil_color = (c->conf.ceil[0] << 16) | (c->conf.ceil[1] << 8)
		| c->conf.ceil[2];
	floor_color = (c->conf.floor[0] << 16) | (c->conf.floor[1] << 8)
		| c->conf.floor[2];
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				update_pixel(&c->view_img, x, y, ceil_color);
			else
				update_pixel(&c->view_img, x, y, floor_color);
			x++;
		}
		y++;
	}
}

int	render(t_cube *c)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	ft_memset(c->map_img.addr, 0, MMAP_W * c->map_img.line_length);
	ft_memset(c->view_img.addr, 0, WIN_HEIGHT * c->view_img.line_length);
	update_state(c);
	draw_background(c);
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = c->cam.dir_x + c->cam.plane_x * camera_x;
		ray_dir_y = c->cam.dir_y + c->cam.plane_y * camera_x;
		ray(c, ray_dir_x, ray_dir_y, x);
		x++;
	}
	fill_minimap(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->view_img.img, 0, 0);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);
	return (0);
}
