/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:41:13 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 20:49:43 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_parse_map(t_cube *data)
{
	data->img->wall = mlx_xpm_file_to_image(data->mlx.mlx,
		data->conf.tex_no, &data->img->x_len, &data->img->y_len);
	if (!data->img->wall)
	{
		ft_printf("Error: failed to load NO texture: %s\n", data->conf.tex_no);
		exit(EXIT_FAILURE);
	}
	data->img->empty = mlx_xpm_file_to_image(data->mlx.mlx,
		data->conf.tex_so, &data->img->x_len, &data->img->y_len);
	data->img->player = mlx_xpm_file_to_image(data->mlx.mlx,
		data->conf.tex_we, &data->img->x_len, &data->img->y_len);
	data->img->exit = mlx_xpm_file_to_image(data->mlx.mlx,
		data->conf.tex_ea, &data->img->x_len, &data->img->y_len);
}

void	ft_map_data(t_cube *data, char *name)
{
	data->map.height = 0;
	data->map.width = 0;
	data->cam.playerX = 0;
	data->cam.playerY = 0;
	data->map.fn = name;
}

int main(int ac, char **av)
{
	t_cube game;

	ft_memset(&game, 0, sizeof(t_cube));
	if (ac != 2 || !av[1])
	{
		ft_printf("Error\nUsage: ./cub3D <map.cub>\n");
		return (1);
	}
	ft_map_data(&game, av[1]);
	ft_map_height(&game);
	ft_parse_identifiers(&game);
	ft_read_map(&game);
	ft_validate_map(&game);
	ft_check_map(&game);
	game.mlx.mlx = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.mlx, game.map.width * 40, game.map.height * 40, "cub3D");
	if (!game.mlx.win)
	{
		ft_printf("Error\nFailed to create window\n");
		return (1);
	}
	game.img = ft_calloc(1, sizeof(t_img));
	if (!game.img)
	{	
		ft_printf("Error\nmalloc img failed\n");
    	return (1);
	}
	ft_parse_map(&game);
	ft_create_map(&game);
	mlx_hook(game.mlx.win, 17, 0, (int (*)(void))(void *)ft_exit, &game);
	mlx_key_hook(game.mlx.win, press_key, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
