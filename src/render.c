/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:29:43 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/12 06:00:31 by lupayet          ###   ########.fr       */
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

static void	update_pos(t_cube *c, double pos_x, double pos_y)
{
	if (c->map.map[(int)floor(pos_y)][(int)floor(pos_x)] != '1')
	{
		c->cam.pos_x = pos_x;
		c->cam.pos_y = pos_y;
	}
	else
		return ;
}

static void	update_state(t_cube *c, t_cam *cam)
{
	if (c->keys.w)
	{
		update_pos(c, cam->pos_x + cam->dir_x * cam->move_speed, cam->pos_y);
		update_pos(c, cam->pos_x, cam->pos_y + cam->dir_y * cam->move_speed);
	}
	if (c->keys.s)
	{
		update_pos(c, cam->pos_x - cam->dir_x * cam->move_speed, cam->pos_y);
		update_pos(c, cam->pos_x, cam->pos_y - cam->dir_y * cam->move_speed);
	}
	if (c->keys.a)
	{
		update_pos(c, cam->pos_x - cam->plane_x * cam->move_speed, cam->pos_y);
		update_pos(c, cam->pos_x, cam->pos_y - cam->plane_y * cam->move_speed);
	}
	if (c->keys.d)
	{
		update_pos(c, cam->pos_x + cam->plane_x * cam->move_speed, cam->pos_y);
		update_pos(c, cam->pos_x, cam->pos_y + cam->plane_y * cam->move_speed);
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
	update_state(c, &c->cam);
	fill_minimap(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->view_img.img, 0, 0);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);
	//mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->textures.img, 40, 40);
	return (0);
}
