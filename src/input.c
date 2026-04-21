/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:33:03 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/20 19:00:44 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int keycode, t_cube *c)
{
	printf("PRESS %d %d\n", (int)c->cam.pos_x , (int)c->cam.pos_y);
	if (keycode == ESC)
		close_cube(c);
	if (keycode == 119)
		c->keys.w = 1;
	if (keycode == 115)
		c->keys.s = 1;
	if (keycode == 97)
		c->keys.a = 1;
	if (keycode == 100)
		c->keys.d = 1;
	if (keycode == 65361)
		c->keys.left = 1;
	if (keycode == 65363)
		c->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_keys *k)
{
	printf("RELEASE\n");
	if (keycode == 119)
		k->w = 0;
	if (keycode == 115)
		k->s = 0;
	if (keycode == 97)
		k->a = 0;
	if (keycode == 100)
		k->d = 0;
	if (keycode == 65361)
		k->left = 0;
	if (keycode == 65363)
		k->right = 0;
	return (0);
}
