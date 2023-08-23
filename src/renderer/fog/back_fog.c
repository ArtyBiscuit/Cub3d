/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:45:41 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:45:43 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_back_fog(int hex_color, float dist, int fog_color)
{
	int	red;
	int	green;
	int	blue;

	dist = ((float)-dist / (HEIGHT / 2.0));
	red = (hex_color >> 24) & fog_color;
	green = (hex_color >> 16) & fog_color;
	blue = (hex_color >> 8) & fog_color;
	red = red * (dist);
	green = green * (dist);
	blue = blue * (dist);
	return (rgba_to_hex(red, green, blue, 255));
}
