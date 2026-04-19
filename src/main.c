/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:41:13 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 18:51:41 by lupayet          ###   ########.fr       */
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

	cube_init(&cube, av[1]);
	mlx_hook(cube.mlx.win, 17, 0, close_cube, &cube);
	mlx_hook(cube.mlx.win, 2, 1L<<0, key_press, &cube);
	mlx_hook(cube.mlx.win, 3, 1L<<1, key_release, &cube.keys);
	mlx_loop(cube.mlx.mlx);
	return (0);
}
