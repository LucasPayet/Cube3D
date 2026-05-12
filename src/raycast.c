/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:22:42 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/12 05:33:48 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	dda_loop(t_cube *c, t_ray *r)
{
	r->hit = 0;
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_y < 0 || r->map_x >= c->map.width
			|| r->map_y >= c->map.height)
			break ;
		if (c->map.map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	draw_fov(t_cube *c, t_ray *r)
{
	static int	f = 0;
	t_pixel		p;
	t_pixel		center_p;

	p = minimap_pos(c, r->hit_x, r->hit_y);
	center_p.x = CENTER;
	center_p.y = CENTER;
	if (f == 0)
	{
		draw_line(&c->map_img, center_p, p, 0x00FF00);
		f++;
	}
	else if (f == WIN_WIDTH / 60)
		f = 0;
	else
		f++;
}

void	render3d(t_cube *c, t_ray *r, int x)
{
	t_vert	v;

	v.line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
	v.draw_start = -v.line_height / 2 + WIN_HEIGHT / 2;
	v.draw_end = v.line_height / 2 + WIN_HEIGHT / 2;
	if (v.draw_start < 0)
		v.draw_start = 0;
	if (v.draw_end >= WIN_HEIGHT)
		v.draw_end = WIN_HEIGHT - 1;
	v.x = x;
	v.color = 0xFF0000;
	if (r->side)
		v.color = 0x0000FF;
	//draw_vertical_line(&c->view_img, v);
	draw_texture_line(c, r, v);
}

void	step_dir(t_cube *c, t_ray *r)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (c->cam.pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - c->cam.pos_x) * r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (c->cam.pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - c->cam.pos_y) * r->delta_dist_y;
	}
}

void	ray(t_cube *c, t_ray *r, int x)
{
	r->map_x = (int)floor(c->cam.pos_x);
	r->map_y = (int)floor(c->cam.pos_y);
	if (r->dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->dir_y);
	step_dir(c, r);
	dda_loop(c, r);
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - c->cam.pos_x + (1 - r->step_x) / 2)
			/ r->dir_x;
	else
		r->perp_wall_dist = (r->map_y - c->cam.pos_y + (1 - r->step_y) / 2)
			/ r->dir_y;
	r->hit_x = c->cam.pos_x + r->dir_x * r->perp_wall_dist;
	r->hit_y = c->cam.pos_y + r->dir_y * r->perp_wall_dist;
	draw_fov(c, r);
	render3d(c, r, x);
}
