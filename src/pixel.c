/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 22:37:47 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/20 05:52:56 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	update_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= img->x_len || y >= img->y_len)
		return (0);
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
	return (1);
}
