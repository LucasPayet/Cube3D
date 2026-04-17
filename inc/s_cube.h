/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:08 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/17 15:59:58 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUBE_H
# define S_CUBE_H

typedef struct	s_mlx
{
	void    *mlx;
	void    *win;
}	t_mlx;

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
}	t_cam;

typedef struct	s_cube
{
	t_mlx	mlx;
	t_map	map;
	t_img	img[2];
} t_cube;

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
