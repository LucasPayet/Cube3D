/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celia <celia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:33:03 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/10 17:17:59 by celia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int keycode, t_cube *c)
{
	if (keycode == ESC || keycode == Q)
		close_cube(c);
	if (keycode == W)
		c->keys.w = 1;
	if (keycode == S)
		c->keys.s = 1;
	if (keycode == A)
		c->keys.a = 1;
	if (keycode == D)
		c->keys.d = 1;
	if (keycode == LEFT)
		c->keys.left = 1;
	if (keycode == RIGHT)
		c->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_keys *k)
{
	if (keycode == W)
		k->w = 0;
	if (keycode == S)
		k->s = 0;
	if (keycode == A)
		k->a = 0;
	if (keycode == D)
		k->d = 0;
	if (keycode == LEFT)
		k->left = 0;
	if (keycode == RIGHT)
		k->right = 0;
	return (0);
}

void	rotate(t_cube *c, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->cam.dir_x;
	old_plane_x = c->cam.plane_x;
	c->cam.dir_x = c->cam.dir_x * cos(rot) - c->cam.dir_y * sin(rot);
	c->cam.dir_y = old_dir_x * sin(rot) + c->cam.dir_y * cos(rot);
	c->cam.plane_x = c->cam.plane_x * cos(rot) - c->cam.plane_y * sin(rot);
	c->cam.plane_y = old_plane_x * sin(rot) + c->cam.plane_y * cos(rot);
}
