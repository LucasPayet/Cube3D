/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:29:43 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/05 12:17:21 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate(t_cube *c, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->cam.dir_x;
	old_plane_x = c->cam.plane_x;
	c->cam.dir_x = c->cam.dir_x * cos(rot) - c->cam.dir_y * sin(rot);
	c->cam.dir_y = old_dir_x * sin(rot) + c->cam.dir_y * cos(rot);
	c->cam.plane_x = c->cam.plane_x * cos(rot) - c->cam.plane_y * sin(rot);
	c->cam.plane_y = old_plane_x * sin(rot) + c->cam.plane_y * cos(rot);
}

static void	update_state(t_cube *c)
{
	if (c->keys.w)
	{
		c->cam.pos_x += c->cam.dir_x * c->cam.move_speed;
		c->cam.pos_y += c->cam.dir_y * c->cam.move_speed;
	}
	if (c->keys.s)
	{
		c->cam.pos_x -= c->cam.dir_x * c->cam.move_speed;
		c->cam.pos_y -= c->cam.dir_y * c->cam.move_speed;
	}
	if (c->keys.a)
	{
		c->cam.pos_x -= c->cam.plane_x * c->cam.move_speed;
		c->cam.pos_y -= c->cam.plane_y * c->cam.move_speed;
	}
	if (c->keys.d)
	{
		c->cam.pos_x += c->cam.plane_x * c->cam.move_speed;
		c->cam.pos_y += c->cam.plane_y * c->cam.move_speed;
	}
	if (c->keys.left)
		rotate(c, -c->cam.rot_speed);
	if (c->keys.right)
		rotate(c, c->cam.rot_speed);
}

int	render(t_cube *c)
{
	ft_memset(c->map_img.addr, 0, MMAP_W * c->map_img.line_length);
	ft_memset(c->view_img.addr, 0, WIN_HEIGHT * c->view_img.line_length);
	update_state(c);
	fill_minimap(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->view_img.img, 0, 0);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);
	return (0);
}
