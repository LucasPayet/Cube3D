/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:47 by celia             #+#    #+#             */
/*   Updated: 2026/04/26 22:48:48 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (0);
	if (line[i] != '1' && line[i] != '0')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	ft_map_height(t_cube *data)
{
	char	*line;
	int		fd;
	int		in_map;
	int		len;

	fd = open(data->map.fn, O_RDONLY);
	if (fd < 0)
		error_exit("cannot open file", data);
	in_map = 0;
	data->map.height = 0;
	data->map.map_start = 0;
	data->map.width = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!in_map && is_map_line(line))
			in_map = 1;
		if (in_map)
		{
			len = 0;
			while (line[len] && line[len] != '\n')
				len++;
			if (len > data->map.width)
				data->map.width = len;
			data->map.height++;
		}
		else
			data->map.map_start++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	if (data->map.height == 0)
		error_exit("no map found", data);
}


char	*trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static char	*pad_line(char *line, int target_width, t_cube *data)
{
	char	*padded;
	int		len;
	int		j;

	len = ft_strlen(line);
	if (len >= target_width)
		return (line);
	padded = ft_calloc(target_width + 1, sizeof(char));
	if (!padded)
		error_exit("malloc failed", data);
	j = 0;
	while (j < len)
	{
		padded[j] = line[j];
		j++;
	}
	while (j < target_width)
		padded[j++] = ' ';
	free(line);
	return (padded);
}

static int	open_and_skip(t_cube *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->map.fn, O_RDONLY);
	if (fd < 0)
		error_exit("cannot open file", data);
	i = 0;
	while (i < data->map.map_start)
	{
		line = ft_get_next_line(fd);
		free(line);
		i++;
	}
	return (fd);
}

static void	fill_map(t_cube *data, int fd)
{
	char	*line;
	int		i;

	data->map.map = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.map)
		error_exit("malloc failed", data);
	i = 0;
	line = ft_get_next_line(fd);
	while (line && i < data->map.height)
	{
		line = trim_newline(line);
		data->map.map[i] = pad_line(line, data->map.width, data);
		line = ft_get_next_line(fd);
		i++;
	}
	data->map.map[i] = NULL;
	if (line)
		free(line);
}

void	ft_read_map(t_cube *data)
{
	int	fd;

	fd = open_and_skip(data);
	fill_map(data, fd);
	close(fd);
}