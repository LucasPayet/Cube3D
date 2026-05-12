/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:41:13 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/10 17:22:51 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_map_data(t_cube *data, char *name)
{
	data->map.height = 0;
	data->map.width = 0;
	data->cam.pos_x = 0;
	data->cam.pos_y = 0;
	data->map.fn = name;
}

int	main(int ac, char **av)
{
	t_cube	game;

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
	cube_init(&game, av[1]);
	mlx_do_key_autorepeatoff(game.mlx.mlx);
	mlx_hook(game.mlx.win, 17, 0, (t_fn)(intptr_t)ft_exit, &game);
	mlx_hook(game.mlx.win, 2, 1L << 0, (t_fn)(intptr_t)key_press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, (t_fn)(intptr_t)key_release, &game.keys);
	mlx_loop_hook(game.mlx.mlx, (t_fn)(intptr_t)render, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
