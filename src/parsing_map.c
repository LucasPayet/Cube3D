/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:49:04 by celia             #+#    #+#             */
/*   Updated: 2026/04/30 19:01:04 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	ft_validate_map(t_cube *data)
// {
// 	int		y;
// 	int		x;
// 	int		spawn_count;
// 	char	c;

// 	spawn_count = 0;
// 	y = 0;
// 	while (data->map.map[y])
// 	{
// 		x = 0;
// 		while (data->map.map[y][x])
// 		{
// 			c = data->map.map[y][x];
// 			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 			{
// 				spawn_count++;
// 				data->cam.playerX = x;
// 				data->cam.playerY = y;
// 				data->map.spawn_dir = c;
// 				data->map.map[y][x] = '0';
// 			}
// 			else if (c != '0' && c != '1' && c != ' ')
// 			{
// 				ft_printf("Error\nInvalid char '%c' in map\n", c);
// 				free_game(data);
// 				exit(EXIT_FAILURE);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (spawn_count == 0)
// 		error_exit("no spawn point", data);
// 	if (spawn_count > 1)
// 		error_exit("multiple spawn points", data);
// }

// static void	check_borders(t_cube *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < data->map.width)
// 	{
// 		if (data->map.map[0][x] != '1')
// 			error_exit("map border not closed (top)", data);
// 		if (data->map.map[data->map.height - 1][x] != '1')
// 			error_exit("map border not closed (bottom)", data);
// 		x++;
// 	}
// 	y = 0;
// 	while (y < data->map.height)
// 	{
// 		if (data->map.map[y][0] != '1')
// 			error_exit("map border not closed (left)", data);
// 		if (data->map.map[y][data->map.width - 1] != '1')
// 			error_exit("map border not closed (right)", data);
// 		y++;
// 	}
// }

// static void	check_spaces(t_cube *data)
// {
// 	int	dx[4];
// 	int	dy[4];
// 	int	y;
// 	int	x;
// 	int	i;
// 	int	nx;
// 	int	ny;

// 	dx[0] = 0; dx[1] = 0; dx[2] = 1; dx[3] = -1;
// 	dy[0] = 1; dy[1] = -1; dy[2] = 0; dy[3] = 0;
// 	y = 0;
// 	while (y < data->map.height)
// 	{
// 		x = 0;
// 		while (x < data->map.width)
// 		{
// 			if (data->map.map[y][x] == '0')
// 			{
// 				i = 0;
// 				while (i < 4)
// 				{
// 					nx = x + dx[i];
// 					ny = y + dy[i];
// 					if (ny < 0 || ny >= data->map.height
// 						|| nx < 0 || nx >= data->map.width
// 						|| data->map.map[ny][nx] == ' ')
// 						error_exit("space adjacent to walkable cell", data);
// 					i++;
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	flood_fill(t_cube *data, char **copy, int x, int y)
// {
// 	int	queue[10000][2];
// 	int	head;
// 	int	tail;
// 	int	dx[4];
// 	int	dy[4];
// 	int	cx;
// 	int	cy;
// 	int	i;

// 	dx[0] = 0; dx[1] = 0; dx[2] = 1; dx[3] = -1;
// 	dy[0] = 1; dy[1] = -1; dy[2] = 0; dy[3] = 0;
// 	head = 0;
// 	tail = 0;
// 	queue[tail][0] = x;
// 	queue[tail][1] = y;
// 	tail++;
// 	while (head < tail)
// 	{
// 		cx = queue[head][0];
// 		cy = queue[head][1];
// 		head++;
// 		if (cy < 0 || cy >= data->map.height || cx < 0 || cx >= data->map.width)
// 			error_exit("map not closed", data);
// 		if (copy[cy][cx] == ' ' || copy[cy][cx] == '\0')
// 			error_exit("map not closed", data);
// 		if (copy[cy][cx] == '1' || copy[cy][cx] == 'V')
// 			continue ;
// 		copy[cy][cx] = 'V';
// 		i = 0;
// 		while (i < 4)
// 		{
// 			queue[tail][0] = cx + dx[i];
// 			queue[tail][1] = cy + dy[i];
// 			tail++;
// 			i++;
// 		}
// 	}
// }

// void	ft_check_map(t_cube *data)
// {
// 	char	**copy;
// 	int		i;

// 	check_borders(data);
// 	check_spaces(data);
// 	copy = malloc(sizeof(char *) * (data->map.height + 1));
// 	if (!copy)
// 		error_exit("malloc failed", data);
// 	i = 0;
// 	while (data->map.map[i])
// 	{
// 		copy[i] = ft_strdup(data->map.map[i]);
// 		if (!copy[i])
// 		{
// 			while (--i >= 0)
// 				free(copy[i]);
// 			free(copy);
// 			error_exit("malloc failed", data);
// 		}
// 		i++;
// 	}
// 	copy[i] = NULL;
// 	flood_fill(data, copy, data->cam.playerX, data->cam.playerY);
// 	i = 0;
// 	while (copy[i])
// 		free(copy[i++]);
// 	free(copy);
// }

// #include "cube.h"

// static void	handle_spawn(t_cube *data, int x, int y, int *spawn_count)
// {
// 	(*spawn_count)++;
// 	data->cam.playerX = x;
// 	data->cam.playerY = y;
// 	data->map.spawn_dir = data->map.map[y][x];
// 	data->map.map[y][x] = '0';
// }

// void	ft_validate_map(t_cube *data)
// {
// 	int		y;
// 	int		x;
// 	int		spawn_count;
// 	char	c;

// 	spawn_count = 0;
// 	y = 0;
// 	while (data->map.map[y])
// 	{
// 		x = 0;
// 		while (data->map.map[y][x])
// 		{
// 			c = data->map.map[y][x];
// 			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 				handle_spawn(data, x, y, &spawn_count);
// 			else if (c != '0' && c != '1' && c != ' ')
// 			{
// 				ft_printf("Error\nInvalid char '%c' in map\n", c);
// 				free_game(data);
// 				exit(EXIT_FAILURE);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (spawn_count == 0)
// 		error_exit("no spawn point", data);
// 	if (spawn_count > 1)
// 		error_exit("multiple spawn points", data);
// }

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
	data->cam.playerX = x;
	data->cam.playerY = y;
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
