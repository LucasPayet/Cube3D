/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:39:29 by celia             #+#    #+#             */
/*   Updated: 2026/05/13 15:35:48 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_cam_dir(t_cube *c)
{
	t_dir_init	dirs[4];
	int			i;

	dirs[0] = (t_dir_init){'N', 0, -1, 0.66, 0};
	dirs[1] = (t_dir_init){'S', 0, 1, -0.66, 0};
	dirs[2] = (t_dir_init){'E', 1, 0, 0, 0.66};
	dirs[3] = (t_dir_init){'W', -1, 0, 0, -0.66};
	i = 0;
	while (i < 4)
	{
		if (c->map.spawn_dir == dirs[i].spawn)
		{
			c->cam.dir_x = dirs[i].dir_x;
			c->cam.dir_y = dirs[i].dir_y;
			c->cam.plane_x = dirs[i].plane_x;
			c->cam.plane_y = dirs[i].plane_y;
			return ;
		}
		i++;
	}
}

void	init_cam(t_cube *c)
{
	c->cam.pos_x += 0.5;
	c->cam.pos_y += 0.5;
	set_cam_dir(c);
	c->cam.move_speed = 0.05;
	c->cam.rot_speed = 0.03;
}
