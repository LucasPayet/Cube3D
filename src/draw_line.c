/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 07:10:10 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/04 03:22:51 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	slope(int n0, int n1)
{
	if (n0 < n1)
		return (1);
	return (-1);
}

void	direction(t_draw *dr, t_pixel *p0)
{
	if (dr->d2 > -dr->dy)
	{
		dr->d -= dr->dy;
		p0->x += dr->sx;
	}
	if (dr->d2 < dr->dx)
	{
		dr->d += dr->dx;
		p0->y += dr->sy;
	}
}

void	draw_line(t_img *img, t_pixel p0, t_pixel p1, int color)
{
	t_draw	dr;

	dr.dx = ft_abs(p1.x - p0.x);
	dr.dy = ft_abs(p1.y - p0.y);
	dr.sx = slope(p0.x, p1.x);
	dr.sy = slope(p0.y, p1.y);
	dr.d = dr.dx - dr.dy;
	while (1)
	{
		if (!(p0.y >= WIN_HEIGHT || p0.x >= WIN_WIDTH || p0.y < 0 || p0.x < 0))
			update_pixel(img, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		dr.d2 = 2 * dr.d;
		direction(&dr, &p0);
	}
}

void	draw_vertical_line(t_img *img, t_vec4 v)
{
	int	y;

	y = v.b;
	while (y <= v.c)
	{
		update_pixel(img, v.a, y, v.d);
		y++;
	}
}
