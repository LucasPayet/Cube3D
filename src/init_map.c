/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:47 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:35:15 by celia            ###   ########.fr       */
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

static void	update_map_size(t_cube *data, char *line, int *in_map)
{
	int	len;

	if (!*in_map && is_map_line(line))
		*in_map = 1;
	if (*in_map)
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
}

void	ft_map_height(t_cube *data)
{
	char	*line;
	int		fd;
	int		in_map;

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
		update_map_size(data, line, &in_map);
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
