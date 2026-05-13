/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:46:55 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/13 18:29:16 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "s_cube.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# ifdef __APPLE__
#  include "../mlx_mac/mlx.h"
# else
#  include "../mlx/mlx.h"
#  include <X11/X.h>
#  include <X11/keysym.h>
# endif

# include "libft.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MMAP 10
# define TILE 20
# define MMAP_W 200
# define MMAP_H 200
# define CENTER 100
# define NUM_RAYS 60

# ifdef __APPLE__
#  define ESC    53
#  define Q      12
#  define W      13
#  define A      0
#  define S      1
#  define D      2
#  define LEFT   123
#  define RIGHT  124
#  define UP     126
#  define DOWN   125
// #  define mlx_destroy_disp(mlx)		(void)(mlx)
# else
#  define ESC    65307
#  define Q      113
#  define W      119
#  define A      97
#  define S      115
#  define D      100
#  define LEFT   65361
#  define RIGHT  65363
#  define UP     65362
#  define DOWN   65364
// #  define mlx_destroy_disp(mlx)		mlx_destroy_display(mlx)
# endif

//check_map_border.c
void	check_borders(t_cube *data);
void	check_spaces(t_cube *data);

//check_map.c
void	ft_check_map(t_cube *data);
char	**dup_map(t_cube *data);

//color.c
int		hex_to_int(char c);
int		hex_rgb_to_int(char *hex);

//draw_line.c
int		ft_abs(int n);
int		slope(int n0, int n1);
void	direction(t_draw *dr, t_pixel *p0);
void	draw_line(t_img *img, t_pixel p0, t_pixel p1, int color);
void	draw_vertical_line(t_img *img, t_vert v);

//draw_square.c
void	draw_square(t_img *img, int start_x, int start_y, int color);

//exit.c
int		close_cube(t_cube *c);
void	free_game(t_cube *data);
void	error_exit(char *msg, t_cube *data);
int		ft_exit(void *param);

//init_cam.c
void	init_cam(t_cube *c);

//init_map.c
void	ft_map_height(t_cube *data);
char	*trim_newline(char *line);

//init.c
void	cube_init(t_cube *c, char *title);

//input.c
int		key_press(int keycode, t_cube *c);
int		key_release(int keycode, t_keys *k);
void	rotate(t_cube *c, double rot);

//main.c
void	ft_map_data(t_cube *data, char *name);
int		main(int ac, char **av);

//minimap_util.c
t_pixel	minimap_pos(t_cube *c, double x, double y);

//minimap.c
void	draw_player_dir(t_cube *c);
void	minimap_loop(t_cube *cube, t_minimap *m);
void	renderd(t_cube *cube);
void	fill_minimap(t_cube *cube);

//parse_rgb.c
void	parse_color(char *line, int j, t_cube *data, int fd);
char	*get_tex_path(char *line);
void	parse_rgb(char *str, int rgb[3], t_cube *data);

//parsing_identifiers.c
void	ft_parse_identifiers(t_cube *data);

//parsing_map.c
void	check_invalid_char(t_cube *data, char c);
void	handle_spawn(t_cube *data, int x, int y, int *spawn_count);
void	ft_validate_map(t_cube *data);
void	init_dirs(int dx[4], int dy[4]);

//pixel.c
int		update_pixel(t_img *img, int x, int y, int color);

//raycast.c 
void	dda_loop(t_cube *c, t_ray *r);
void	draw_fov(t_cube *c, t_ray *r);
void	step_dir(t_cube *c, t_ray *r, double ray_dir_x, double ray_dir_y);
void	render3d(t_cube *c, t_ray *r, int x);
void	ray(t_cube *c, double ray_dir_x, double ray_dir_y, int x);

//read_map.c
void	ft_read_map(t_cube *data);

//render.c
int		render(t_cube *c);

//texture.c
void	draw_tex_line(t_cube *c, t_ray *r, t_draw_tex *d);
void	calc_tex(t_cube *c, t_ray *r, double ray_dir_x, double ray_dir_y);

#endif
