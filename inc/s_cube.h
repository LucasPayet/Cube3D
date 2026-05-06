/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:08 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/06 18:04:24 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUBE_H
# define S_CUBE_H

typedef	int (*t_fn)(void);

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pixel;

typedef struct s_vert
{
	int	x;
	int	y_start;
	int y_end;
	int	color;
}	t_vert;

typedef struct draw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	d;
	int	d2;
}	t_draw;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	double	hit_x;
	double	hit_y;
}	t_ray;

typedef struct s_minimap
{
	int		x;
	int		y;
	int		px;
	int		py;
	int		start_x;
	int		start_y;
	int		mx;
	int		my;
	int		color;
	double	world_x;
	double	world_y;
	double	dx;
	double	dy;
	int		center;
	int		draw_x;
	int		draw_y;
}	t_minimap;

typedef struct s_square
{
	int	v;
	int x;
	int	y;
	int	end_x;
	int	end_y;
}	t_square;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_len;
	int		y_len;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		fd;
	char	*line;
	char	**split;
	char	**map;
}	t_map;

typedef struct s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_cam;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_cube
{
	t_mlx	mlx;
	t_map	map;
	t_cam	cam;
	t_keys	keys;
	t_img	map_img;
	t_img	view_img;
	t_img	textures;
}	t_cube;

typedef	struct s_conf{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		floor[3];
	int		ceil[3];
	int		tex_parsed; //bitmask : 1=NO 2=SO 4=WE 8=EA 16=F 32=C
}t_conf;

#endif
