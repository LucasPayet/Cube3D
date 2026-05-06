/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:46:55 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/06 19:49:36 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "s_cube.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../mlx/mlx.h"
#  include <X11/X.h>
#  include <X11/keysym.h>
# endif

# include "libft.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

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
# endif

//camera.c
// void	update_time(t_cube *data);
// void	camera_dir(t_cube *game);

//check_map_border.c
void	check_borders(t_cube *data);
void	check_spaces(t_cube *data);

//check_map.c
void	ft_check_map(t_cube *data);
char    **dup_map(t_cube *data);

//exit.c
void	free_game(t_cube *data);
void	error_exit(char *msg, t_cube *data);
int		ft_exit(void *param);

//init_game.c
void	ft_create_map(t_cube *data);

//init_map.c
void	ft_map_height(t_cube *data);
char	*trim_newline(char *line);

//main.c
void	ft_map_data(t_cube *data, char *name);
int		main(int ac, char **av);

//moving.c
int		press_key(int keycode, void *game);

//parse_rgb.c
void    parse_color(char *line, int j, t_cube *data, int fd);
char	*get_tex_path(char *line);
void	parse_rgb(char *str, int rgb[3], t_cube *data);

//parsing_identifiers.c
void	ft_parse_identifiers(t_cube *data);

//parsing_map.c
void	check_invalid_char(t_cube *data, char c);
void	handle_spawn(t_cube *data, int x, int y, int *spawn_count);
void	ft_validate_map(t_cube *data);
void	init_dirs(int dx[4], int dy[4]);

//read_map.c
void	ft_read_map(t_cube *data);

#endif
