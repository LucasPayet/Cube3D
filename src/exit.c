#include "cube.h"

void	free_game(t_cube *data)
{
	int	i;

	if (data->conf.tex_no)
		free(data->conf.tex_no);
	if (data->conf.tex_so)
		free(data->conf.tex_so);
	if (data->conf.tex_we)
		free(data->conf.tex_we);
	if (data->conf.tex_ea)
		free(data->conf.tex_ea);
	if (data->map.map)
	{
		i = 0;
		while (data->map.map[i])
			free(data->map.map[i++]);
		free(data->map.map);
	}
	if (data->img)
		free(data->img);
}
//il faut remplacer tout les printf avec cette fonction, pas fait encore!!!!!!
void	error_exit(char *msg, t_cube *data)
{
	ft_printf("Error\n%s\n", msg);
	if (data)
		free_game(data);
	exit(EXIT_FAILURE);
}
