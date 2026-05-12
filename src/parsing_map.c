/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:49:04 by celia             #+#    #+#             */
/*   Updated: 2026/05/10 17:33:11 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_invalid_char(t_cube *data, char c)
{
	if (c != '0' && c != '1' && c != ' ')
	{
		ft_printf("Error\nInvalid char '%c' in map\n", c);
		free_game(data);
		exit(EXIT_FAILURE);
	}
}

void	handle_spawn(t_cube *data, int x, int y, int *spawn_count)
{
	(*spawn_count)++;
	data->cam.pos_x = x;
	data->cam.pos_y = y;
	data->map.spawn_dir = data->map.map[y][x];
	data->map.map[y][x] = '0';
}

void	ft_validate_map(t_cube *data)
{
	int		y;
	int		x;
	int		spawn_count;
	char	c;

	spawn_count = 0;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			c = data->map.map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				handle_spawn(data, x, y, &spawn_count);
			else
				check_invalid_char(data, c);
			x++;
		}
		y++;
	}
	if (spawn_count == 0)
		error_exit("no spawn point", data);
	if (spawn_count > 1)
		error_exit("multiple spawn points", data);
}

void	init_dirs(int dx[4], int dy[4])
{
	dx[0] = 0;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = -1;
	dy[0] = 1;
	dy[1] = -1;
	dy[2] = 0;
	dy[3] = 0;
}
