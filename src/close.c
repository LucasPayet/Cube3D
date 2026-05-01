/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:40:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/24 23:28:59 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void free_map(char **map)
{
    /*int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }*/
    free(map);
}

int	close_cube(t_cube *c)
{
	//clean_fdf(fdf);
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
