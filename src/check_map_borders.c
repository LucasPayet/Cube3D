/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:50:27 by celia             #+#    #+#             */
/*   Updated: 2026/05/13 15:28:20 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_borders(t_cube *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.width)
	{
		if (data->map.map[0][x] != '1')
			error_exit("map border not closed (top)", data);
		if (data->map.map[data->map.height - 1][x] != '1')
			error_exit("map border not closed (bottom)", data);
		x++;
	}
	y = 0;
	while (y < data->map.height)
	{
		if (data->map.map[y][0] != '1')
			error_exit("map border not closed (left)", data);
		if (data->map.map[y][data->map.width - 1] != '1')
			error_exit("map border not closed (right)", data);
		y++;
	}
}

static void	check_cell_neighbors(t_cube *data, int x, int y)
{
	int		dx[4];
	int		dy[4];
	int		i;
	int		nx;
	int		ny;

	init_dirs(dx, dy);
	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (ny < 0 || ny >= data->map.height
			|| nx < 0 || nx >= data->map.width
			|| data->map.map[ny][nx] == ' ')
			error_exit("space adjacent to walkable cell", data);
		i++;
	}
}

void	check_spaces(t_cube *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map[y][x] == '0')
				check_cell_neighbors(data, x, y);
			x++;
		}
		y++;
	}
}
