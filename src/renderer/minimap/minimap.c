/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:18:59 by arforgea          #+#    #+#             */
/*   Updated: 2023/07/31 15:49:55 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
typedef struct	s_vector
{
	float	x;
	float	y;
	float	vector;
}				t_vector;

static	t_vector	get_vetor(float x, float y)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.vector = sqrt((x * x) + (y * y));
	return (vector);
}
*/

// void	minimap(t_main *main, int pos_x, int pos_y, float zoom)
// {
// 	int		i;
// 	int		j;
// 	float	dist;
// 	float	pix_x;
// 	float	pix_y;
// 	i = 0;
// 	j = 0;

// 	float a;
// 	float b;
// 	float c;
// 	float d;


// 	i = 0;
// 	while (i < (MINIMAP_SIZE * 2))
// 	{
// 		j = 0;
// 		while (j < (MINIMAP_SIZE * 2))
// 		{
// 			c = i - MINIMAP_SIZE;
// 			d = j - MINIMAP_SIZE;
// 			a = cos(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0);
// 			b = sin(atan2(main->player.dir_y, main->player.dir_x) - PI / 2.0);
// 			pix_x = main->player.pos_x - (a * c - (b * d)) / zoom;
// 			pix_y = main->player.pos_y - (b * c + (a * d)) / zoom;

// 			dist = sqrt(c * c + d * d);
// 			if (dist < MINIMAP_SIZE)
// 				mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0x000000ff);
// 			if (pix_x > 0 && pix_y > 0 && pix_x < main->map.size_x && pix_y < main->map.size_y)
// 			{
// 				if (dist < MINIMAP_SIZE - 3 && main->map.format_map[(int)pix_x][(int)pix_y] == 1)
// 					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0x9c9b9aff);
// 				if (dist < MINIMAP_SIZE - 3 && main->map.format_map[(int)pix_x][(int)pix_y] != 1)
// 					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xe0e0e0ff);
// 				if (i == MINIMAP_SIZE - 3 && j == MINIMAP_SIZE)
// 					mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xff0000ff);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
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
			if (pix_x > 0 && pix_y > 0 && pix_x < main->map.size_x && pix_y < main->map.size_y)
			{
				if ((int)pix_x < main->map.size_x && (int)pix_y < main->map.size_y && (int)pix_x >= 0 && (int)pix_y >= 0)
				{
					if (dist < MINIMAP_SIZE - 3 && main->map.format_map[(int)pix_y][(int)pix_x] == '0')
						mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0x9c9b9aff);
					if (dist < MINIMAP_SIZE - 3 && main->map.format_map[(int)pix_y][(int)pix_x] != '0')
						mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xe0e0e0ff);
					if (i == MINIMAP_SIZE - 3 && j == MINIMAP_SIZE)
						mlx_put_pixel(main->mlx_data.img, i + pos_x - MINIMAP_SIZE, j + pos_y - MINIMAP_SIZE, 0xff0000ff);
				}
			}
			j++;
		}
		i++;
	}
}
