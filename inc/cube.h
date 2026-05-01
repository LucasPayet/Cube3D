/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:46:55 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/01 04:39:01 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "s_cube.h"
#include "libft.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MMAP 5
# define TILE 40
# define MMAP_W MMAP * TILE
# define MMAP_H MMAP * TILE
# define NUM_RAYS 60

# define ESC 65307

void	cube_init(t_cube *c, char *title);
int		close_cube(t_cube *c);

int		hex_rgb_to_int(char *hex);

void	fill_minimap(t_cube *c);

// INPUT
int	key_press(int keycode, t_cube *c);
int	key_release(int keycode, t_keys *k);

// PIXEL
int	update_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color);
void	draw_vertical_line(t_img *img, int x, int start, int end, int color);

// RENDER
int	render(t_cube *c);
void	ray(t_cube *c, double ray_dir_x, double ray_dir_y, int x);

#endif
