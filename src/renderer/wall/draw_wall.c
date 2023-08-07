/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:11:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/04 10:31:54 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_main *main, t_ray *ray_array)
{
	t_wall_line	wall_line;
	int			i;

	i = 0;
	while (i < WIDTH)
	{
		wall_line.ray = &ray_array[i];
		wall_line.texture = get_wall_texture(main, &ray_array[i]);
		wall_line.line_dist = get_ray_min_dist(ray_array[i]);
		wall_line.wall_height = (int)(HEIGHT / wall_line.line_dist);
		wall_line.start = -wall_line.wall_height / 2 + HEIGHT / 2;
		wall_line.end = wall_line.wall_height / 2 + HEIGHT / 2;
		wall_line.start += main->player.view;
		wall_line.end += main->player.view;
		draw_wall_line(main, &wall_line);
		i++;
	}
}
