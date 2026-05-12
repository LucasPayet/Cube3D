/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:36:15 by celia             #+#    #+#             */
/*   Updated: 2026/05/10 17:27:49 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	enqueue_neighbors(t_queue *q, int cx, int cy)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		q->q[q->tail][0] = cx + q->dx[i];
		q->q[q->tail][1] = cy + q->dy[i];
		q->tail++;
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

static void	flood_fill(t_cube *data, char **copy, int x, int y)
{
	t_queue	q;
	int		cx;
	int		cy;

	init_dirs(q.dx, q.dy);
	q.head = 0;
	q.tail = 0;
	q.q[q.tail][0] = x;
	q.q[q.tail++][1] = y;
	while (q.head < q.tail)
	{
		cx = q.q[q.head][0];
		cy = q.q[q.head++][1];
		if (is_cell_done(data, copy, cx, cy))
			continue ;
		copy[cy][cx] = 'V';
		enqueue_neighbors(&q, cx, cy);
	}
}

void	ft_check_map(t_cube *data)
{
	char	**copy;
	int		i;

	check_borders(data);
	check_spaces(data);
	copy = dup_map(data);
	flood_fill(data, copy, (int)data->cam.pos_x, (int)data->cam.pos_y);
	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

char	**dup_map(t_cube *data)
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

