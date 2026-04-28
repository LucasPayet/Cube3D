/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:55:29 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:07:02 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    parse_color(char *line, int j, t_cube *data, int fd)
{
	if (ft_strncmp(line + j, "F ", 2) == 0)
	{
		if (data->conf.tex_parsed & 16)
			error_exit("duplicate F", data);
		parse_rgb(line + j + 2, data->conf.floor, data);
		data->conf.tex_parsed |= 16;
	}
	else if (ft_strncmp(line + j, "C ", 2) == 0)
	{
		if (data->conf.tex_parsed & 32)
			error_exit("duplicate C", data);
		parse_rgb(line + j + 2, data->conf.ceil, data);
		data->conf.tex_parsed |= 32;
	}
	else
	{
		free(line);
		close(fd);
		error_exit("unknown identifier", data);
	}
}

char	*get_tex_path(char *line)
{
	int		start;
	int		end;
	char	*path;

	start = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	end = start;
	while (line[end] && line[end] != '\n')
		end++;
	path = ft_substr(line, start, end - start);
	if (!path)
		return (NULL);
	return (path);
}

static void	validate_rgb_part(char **parts, int i, char *trimmed, t_cube *data)
{
	int	j;

	j = 0;
	while (trimmed[j] && trimmed[j] != '\n')
	{
		if (trimmed[j] < '0' || trimmed[j] > '9')
		{
			free(parts[i]);
			free(parts);
			error_exit("RGB must be numeric", data);
		}
		j++;
	}
}

static void	parse_rgb_component(char **parts, int i, int *rgb, t_cube *data)
{
	char	*trimmed;

	trimmed = parts[i];
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	validate_rgb_part(parts, i, trimmed, data);
	rgb[i] = ft_atoi(trimmed);
	if (rgb[i] < 0 || rgb[i] > 255)
	{
		free(parts[i]);
		free(parts);
		error_exit("RGB value out of range [0-255]", data);
	}
	free(parts[i]);
}

void	parse_rgb(char *str, int rgb[3], t_cube *data)
{
	char	**parts;
	int		i;

	while (*str == ' ' || *str == '\t')
		str++;
	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		error_exit("invalid RGB format (expected R,G,B)", data);
	i = 0;
	while (i < 3)
	{
		parse_rgb_component(parts, i, rgb, data);
		i++;
	}
	free(parts);
}
