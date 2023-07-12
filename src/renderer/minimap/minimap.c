/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:18:59 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/30 17:26:44 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/cub3d.h"
#include <math.h>
#include <stdio.h>

void	minimap(t_main *main, int pos_x, int pos_y, float zoom)
{
	int		i;
	int		j;
	float	dist;
	float	pix_x;
	float	pix_y;

	i = 0;
	while (i < (MINIMAP_SIZE * 2))
	{
		j = 0;
		while (j < (MINIMAP_SIZE * 2))
		{
			pix_x = main->player.pos_x - (cos(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0) * (i - MINIMAP_SIZE) - sin(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0) * (j - MINIMAP_SIZE)) / zoom;
			pix_y = main->player.pos_y - (sin(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0) * (i - MINIMAP_SIZE) + cos(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0) * (j - MINIMAP_SIZE)) / zoom;
			dist = sqrt((i - MINIMAP_SIZE) * (i - MINIMAP_SIZE) + (j - MINIMAP_SIZE) * (j - MINIMAP_SIZE));
			if (dist < MINIMAP_SIZE)
				mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0x000000ff);
			if (pix_x > 0 && pix_y > 0 && pix_x < main->map_data.size_x && pix_y < main->map_data.size_y)
			{
				if (dist < MINIMAP_SIZE - 3 && main->map_data.format_map[(int)pix_x][(int)pix_y] == 0)
					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0x9c9b9aff);
				if (dist < MINIMAP_SIZE - 3 && main->map_data.format_map[(int)pix_x][(int)pix_y] != 0)
					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xe0e0e0ff);
				if (i == MINIMAP_SIZE - 3 && j == MINIMAP_SIZE)
					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xff0000ff);
			}
			j++;
		}
		i++;
	}
}
