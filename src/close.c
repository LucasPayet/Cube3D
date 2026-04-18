/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:40:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/17 18:51:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	exit(0);
	return (0);
}
