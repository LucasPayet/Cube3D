/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:40:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/05 11:21:13 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_map(char **map)
{
	free(map);
}

int	close_cube(t_cube *c)
{
	if (c->map_img.img)
		mlx_destroy_image(c->mlx.mlx, c->map_img.img);
	if (c->view_img.img)
		mlx_destroy_image(c->mlx.mlx, c->view_img.img);
	if (c->mlx.mlx)
	{
		if (c->mlx.win)
		{
			mlx_destroy_window(c->mlx.mlx, c->mlx.win);
			mlx_destroy_display(c->mlx.mlx);
			free(c->mlx.mlx);
		}
	}
	free_map(c->map.map);
	exit(0);
	return (0);
}
