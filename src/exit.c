/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:33 by celia             #+#    #+#             */
/*   Updated: 2026/05/13 18:28:46 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	free_game(t_cube *data)
{
	int	i;

	if (data->conf.tex_no)
		free(data->conf.tex_no);
	if (data->conf.tex_so)
		free(data->conf.tex_so);
	if (data->conf.tex_we)
		free(data->conf.tex_we);
	if (data->conf.tex_ea)
		free(data->conf.tex_ea);
	if (data->map.map)
	{
		i = 0;
		while (data->map.map[i])
			free(data->map.map[i++]);
		free(data->map.map);
	}
}

void	error_exit(char *msg, t_cube *data)
{
	ft_printf("Error\n%s\n", msg);
	if (data)
		free_game(data);
	exit(EXIT_FAILURE);
}

int	ft_exit(void *param)
{
	close_cube((t_cube *)param);
	return (0);
}
