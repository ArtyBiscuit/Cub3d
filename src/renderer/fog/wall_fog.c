/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:46:55 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:47:04 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_wall_fog(int hex_color, float dist, int fog_color)
{
	int	red;
	int	green;
	int	blue;

	red = (hex_color >> 24) & fog_color;
	green = (hex_color >> 16) & fog_color;
	blue = (hex_color >> 8) & fog_color;
	if (dist > 1)
		dist = 1;
	if (dist < 0.1)
		dist = 0.1;
	red = red * (1 - dist);
	green = green * (1 - dist);
	blue = blue * (1 - dist);
	return (rgba_to_hex(red, green, blue, 255));
}
