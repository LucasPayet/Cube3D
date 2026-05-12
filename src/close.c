/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:40:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/12 15:38:33 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	ft_mlx_destroy(void *mlx)
// {
// # ifndef __APPLE__
// 	mlx_destroy_display(mlx);
	
// # endif
// 	free(mlx);
// }

void	free_map(char **map)
{
	free(map);
}

int	close_cube(t_cube *c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c->tex[i].img)
			mlx_destroy_image(c->mlx.mlx, c->tex[i].img);
		i++;
	}
	if (c->map_img.img)
		mlx_destroy_image(c->mlx.mlx, c->map_img.img);
	if (c->view_img.img)
		mlx_destroy_image(c->mlx.mlx, c->view_img.img);
	if (c->mlx.win)
		mlx_destroy_window(c->mlx.mlx, c->mlx.win);
	ft_mlx_destroy(c->mlx.mlx);
	free_game(c);
	exit(0);
	return (0);
}