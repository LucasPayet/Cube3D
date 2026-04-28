/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:48:59 by celia             #+#    #+#             */
/*   Updated: 2026/04/28 15:02:16 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_all_parsed(t_cube *data)
{
	if (data->conf.tex_parsed != 63)
	{
		ft_printf("Error\nMissing identifier(s) (mask: %d/63)\n",
			data->conf.tex_parsed);
		free_game(data);
		exit(EXIT_FAILURE);
	}
}

static void	parse_tex_ns(char *line, int j, t_cube *data)
{
	if (ft_strncmp(line + j, "NO ", 3) == 0)
	{
		if (data->conf.tex_parsed & 1)
			error_exit("duplicate NO", data);
		data->conf.tex_no = get_tex_path(line + j + 3);
		data->conf.tex_parsed |= 1;
	}
	else if (ft_strncmp(line + j, "SO ", 3) == 0)
	{
		if (data->conf.tex_parsed & 2)
			error_exit("duplicate SO", data);
		data->conf.tex_so = get_tex_path(line + j + 3);
		data->conf.tex_parsed |= 2;
	}
}

static void	parse_tex_we(char *line, int j, t_cube *data)
{
	if (ft_strncmp(line + j, "WE ", 3) == 0)
	{
		if (data->conf.tex_parsed & 4)
			error_exit("duplicate WE", data);
		data->conf.tex_we = get_tex_path(line + j + 3);
		data->conf.tex_parsed |= 4;
	}
	else if (ft_strncmp(line + j, "EA ", 3) == 0)
	{
		if (data->conf.tex_parsed & 8)
			error_exit("duplicate EA", data);
		data->conf.tex_ea = get_tex_path(line + j + 3);
		data->conf.tex_parsed |= 8;
	}
}

static void	parse_tex(char *line, int j, t_cube *data, int fd)
{
	if (ft_strncmp(line + j, "NO ", 3) == 0
		|| ft_strncmp(line + j, "SO ", 3) == 0)
		parse_tex_ns(line, j, data);
	else if (ft_strncmp(line + j, "WE ", 3) == 0
		|| ft_strncmp(line + j, "EA ", 3) == 0)
		parse_tex_we(line, j, data);
	else
		parse_color(line, j, data, fd);
}

void	ft_parse_identifiers(t_cube *data)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(data->map.fn, O_RDONLY);
	if (fd < 0)
		error_exit("cannot open file", data);
	data->conf.tex_parsed = 0;
	i = 0;
	line = ft_get_next_line(fd);
	while (line && i < data->map.map_start)
	{
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] != '\n' && line[j] != '\0')
			parse_tex(line, j, data, fd);
		free(line);
		line = ft_get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	check_all_parsed(data);
}
