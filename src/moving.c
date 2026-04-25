#include "cube.h"


void	move_player(t_cube *data, int new_x, int new_y)
{
	char next_tile = data->map.map[new_y][new_x];

	if (next_tile == '1') // mur
		return ;

	// if (next_tile == 'C') // collectible
	// {
	// 	data->count--;
	// }
	else if (next_tile == 'E')
	{
		// if (data->count == 0)
		// {
		// 	data->escape = 1;
			data->img->on_exit = 1;
	}
		else
			return; // empêche d'aller sur la sortie si collectibles restants
	// else
	data->img->on_exit = 0;

	data->map.map[data->cam.playerY][data->cam.playerX] = data->img->on_exit ? 'E' : '0';// ancienne position
	data->map.map[new_y][new_x] = 'P';          // nouvelle position
	data->cam.playerX = new_x;
	data->cam.playerY = new_y;
	// data->step++;

	// ft_printf("Steps: %d\n", data->step);
}

void	move_w(t_cube *data)
{
	move_player(data, data->cam.playerX, data->cam.playerY - 1);
}

void	move_s(t_cube *data)
{
	move_player(data, data->cam.playerX, data->cam.playerY + 1);
}

void	move_a(t_cube *data)
{
	move_player(data, data->cam.playerX - 1, data->cam.playerY);
}

void	move_d(t_cube *data)
{
	move_player(data, data->cam.playerX + 1, data->cam.playerY);
}


int	press_key(int keycode, void *game)
{
	t_cube *data;

	data = (t_cube *) game;
	ft_printf("Touche pressée : %d\n", keycode);
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == Q)
		ft_exit(data);
	else if (keycode == W)
		move_w(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == D)
		move_d(data);

	mlx_clear_window(data->mlx.mlx, data->mlx.win); 
	// ft_create_map(data);                    

	// if (data->count == 0 && data->on_exit == 1)
	// 	ft_game_result(data);

	return (0);
}

void    update_time(t_cube *data)
{
    data->cam.oldTime   = data->cam.time;
    //data->time      = get_ticks(); // ton équivalent de getTicks()
    data->cam.frameTime = (data->cam.time - data->cam.oldTime) / 1000.0;
    ft_printf("FPS: %f\n", 1.0 / data->cam.frameTime);
}

void	camera_dir(t_cube *game)
{
	if (game->cam.side == 0)
		game->cam.perpWallDist = (game->cam.sideDistX - game->cam.deltaDistX);
	else
		game->cam.perpWallDist = (game->cam.sideDistY - game->cam.deltaDistX);
}