/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:36:15 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:24:25 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	enqueue_neighbors(int queue[10000][2], int *tail,
				int cx, int cy, int dx[4], int dy[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		queue[*tail][0] = cx + dx[i];
		queue[*tail][1] = cy + dy[i];
		(*tail)++;
		i++;
	}
}

static int	is_cell_done(t_cube *data, char **copy, int cx, int cy)
{
	if (cy < 0 || cy >= data->map.height
		|| cx < 0 || cx >= data->map.width)
		error_exit("map not closed", data);
	if (copy[cy][cx] == ' ' || copy[cy][cx] == '\0')
		error_exit("map not closed", data);
	if (copy[cy][cx] == '1' || copy[cy][cx] == 'V')
		return (1);
	return (0);
}


static void	flood_fill(t_cube *data, char **copy, int x, int y,
				int dx[4], int dy[4])
{
	int	queue[10000][2];
	int	head;
	int	tail;
	int	cx;
	int	cy;

	head = 0;
	tail = 0;
	queue[tail][0] = x;
	queue[tail++][1] = y;
	while (head < tail)
	{
		cx = queue[head][0];
		cy = queue[head++][1];
		if (is_cell_done(data, copy, cx, cy))
			continue ;
		copy[cy][cx] = 'V';
		enqueue_neighbors(queue, &tail, cx, cy, dx, dy);
	}
}

void	ft_check_map(t_cube *data)
{
	char	**copy;
	int		dx[4];
	int		dy[4];
	int		i;

	init_dirs(dx, dy);
	check_borders(data);
	check_spaces(data);
	copy = dup_map(data);
	flood_fill(data, copy, data->cam.playerX, data->cam.playerY, dx, dy);
	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

char    **dup_map(t_cube *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->map.height + 1));
	if (!copy)
		error_exit("malloc failed", data);
	i = 0;
	while (data->map.map[i])
	{
		copy[i] = ft_strdup(data->map.map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			error_exit("malloc failed", data);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

