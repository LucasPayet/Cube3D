/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:46:17 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/16 03:05:21 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_keys(t_cube *c)
{
	c->keys.w = 0;
	c->keys.s = 0;
	c->keys.a = 0;
	c->keys.d = 0;
	c->keys.left = 0;
	c->keys.right = 0;
	mlx_mouse_get_pos(c->mlx.mlx, c->mlx.win, &c->keys.mouse_x,
		&c->keys.mouse_y);
	mlx_mouse_move(c->mlx.mlx, c->mlx.win, c->keys.mouse_x, c->keys.mouse_y);
}

static void	init_images(t_cube *c)
{
	c->map_img.img = mlx_new_image(c->mlx.mlx, MMAP_W, MMAP_H);
	c->map_img.addr = mlx_get_data_addr(c->map_img.img,
			&c->map_img.bits_per_pixel, &c->map_img.line_length,
			&c->map_img.endian);
	c->view_img.img = mlx_new_image(c->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	c->view_img.addr = mlx_get_data_addr(c->view_img.img,
			&c->view_img.bits_per_pixel, &c->view_img.line_length,
			&c->view_img.endian);
	c->map_img.x_len = MMAP_W;
	c->map_img.y_len = MMAP_H;
	c->view_img.x_len = WIN_WIDTH;
	c->view_img.y_len = WIN_HEIGHT;
}

static void	init_textures(t_cube *c)
{
	int		i;
	char	*paths[4];

	paths[0] = c->conf.tex_no;
	paths[1] = c->conf.tex_so;
	paths[2] = c->conf.tex_we;
	paths[3] = c->conf.tex_ea;
	i = 0;
	while (i < 4)
	{
		c->tex[i].img = mlx_xpm_file_to_image(c->mlx.mlx,
				paths[i], &c->tex[i].x_len, &c->tex[i].y_len);
		if (!c->tex[i].img)
			error_exit("failed to load texture", c);
		c->tex[i].addr = mlx_get_data_addr(c->tex[i].img,
				&c->tex[i].bits_per_pixel, &c->tex[i].line_length,
				&c->tex[i].endian);
		i++;
	}
}

void	cube_init(t_cube *c, char *title)
{
	c->mlx.mlx = mlx_init();
	c->mlx.win = mlx_new_window(c->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	init_images(c);
	init_keys(c);
	init_cam(c);
	init_textures(c);
}
