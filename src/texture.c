/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:12:34 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/12 06:32:49 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_img	*get_texture(t_cube *c, t_ray *r)
{
	if (r->side)
		if (r->dir_x > 0)
			return (&c->textures); // EST
		else
			return (&c->textures); // OUEST
	else
		if (r->dir_y > 0)
			return (&c->textures); // NORTH
		else
			return (&c->textures); // SOUTH
}

void	draw_texture_line(t_cube *c, t_ray *r, t_vert v)
{
	double	x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;

	t_img	*tex;

	if (r->side)
		x = r->hit_x - floor(r->hit_x);
	else
		x = r->hit_y - floor(r->hit_y);
	tex = get_texture(c, r);
	tex_x = (int)(x * tex->x_len);
	if (r->side == 0 && r->dir_x > 0)
		tex_x = tex->x_len - tex_x - 1;
	if (r->side == 1 && r->dir_y < 0)
		tex_x = tex->x_len - tex_x - 1;
	step = (double)tex->y_len / (double)v.line_height;
	tex_pos = (v.draw_start - WIN_HEIGHT / 2 + v.line_height / 2) * step;
	if (v.draw_start < 0)
	{
		tex_pos += (-v.draw_start) * step;
		v.draw_start = 0;
	}
	if (v.draw_end >= WIN_HEIGHT)
		v.draw_end = WIN_HEIGHT - 1;
	int y = v.draw_start;
	while (y <= v.draw_end)
	{
		tex_y = (int)tex_pos % tex->y_len;
		int	offset = (tex->line_length * tex_y) + (tex_x * (tex->bits_per_pixel / 8));
		int color = *(unsigned int *)(tex->addr + offset);
		update_pixel(&c->view_img, v.x, y, color);
		tex_pos += step;
		y++;
	}
}
