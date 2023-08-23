/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:08:06 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:37:27 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	crosshair(t_main *main)
{
	int	i;
	int	j;
	int	s;
	int	color;

	i = 0;
	s = main->parameter.crossshair_size;
	color = main->parameter.crossshair_color;
	while (i++ < WIDTH)
	{
		j = 0;
		while (j++ < HEIGHT)
		{
			if (j == (HEIGHT / 2))
			{
				if (i > (WIDTH / 2) - s && i < (WIDTH / 2) + s)
					mlx_put_pixel(main->mlx_data.img, i, j, color);
			}
			if (i == (WIDTH / 2))
			{
				if (j > (HEIGHT / 2) - s && j < (HEIGHT / 2) + s)
					mlx_put_pixel(main->mlx_data.img, i, j, color);
			}
		}
	}
}
