/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:40:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/13 15:41:50 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	mlx_destroy_display(c->mlx.mlx);
	free(c->mlx.mlx);
	free_game(c);
	exit(0);
	return (0);
}
