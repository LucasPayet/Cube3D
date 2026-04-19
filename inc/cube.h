/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:46:55 by lupayet           #+#    #+#             */
/*   Updated: 2026/04/19 18:51:03 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "s_cube.h"
#include "libft.h"
#include "mlx.h"

#include <stdlib.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define ESC 65307

void	cube_init(t_cube *c, char *title);
int		close_cube(t_cube *c);

int		hex_rgb_to_int(char *hex);

void	fill_minimap(t_img *mn);

// INPUT
int	key_press(int keycode, t_cube *c);
int	key_release(int keycode, t_keys *k);

#endif
