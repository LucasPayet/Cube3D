/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:41:12 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/01 08:41:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_pixel	minimap_pos(t_cube *c, double x, double y)
{
	t_pixel	p;
	double	dx;
	double	dy;

	dx = x - c->cam.pos_x;
	dy = y - c->cam.pos_y;
	p.x = (CENTER + dx * TILE);
	p.y = (CENTER + dy * TILE);
	return (p);
}
