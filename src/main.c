/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:41:13 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/15 19:14:05 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

int	main(int ac, char *av[])
{
	t_cube	cube;
	
	if (ac != 2)
	{
		ft_putstr_fd("Wrong input", 2);
		return (1);
	}
	cube.mlx.mlx = mlx_init();
	cube.mlx.win = mlx_new_window(cube.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, av[1]);


	mlx_destroy_window(cube.mlx.mlx, cube.mlx.win);
	mlx_destroy_display(cube.mlx.mlx);
	free(cube.mlx.mlx);

	return (0);
}
