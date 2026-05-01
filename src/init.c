/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:46:17 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/01 04:51:44 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char **create_map(void)
{
    char **map;

    map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;

    return (map);
}

static void	init_cam(t_cam *cam)
{
	cam->pos_x = 13;
	cam->pos_y = 8;
	cam->dir_x = 1;
	cam->dir_y = 0;
	cam->plane_x = 0;
	cam->plane_y = 0.66;
}

static void	init_keys(t_keys *k)
{
	k->w = 0;
	k->s = 0;
	k->a = 0;
	k->d = 0;
	k->left = 0;
	k->right = 0;
}

void	cube_init(t_cube *c, char *title)
{
	c->mlx.mlx = mlx_init();
	c->mlx.win = mlx_new_window(c->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	c->map_img.img = mlx_new_image(c->mlx.mlx, MMAP_W, MMAP_H);
	c->map_img.addr = mlx_get_data_addr(c->map_img.img, &c->map_img.bits_per_pixel,
			&c->map_img.line_length, &c->map_img.endian);
	c->view_img.img = mlx_new_image(c->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	c->view_img.addr = mlx_get_data_addr(c->view_img.img, &c->view_img.bits_per_pixel,
			&c->view_img.line_length, &c->view_img.endian);
	c->map_img.x_len = MMAP_W;
	c->map_img.y_len = MMAP_H;
	c->view_img.x_len = WIN_WIDTH;
	c->view_img.y_len = WIN_HEIGHT;
	c->map.map = create_map();
	init_keys(&c->keys);
	init_cam(&c->cam);
	c->map.width = 15;
	c->map.height = 10;
//	fill_minimap(c);
//	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->map_img.img, 40, 40);

}
