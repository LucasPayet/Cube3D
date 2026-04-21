/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:29:43 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/20 18:30:46 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate(t_cube *c, double rot)
{
	double old_dir_x = c->cam.dir_x;
	double old_plane_x = c->cam.plane_x;

	c->cam.dir_x = c->cam.dir_x * cos(rot) - c->cam.dir_y * sin(rot);
	c->cam.dir_y = old_dir_x * sin(rot) + c->cam.dir_y * cos(rot);

	c->cam.plane_x = c->cam.plane_x * cos(rot) - c->cam.plane_y * sin(rot);
	c->cam.plane_y = old_plane_x * sin(rot) + c->cam.plane_y * cos(rot);
}

/*
static void	inside_map(double new_x, double new_y, t_cube *c)
{

}
*/
static void	update_state(t_cube *c)
{
	double move_speed = 0.0005;
	double rot_speed = 0.0003;

	if (c->keys.w)
	{
		c->cam.pos_x += c->cam.dir_x * move_speed;
		c->cam.pos_y += c->cam.dir_y * move_speed;
	}
	if (c->keys.s)
	{
		c->cam.pos_x -= c->cam.dir_x * move_speed;
		c->cam.pos_y -= c->cam.dir_y * move_speed;
	}
	if (c->keys.a) // strafe left
	{
		c->cam.pos_x -= c->cam.plane_x * move_speed;
		c->cam.pos_y -= c->cam.plane_y * move_speed;
	}
	if (c->keys.d) // strafe right
	{
		c->cam.pos_x += c->cam.plane_x * move_speed;
		c->cam.pos_y += c->cam.plane_y * move_speed;
	}
	if (c->keys.left) // rotate left
		rotate(c, -rot_speed);
	if (c->keys.right) // rotate right
		rotate(c, rot_speed);
}

int	render(t_cube *c)
{
	ft_memset(c->map_img.addr, 0,
	MMAP_W * c->map_img.line_length);
	update_state(c);
	fill_minimap(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);
	return (0);
}
