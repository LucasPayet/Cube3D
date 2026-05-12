/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:12:34 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/10 16:41:53 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_tex_line(t_cube *c, t_ray *r, t_draw_tex *d)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		y;

	step = (double)c->tex[r->tex_num].y_len / d->line_height;
	tex_pos = (d->draw_start - WIN_HEIGHT / 2 + d->line_height / 2) * step;
	y = d->draw_start;
	while (y <= d->draw_end)
	{
		tex_y = (int)tex_pos % c->tex[r->tex_num].y_len;
		tex_pos += step;
		color = *(int *)(c->tex[r->tex_num].addr
				+ tex_y * c->tex[r->tex_num].line_length
				+ r->tex_x * (c->tex[r->tex_num].bits_per_pixel / 8));
		if (r->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		update_pixel(&c->view_img, d->x, y, color);
		y++;
	}
}

void	calc_tex(t_cube *c, t_ray *r, double ray_dir_x, double ray_dir_y)
{
	if (r->side == 0)
	{
		if (ray_dir_x > 0)
			r->tex_num = 3;
		else
			r->tex_num = 2;
	}
	else
	{
		if (ray_dir_y > 0)
			r->tex_num = 1;
		else
			r->tex_num = 0;
	}
	if (r->side == 0)
		r->wall_x = c->cam.pos_y + r->perp_wall_dist * ray_dir_y;
	else
		r->wall_x = c->cam.pos_x + r->perp_wall_dist * ray_dir_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * c->tex[r->tex_num].x_len);
	if (r->side == 0 && ray_dir_x > 0)
		r->tex_x = c->tex[r->tex_num].x_len - r->tex_x - 1;
	if (r->side == 1 && ray_dir_y < 0)
		r->tex_x = c->tex[r->tex_num].x_len - r->tex_x - 1;
}
