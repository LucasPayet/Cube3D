/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:46:55 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 20:13:01 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef CUBE_H
// # define CUBE_H

// #include "s_cube.h"
// #include "mlx.h"
// #include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <math.h>

// # define WIN_WIDTH 1280
// # define WIN_HEIGHT 720

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



//moving
int		ft_exit(void *param);
void	move_player(t_cube *data, int new_x, int new_y);

void	move_w(t_cube *data);
void	move_s(t_cube *data);
void	move_a(t_cube *data);
void	move_d(t_cube *data);

int     press_key(int keycode, void *data);

//init_game
void	put_player_img(t_cube *data, int *j, int *i);
void	put_wall_img(t_cube *data, int *j, int *i);
void	put_empty_img(t_cube *data, int *j, int *i);
void	ft_create_map(t_cube *data);

//init_map
void	ft_map_height(t_cube *data);
char	*trim_newline(char *line);
void	ft_read_map(t_cube *data);
void	ft_find_player_position(t_cube *data);

//main
void	ft_parse_map(t_cube *data);
void	ft_map_data(t_cube *data, char *name);
int		main(int ac, char **av);

//parsing
void	ft_check_format(t_cube *game);
void    ft_parse_identifiers(t_cube *data);

void	ft_validate_map(t_cube *data);
void	ft_check_map(t_cube *data);

void	ft_init_player_dir(t_cube *data);

void	free_game(t_cube *data);
void	error_exit(char *msg, t_cube *data);

#endif
