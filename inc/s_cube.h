/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:08 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/06 19:19:13 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUBE_H
# define S_CUBE_H

typedef struct s_mlx{
	void	*win;
	void	*mlx;
}t_mlx;

typedef struct s_img
{
	int		on_exit;
} t_img;

typedef struct s_map
{
        int             width;
        int             height;
		
		int				map_start;
		
		char	spawn_dir;
		char	*fn;
		char	**map;
} t_map;

typedef struct	s_cam
{	
	double	perpWallDist;
	double	frameTime;
	long	time;
	long	oldTime;

	int		side;

	double	deltaDistX;
	double	deltaDistY;

	double sideDistX;
	double sideDistY;
	
	int		playerX;
	int		playerY;
} t_cam;

typedef	struct s_conf{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		floor[3];
	int		ceil[3];
	int		tex_parsed;
}t_conf;

typedef struct	s_cube
{
	t_mlx	mlx;
	t_map	map;
	t_img	*img;
	t_conf	conf;
	t_cam	cam;
} t_cube;


#endif
