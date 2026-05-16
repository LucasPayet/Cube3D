/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:33:48 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/16 03:15:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_mov(int x, int y, t_cube *c)
{
	int	dx;

	(void)y;
	if (x < c->keys.mouse_x)
	{
		dx = c->keys.mouse_x - x;
		dx = -dx;
	}
	else
		dx = x - c->keys.mouse_x;
	rotate(c, dx * 0.02);
	c->keys.mouse_x = x;
	return (0);
}
