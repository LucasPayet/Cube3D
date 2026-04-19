/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:46:17 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 23:34:45 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char **create_map(void)
{
    char **map;

    map = malloc(sizeof(char *) * 6);
	map[0] = ft_strdup("111111");
	map[1] = ft_strdup("100001");
	map[2] = ft_strdup("101101");
	map[3] = ft_strdup("100001");
	map[4] = ft_strdup("111111");
	map[5] = NULL;

    return (map);
}

static void	init_cam(t_cam *cam)
{
	cam->pos_x = 2;
	cam->pos_y = 1;
	cam->dir_x = 1.5;
	cam->dir_y = 1;
}

void	cube_init(t_cube *c, char *title)
{
	c->mlx.mlx = mlx_init();
	c->mlx.win = mlx_new_window(c->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	c->map_img.img = mlx_new_image(c->mlx.mlx, MMAP_W, MMAP_H);
	c->map_img.addr = mlx_get_data_addr(c->map_img.img, &c->map_img.bits_per_pixel,
			&c->map_img.line_length, &c->map_img.endian);
	c->map.map = create_map();
	init_cam(&c->cam);
	c->map.width = 6;
	c->map.height = 6;
	fill_minimap(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);
}
