#include "cube.h"


int	ft_exit(void *param)
{
	t_cube	*data;

	data = (t_cube *)param;
	free_game(data);
	exit(EXIT_SUCCESS);
}

void	put_player_img(t_cube *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->player, (*j) * 40, (*i) * 40);
	if (!data->img->player)
	{
		ft_printf("Failed to load player image");
	}
		
}

void	put_wall_img(t_cube *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->wall, (*j) * 40, (*i) * 40);
}

void	put_empty_img(t_cube *data, int *j, int *i)
{
	if (!data->img->empty)
		return ;
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->img->empty, (*j) * 40, (*i) * 40);
}

void	ft_create_map(t_cube *data)
{
	int		x;
	int		y;
	int		floor_color;
	int		ceil_color;

	floor_color = (data->conf.floor[0] << 16)
		| (data->conf.floor[1] << 8)
		| data->conf.floor[2];
	ceil_color = (data->conf.ceil[0] << 16)
		| (data->conf.ceil[1] << 8)
		| data->conf.ceil[2];
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_pixel_put(data->mlx.mlx, data->mlx.win,
					x, y, ceil_color);
			else
				mlx_pixel_put(data->mlx.mlx, data->mlx.win,
					x, y, floor_color);
			x++;
		}
		y++;
	}
}