/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:11:16 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:11:17 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update_time(t_cube *data)
{
	data->cam.oldTime = data->cam.time;
	data->cam.frameTime = (data->cam.time - data->cam.oldTime) / 1000.0;
	ft_printf("FPS: %f\n", 1.0 / data->cam.frameTime);
}

void	camera_dir(t_cube *game)
{
	if (game->cam.side == 0)
		game->cam.perpWallDist = (game->cam.sideDistX - game->cam.deltaDistX);
	else
		game->cam.perpWallDist = (game->cam.sideDistY - game->cam.deltaDistX);
}