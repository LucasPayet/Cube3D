/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 22:09:48 by lupayet           #+#    #+#             */
/*   Updated: 2026/05/13 16:09:39 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	hex_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'f')
		return (10 + (c - 'a'));
	if ('A' <= c && c <= 'F')
		return (10 + (c - 'A'));
	return (-1);
}

int	hex_rgb_to_int(char *hex)
{
	int	i;
	int	d;
	int	color;

	i = 0;
	if (hex[i] == '0')
		i++;
	if (hex[i] == 'x')
		i++;
	color = 0;
	while (i <= 7)
	{
		d = hex_to_int(hex[i]);
		if (d == -1)
			return (16777215);
		color = (color << 4) | d;
		i++;
	}
	return (color);
}
