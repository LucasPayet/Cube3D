/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:55 by celia             #+#    #+#             */
/*   Updated: 2026/04/30 19:13:19 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void move_player(t_cube *data, int new_x, int new_y)
{
	char	next_tile;
	char	old_tile;

	next_tile = data->map.map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E')
		data->img->on_exit = 1;
	else
		data->img->on_exit = 0;
	if (data->img->on_exit)
		old_tile = 'E';
	else
		old_tile = '0';
	data->map.map[data->cam.playerY][data->cam.playerX] = old_tile;
	data->map.map[new_y][new_x] = 'P';
	data->cam.playerX = new_x;
	data->cam.playerY = new_y;
}

static void	init_move_tables(int keys[4], int dx[4], int dy[4])
{
	keys[0] = W;
	keys[1] = S;
	keys[2] = A;
	keys[3] = D;
	dx[0] = 0;
	dx[1] = 0;
	dx[2] = -1;
	dx[3] = 1;
	dy[0] = -1;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = 0;
}

static void	move_dir(t_cube *data, int keycode)
{
	int	dx[4];
	int	dy[4];
	int	keys[4];
	int	i;

	init_move_tables(keys, dx, dy);
	i = 0;
	while (i < 4)
	{
		if (keycode == keys[i])
		{
			move_player(data, data->cam.playerX + dx[i],
				data->cam.playerY + dy[i]);
			return ;
		}
		i++;
	}
}

int	press_key(int keycode, void *game)
{
	t_cube	*data;

	data = (t_cube *)game;
	if (keycode == ESC || keycode == Q)
		ft_exit(data);
	move_dir(data, keycode);
	return (0);
}
