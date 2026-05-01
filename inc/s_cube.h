/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:08 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/28 07:32:16 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUBE_H
# define S_CUBE_H

typedef struct	s_mlx
{
	void    *mlx;
	void    *win;
}	t_mlx;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pixel;

typedef struct	s_ray
{
	int		map_x;
	int		map_y;
	double	frac_x;
	double	frac_y;
}	t_ray;

typedef struct s_img
{
        void    *img;
        char    *addr;
        int             bits_per_pixel;
        int             line_length;
        int             endian;
        int             x_len;
        int             y_len;
}       t_img;

typedef struct s_map
{
        int             width;
        int             height;
        int             fd;
        char    *line;
        char    **split;
		char	**map;
}       t_map;

typedef struct	s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_cam;

typedef struct s_keys
{
	int w;
	int a;
	int s;
	int d;
	int left;
	int right;
}	t_keys;

typedef struct	s_cube
{
	t_mlx	mlx;
	t_map	map;
	t_cam	cam;
	t_keys	keys;
	t_img	map_img;
	t_img	view_img;
} t_cube;

#endif
