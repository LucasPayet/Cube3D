/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:52:57 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/17 22:46:53 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_minimap(t_img *mn)
{
	int	x;
	int	y;
	int	color;

	color = 0x00FF0000; // red

	y = 0;
	while (y < 40)
	{
		x = 0;
		while (x < 40)
		{
			int index = y * mn->line_length + x * (mn->bits_per_pixel / 8);
			*(unsigned int *)(mn->addr + index) = color;
			x++;
		}
		y++;
	}
}
