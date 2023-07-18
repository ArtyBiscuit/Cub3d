/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:11:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/07/18 10:10:46 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_main *main, t_ray *ray_array)
{
	float	min_dist;
	int		wall_line_start;
	int 	wall_line_end;
	int 	wall_height;
	int i;

	i = 0;
	while (i < WIDTH)
	{
		min_dist = get_ray_min_dist(ray_array[i]);
		wall_height = (int)(HEIGHT / min_dist);
		wall_line_start = -wall_height / 2 + HEIGHT / 2;
		wall_line_end = wall_height / 2 + HEIGHT / 2;
		wall_line_start += main->player.view;
		wall_line_end += main->player.view;
		if (wall_line_start < 0)
			wall_line_start = 0;
		if (wall_line_end >= HEIGHT)
			wall_line_end = HEIGHT - 1;
		get_wall_color(main->map.format_map, &ray_array[i]);
		draw_line(main, wall_line_start, wall_line_end, ray_array[i]);
		i++;
	}
}
