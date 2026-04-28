/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:34:40 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:36:15 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
