/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:52:57 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/04 05:54:48 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_player_dir(t_cube *c)
{
	t_pixel	center_p;
	t_pixel	end_p;

	center_p.x = CENTER;
	center_p.y = CENTER;
	end_p.x = CENTER + c->cam.dir_x * TILE;
	end_p.y = CENTER + c->cam.dir_y * TILE;
	draw_line(&c->map_img, center_p, end_p, 0x00FF0000);
}

void	minimap_loop(t_cube *cube, t_minimap *m)
{
	while (m->y <= MMAP)
	{
		m->x = -1;
		while (m->x <= MMAP)
		{
			m->mx = m->start_x + m->x;
			m->my = m->start_y + m->y;
			if (m->mx < 0 || m->my < 0
				|| m->mx >= cube->map.width || m->my >= cube->map.height)
				m->color = 0x0000FFFF;
			else if (cube->map.map[m->my] && cube->map.map[m->my][m->mx] == '1')
				m->color = 0x00FFFFFF;
			else
				m->color = 0x00333333;
			m->world_x = m->mx;
			m->world_y = m->my;
			m->dx = m->world_x - cube->cam.pos_x;
			m->dy = m->world_y - cube->cam.pos_y;
			m->draw_x = CENTER + m->dx * TILE;
			m->draw_y = CENTER + m->dy * TILE;
			draw_square(&cube->map_img, m->draw_x, m->draw_y, m->color);
			m->x++;
		}
		m->y++;
	}
}

void	renderd(t_cube *cube)
{
	int		i;
	double	camera;

	i = 0;
	while (i < WIN_WIDTH)
	{
		camera = 2 * i / (double)WIN_WIDTH - 1;
		ray(cube, cube->cam.dir_x + cube->cam.plane_x * camera,
			cube->cam.dir_y + cube->cam.plane_y * camera, i);
		i++;
	}
}

void	fill_minimap(t_cube *cube)
{
	t_minimap	m;

	m.px = floor(cube->cam.pos_x);
	m.py = floor(cube->cam.pos_y);
	m.start_x = m.px - (MMAP / 2);
	m.start_y = m.py - (MMAP / 2);
	m.y = -1;
	minimap_loop(cube, &m);
	renderd(cube);
	draw_player_dir(cube);
}
