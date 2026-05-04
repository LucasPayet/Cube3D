/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 05:53:04 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/04 06:11:56 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_square	init_draw_square(t_img *img, int *start_x, int *start_y)
{
	t_square	s;

	s.v = 1;
	s.end_x = *start_x + TILE;
	s.end_y = *start_y + TILE;
	if (s.end_x <= 0 || s.end_y <= 0
		|| *start_x >= img->x_len || *start_y >= img->y_len)
		return (s.v = 0, s);
	if (*start_x < 0)
		*start_x = 0;
	if (*start_y < 0)
		*start_y = 0;
	if (s.end_x > img->x_len)
		s.end_x = img->x_len;
	if (s.end_y > img->y_len)
		s.end_y = img->y_len;
	return (s);
}

void	draw_square(t_img *img, int start_x, int start_y, int color)
{
	t_square	s;

	s = init_draw_square(img, &start_x, &start_y);
	if (!s.v)
		return ;
	s.y = start_y;
	while (s.y < s.end_y)
	{
		s.x = start_x;
		while (s.x < s.end_x)
		{
			if (s.x == start_x || s.x == start_x + TILE || s.y == start_y
				|| s.y == start_y + TILE)
				update_pixel(img, s.x, s.y, 0x424242);
			else
				update_pixel(img, s.x, s.y, color);
			s.x++;
		}
		s.y++;
	}
}
