/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:50:27 by celia             #+#    #+#             */
/*   Updated: 2026/05/14 20:53:48 by cbrice           ###   ########.fr       */
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
		if (data->map.map[0][x] == '0')
			error_exit("map border not closed (top)", data);
		if (data->map.map[data->map.height - 1][x] == '0')
			error_exit("map border not closed (bottom)", data);
		x++;
	}
	y = 0;
	while (y < data->map.height)
	{
		if (data->map.map[y][0] == '0')
			error_exit("map border not closed (left)", data);
		if (data->map.map[y][data->map.width - 1] == '0')
			error_exit("map border not closed (right)", data);
		y++;
	}
}
